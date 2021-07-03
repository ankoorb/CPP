#include <dirent.h>
#include <unistd.h>
#include <string>
#include <vector>
#include <iomanip>

#include "linux_parser.h"

using std::stof;
using std::string;
using std::to_string;
using std::vector;


// DONE: An example of how to read data from the filesystem
string LinuxParser::OperatingSystem() {
  string line;
  string key;
  string value;
  std::ifstream filestream(kOSPath);
  if (filestream.is_open()) {
    while (std::getline(filestream, line)) {
      std::replace(line.begin(), line.end(), ' ', '_');
      std::replace(line.begin(), line.end(), '=', ' ');
      std::replace(line.begin(), line.end(), '"', ' ');
      std::istringstream linestream(line);
      while (linestream >> key >> value) {
        if (key == "PRETTY_NAME") {
          std::replace(value.begin(), value.end(), '_', ' ');
          return value;
        }
      }
    }
  }
  return value;
}

// DONE: An example of how to read data from the filesystem
string LinuxParser::Kernel() {
  string os, version, kernel;
  string line;
  std::ifstream stream(kProcDirectory + kVersionFilename);
  if (stream.is_open()) {
    std::getline(stream, line);
    std::istringstream linestream(line);
    linestream >> os >> version >> kernel;
  }
  return kernel;
}

// BONUS: Update this to use std::filesystem
vector<int> LinuxParser::Pids() {
  vector<int> pids;
  DIR* directory = opendir(kProcDirectory.c_str());
  struct dirent* file;
  while ((file = readdir(directory)) != nullptr) {
    // Is this a directory?
    if (file->d_type == DT_DIR) {
      // Is every character of the name a digit?
      string filename(file->d_name);
      if (std::all_of(filename.begin(), filename.end(), isdigit)) {
        int pid = stoi(filename);
        pids.push_back(pid);
      }
    }
  }
  closedir(directory);
  return pids;
}

// TODO: Read and return the system memory utilization
float LinuxParser::MemoryUtilization() {

  // Ref: https://stackoverflow.com/questions/41224738/how-to-calculate-system-memory-usage-from-proc-meminfo-like-htop/41251290%2341251290

  string line;
  string mem_total_key = "MemTotal";
  string mem_free_key = "MemFree";
  float mem_total;
  float mem_free;
  string key;
  string value;

  std::ifstream stream(kProcDirectory + kMeminfoFilename);
  if (stream.is_open()) {
    while (std::getline(stream, line)) {
      std::replace(line.begin(), line.end(), ':', ' ');
      std::istringstream linestream(line);
      while (linestream >> key >> value) {
        if (key == mem_total_key) {
          mem_total = stof(value);
        } else if (key == mem_free_key) {
          mem_free = stof(value);
        }
      }
    }
  }
  return (mem_total - mem_free) / mem_total;
}

// TODO: Read and return the system uptime
long LinuxParser::UpTime() {
  string line, time;
  long uptime;
  std::ifstream stream(kProcDirectory + kUptimeFilename);
  if (stream.is_open()) {
    std::getline(stream, line);
    std::istringstream linestream(line);
    linestream >> time;
    uptime = std::stol(time);
    return uptime;
  }
  return 0;
}

// TODO: CPU

// TODO: Read and return the number of jiffies for the system
long LinuxParser::Jiffies() {
  return ActiveJiffies() - IdleJiffies();
}

// TODO: Read and return the number of active jiffies for a PID
// REMOVE: [[maybe_unused]] once you define the function
long LinuxParser::ActiveJiffies(int pid) {
  string line;
  string value;
  std::vector<string> values;
  std::ifstream stream(kProcDirectory + to_string(pid) + kStatFilename);
  if (stream.is_open()) {
    std::getline(stream, line);
    std::istringstream linestream(line);
    while (linestream >> value){
      values.emplace_back(value);
    }
  }

  if (values.size() >= 21){
    return std::stol(values[13]) + std::stol(values[14]) + std::stol(values[15]) + std::stol(values[16]);
  }

  return 0;
}

// TODO: Read and return the number of active jiffies for the system
long LinuxParser::ActiveJiffies() {

  auto cpu_stats = LinuxParser::CpuUtilization();
  auto user = stol(cpu_stats[LinuxParser::kUser_]);
  auto nice = stol(cpu_stats[LinuxParser::kNice_]);
  auto system = stol(cpu_stats[LinuxParser::kSystem_]);
  auto idle = stol(cpu_stats[LinuxParser::kIdle_]);
  auto iowait = stol(cpu_stats[LinuxParser::kIOwait_]);
  auto irq = stol(cpu_stats[LinuxParser::kIRQ_]);
  auto softirq = stol(cpu_stats[LinuxParser::kSoftIRQ_]);
  auto steal = stol(cpu_stats[LinuxParser::kSteal_]);

  return (user + nice + system + idle + iowait + irq + softirq + steal);;
}

// TODO: Read and return the number of idle jiffies for the system
long LinuxParser::IdleJiffies() {
  auto cpu_stats = LinuxParser::CpuUtilization();
  auto idle = stol(cpu_stats[LinuxParser::kIdle_]);
  auto iowait = stol(cpu_stats[LinuxParser::kIOwait_]);

  return (idle + iowait);
}

// TODO: Read and return CPU utilization
vector<string> LinuxParser::CpuUtilization() {
  string line;
  string value;
  vector<string> output;
  std::ifstream stream(kProcDirectory + kStatFilename);
  if (stream.is_open()) {
    std::getline(stream, line);
    std::istringstream linestream(line);
    linestream >> value;

    for (auto i = 0; i < CPUStates::kGuestNice_; i++){
      linestream >> value;
      output.emplace_back(value);
    }

  }

  return output;
}


// TODO: PROCESS

// TODO: Read and return the total number of processes
int LinuxParser::TotalProcesses() {
  string line;
  string processes_key = "processes";
  string key;
  string value;
  std::ifstream stream(kProcDirectory + kStatFilename);
  if (stream.is_open()) {
    while (std::getline(stream, line)) {
      std::istringstream linestream(line);
      while (linestream >> key >> value) {
        if (key == processes_key) {
          return std::stoi(value);
        }
      }
    }
  }

  return 0;
}

// TODO: Read and return the number of running processes
int LinuxParser::RunningProcesses() {

  string line;
  string running_key = "procs_running";
  string key;
  string value;
  std::ifstream stream(kProcDirectory + kStatFilename);
  if (stream.is_open()) {
    while (std::getline(stream, line)) {
      std::istringstream linestream(line);
      while (linestream >> key >> value) {
        if (key == running_key) {
          return std::stoi(value);
        }
      }
    }
  }

  return 0;
}

// TODO: Read and return the command associated with a process
// REMOVE: [[maybe_unused]] once you define the function
string LinuxParser::Command(int pid) {
  string line;
  std::ifstream stream(kProcDirectory + to_string(pid) + kCmdlineFilename);
  if (stream.is_open()){
    std::getline(stream, line);
  }
  return line;
}

// TODO: Read and return the memory used by a process
// REMOVE: [[maybe_unused]] once you define the function
string LinuxParser::Ram(int pid) {
  string line;
  string ram_key = "VmRSS";
  string key;
  string value;
  long vm_size;
  std::ifstream stream(kProcDirectory + to_string(pid) + kStatusFilename);
  while (std::getline(stream, line)){
    std::replace(line.begin(), line.end(), ':', ' ');
    std::istringstream linestream(line);
    while (linestream >> key >> value){
      if (key == ram_key){
        vm_size = stol(value);
        break;
      }
    }
  }
  // See: https://stackoverflow.com/questions/29200635/convert-float-to-string-with-precision-number-of-decimal-digits-specified
  float vm_size_mb = vm_size / 1000.0f;
  std::stringstream vm_stream;
  vm_stream << std::fixed << std::setprecision(2) << vm_size_mb;
  return vm_stream.str();
}

// TODO: Read and return the user ID associated with a process
// REMOVE: [[maybe_unused]] once you define the function
string LinuxParser::Uid(int pid) {
  string line;
  string uid_key = "Uid";
  string key;
  string value;

  std::ifstream stream(kProcDirectory + to_string(pid) + kStatusFilename);
  if (stream.is_open()) {
    while (std::getline(stream, line)) {
      std::replace(line.begin(), line.end(), ':', ' ');
      std::istringstream linestream(line);
      while (linestream >> key >> value) {
        if (key == uid_key) {
          return value;
        }
      }
    }
  }

  return value;
}

// TODO: Read and return the user associated with a process
// REMOVE: [[maybe_unused]] once you define the function
string LinuxParser::User(int pid) {
  string line;
  string uid = LinuxParser::Uid(pid);
  string key;
  string value;
  string password;

  std::ifstream stream(kPasswordPath);
  if (stream.is_open()) {
    while (std::getline(stream, line)) {
      std::replace(line.begin(), line.end(), ':', ' ');
      std::istringstream linestream(line);
      while (linestream >> key >> password >> value) {
        if (uid == value) {
          return key;
        }
      }
    }
  }

  return key;
}

// TODO: Read and return the uptime of a process
// REMOVE: [[maybe_unused]] once you define the function
long LinuxParser::UpTime(int pid) {
  string line;
  string value;
  vector<string> values;
  std::ifstream stream(kProcDirectory + to_string(pid) + kStatusFilename);
  if (stream.is_open()) {
    while (std::getline(stream, line)) {
      std::istringstream linestream(line);
      while (linestream >> value){
        values.emplace_back(value);
      }
    }
  }

  long pid_uptime = LinuxParser::UpTime() - std::stol(values[21]) / sysconf(_SC_CLK_TCK);

  return pid_uptime;
}

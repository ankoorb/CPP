#ifndef SYSTEM_PARSER_H
#define SYSTEM_PARSER_H

#include <fstream>
#include <regex>
#include <string>

namespace LinuxParser {
// Paths
const std::string kProcDirectory{"/proc/"};
const std::string kCmdlineFilename{"/cmdline"};
const std::string kCpuinfoFilename{"/cpuinfo"};
const std::string kStatusFilename{"/status"};
const std::string kStatFilename{"/stat"};
const std::string kUptimeFilename{"/uptime"};
const std::string kMeminfoFilename{"/meminfo"};
const std::string kVersionFilename{"/version"};
const std::string kOSPath{"/etc/os-release"};
const std::string kPasswordPath{"/etc/passwd"};

// System
float MemoryUtilization(); // TODO: Done
long UpTime(); // TODO: Done
std::vector<int> Pids(); // TODO: Done
int TotalProcesses(); // TODO: Done
int RunningProcesses(); // TODO: Done
std::string OperatingSystem(); // TODO: Done
std::string Kernel(); // TODO: Done

// CPU
enum CPUStates {
  kUser_ = 0,
  kNice_,
  kSystem_,
  kIdle_,
  kIOwait_,
  kIRQ_,
  kSoftIRQ_,
  kSteal_,
  kGuest_,
  kGuestNice_
};

std::vector<std::string> CpuUtilization(); // TODO: Done
long Jiffies(); // TODO: Done
long ActiveJiffies(); // TODO: Done
long ActiveJiffies(int pid); // TODO: Done
long IdleJiffies(); // TODO: Done

// Processes
std::string Command(int pid); // TODO: Done
std::string Ram(int pid); // TODO: Done
std::string Uid(int pid); // TODO: Done
std::string User(int pid); // TODO: Done
long int UpTime(int pid); // TODO: Done
};  // namespace LinuxParser

#endif
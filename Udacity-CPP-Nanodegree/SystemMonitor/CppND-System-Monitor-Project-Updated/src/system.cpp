#include <unistd.h>
#include <cstddef>
#include <set>
#include <string>
#include <vector>

#include "process.h"
#include "processor.h"
#include "system.h"
#include "linux_parser.h"

using std::set;
using std::size_t;
using std::string;
using std::vector;

System::System() {

    cpu_ = Processor();

    vector<int> pids = LinuxParser::Pids();
    for (auto pid: pids){
        processes_.emplace_back(Process(pid));
    }

    kernel_ = LinuxParser::Kernel();
    memory_utilization_ = LinuxParser::MemoryUtilization();
    operating_system_ = LinuxParser::OperatingSystem();
    running_processes_ = LinuxParser::RunningProcesses();
    total_processes_ = LinuxParser::TotalProcesses();
    uptime_ = LinuxParser::UpTime();

}

// TODO: Return the system's CPU
Processor& System::Cpu() { return cpu_; }

// TODO: Return a container composed of the system's processes
vector<Process>& System::Processes() {
    std::sort(processes_.begin(), processes_.end());
    return processes_;
}

// TODO: Return the system's kernel identifier (string)
std::string System::Kernel() { return kernel_; }

// TODO: Return the system's memory utilization
float System::MemoryUtilization() { return memory_utilization_; }

// TODO: Return the operating system name
std::string System::OperatingSystem() { return operating_system_; }

// TODO: Return the number of processes actively running on the system
int System::RunningProcesses() { return running_processes_; }

// TODO: Return the total number of processes on the system
int System::TotalProcesses() { return total_processes_; }

// TODO: Return the number of seconds since the system started running
long int System::UpTime() { return uptime_; }
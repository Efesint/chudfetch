#include <iostream>
#include <stdlib.h>
#include <string>

int main()
{
std::string host, os, hardware, kernel, hostname, cpu, ram, ip, disk, uptime, load, proc, gpu, sh, term, date, arch, mac;
char arr[128];
FILE* pipe;

pipe = popen("echo $(whoami)@$(hostname)", "r");
fgets(arr, 128, pipe);
host = arr;
host.pop_back();
pclose(pipe);

pipe = popen("echo \"os: $(lsb_release -sd 2>/dev/null | sed 's/\"//g')\"", "r");
fgets(arr, 128, pipe);
os = arr;
os.pop_back();
pclose(pipe);

pipe = popen("hostnamectl 2>/dev/null | grep -i 'hardware model' | sed 's/^[[:space:]]*//'", "r");
if (fgets(arr, 128, pipe)) 
{
    hardware = arr;
    hardware.pop_back();
}
pclose(pipe);
    
pipe = popen("echo \"kernel version: $(uname -r)\"", "r");
fgets(arr,128,pipe);
kernel = arr;
kernel.pop_back();
pclose(pipe);

pipe = popen("echo \"hostname: $(hostname)\"", "r");
fgets(arr,128,pipe);
hostname = arr;
hostname.pop_back();
pclose(pipe);

pipe = popen("echo \"cpu: $(lscpu | grep 'Model name' | cut -d':' -f2- | xargs)\"", "r");
fgets(arr,128,pipe);
cpu = arr;
cpu.pop_back();
pclose(pipe);

pipe = popen("echo \"ram: $(free -h | awk '/Mem:/ {print $3 \" / \" $2}')\"", "r");
fgets(arr, 128, pipe);
ram = arr;
ram.pop_back();
pclose(pipe);

pipe = popen("echo \"ip: $(ip -4 addr show | grep -oP '(?<=inet\\s)\\d+(\\.\\d+){3}' | grep -v 127.0.0.1 | head -1)\"", "r");
fgets(arr, 128, pipe);
ip = arr;
ip.pop_back();
pclose(pipe);

pipe = popen("echo \"disk: $(df -h / | awk 'NR==2 {print $3 \"/\" $2 \" (\" $5 \")\"}')\"", "r");
fgets(arr, 128, pipe);
disk = arr;
disk.pop_back();
pclose(pipe);

pipe = popen("echo \"uptime: $(uptime -p | sed 's/up //')\"", "r");
fgets(arr, 128, pipe);
uptime = arr;
uptime.pop_back();
pclose(pipe);

pipe = popen("echo \"load: $(uptime | awk -F'load average:' '{print $2}' | xargs)\"", "r");
fgets(arr, 128, pipe);
load = arr;
load.pop_back();
pclose(pipe);

pipe = popen("echo \"processes: $(ps aux | wc -l | xargs)\"", "r");
fgets(arr, 128, pipe);
proc = arr;
proc.pop_back();
pclose(pipe);

pipe = popen("echo \"gpu: $(lspci | grep -i 'vga\\|3d\\|display' | sed 's/.*: //')\"", "r");
fgets(arr, 128, pipe);
gpu = arr;
gpu.pop_back();
pclose(pipe);

pipe = popen("echo \"shell: $(basename $SHELL)\"", "r");
fgets(arr, 128, pipe);
sh = arr;
sh.pop_back();
pclose(pipe);

pipe = popen("echo \"term: $(basename $TERM 2>/dev/null)\"", "r");
fgets(arr, 128, pipe);
term = arr;
term.pop_back();
pclose(pipe);

pipe = popen("echo \"date: $(date '+%Y-%m-%d %H:%M:%S')\"", "r");
fgets(arr, 128, pipe);
date = arr;
date.pop_back();
pclose(pipe);

pipe = popen("echo \"arch: $(uname -m)\"", "r");
fgets(arr, 128, pipe);
arch = arr;
arch.pop_back();
pclose(pipe);

pipe = popen("echo \"mac: $(ip link | grep ether | awk '{print $2}' | head -1)\"", "r");
fgets(arr, 128, pipe);
mac = arr;
mac.pop_back();
pclose(pipe);

std::cout << "\033[92m";

std::cout << "⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠿⠿⠿⠿⠿⠿⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿   ";
std::cout << host << std::endl;

std::cout << "⣿⣿⣿⣿⣿⣿⣿⣿⣿⠿⠛⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠙⠻⠿⣿⣿⣿⣿   ";
std::cout << "- - - - -" << std::endl;

std::cout << "⣿⣿⣿⣿⣿⣿⣿⣿⠋⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣀⣀⡀⠀⢀⠀⠙⣿⣿   os: ";
std::cout << "\033[37m" << os.substr(4) << "\033[92m" << std::endl;

std::cout << "⣿⣿⣿⣿⣿⣿⣿⡇⠀⠀⠀⠀⠀⣠⣴⣶⣶⣶⣶⣿⣿⣿⣿⣿⣿⣿⣷⡌⣿⣿   Hardware Model: ";
std::cout << "\033[37m" << hardware.substr(16) << "\033[92m" << std::endl;

std::cout << "⣿⣿⣿⣿⣿⣿⣿⡇⠀⠀⠀⠀⣴⣿⣿⣿⣿⣿⣿⣻⣿⣿⣿⡿⣿⣿⣿⣿⡜⣿   kernel version: ";
std::cout << "\033[37m" << kernel.substr(16) << "\033[92m" << std::endl;

std::cout << "⣿⣿⣿⣿⣿⣿⣿⡇⠀⠀⠀⢀⣿⣿⣿⣿⣿⣿⣿⣷⢿⣿⣿⣇⣿⣿⣿⣿⣧⣿   hostname: ";
std::cout << "\033[37m" << hostname.substr(10) << "\033[92m" << std::endl;

std::cout << "⣿⣿⣿⣿⣿⣿⣿⡇⡆⠀⠀⣸⣿⣯⡉⠙⠛⠿⣿⣿⢺⣿⣿⡇⢿⡿⠿⠛⠉⣿   cpu: ";
std::cout << "\033[37m" << cpu.substr(5) << "\033[92m" << std::endl;

std::cout << "⣿⣿⣿⣿⣿⣿⣿⢁⡟⣀⣘⣛⣛⡛⢩⣤⣤⣤⣤⣀⠻⠿⠿⡇⢊⣀⣐⣚⡃⢻   ram: ";
std::cout << "\033[37m" << ram.substr(5) << "\033[92m" << std::endl;

std::cout << "⣿⣿⣿⣿⣿⣿⣿⠸⣧⣽⣿⣿⣿⡇⢼⠰⠀⠈⠙⣻⠆⣾⣷⡆⢘⡋⠉⣽⡇⢸   ip: ";
std::cout << "\033[37m" << ip.substr(4) << "\033[92m" << std::endl;

std::cout << "⣿⣿⣿⣿⣿⣿⣿⡅⣿⣿⣿⣿⣿⣧⣬⣉⣂⣚⣛⢋⣠⣿⣿⣿⢀⡐⢀⢛⡃⣸   uptime: ";
std::cout << "\033[37m" << uptime.substr(8) << "\033[92m" << std::endl;

std::cout << "⣿⣿⣿⣿⣿⣿⣿⣧⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⢸⣿⣿⣿⣿⡘⣿⣿⣿⡇⣿   disk: ";
std::cout << "\033[37m" << disk.substr(6) << "\033[92m" << std::endl;

std::cout << "⣿⣿⣿⣿⣿⣿⣿⣿⢸⣿⣿⣿⣿⣿⣿⣿⣿⣿⡏⠩⡿⠛⢿⠿⢃⣿⣿⡿⢣⣿   load: ";
std::cout << "\033[37m" << load.substr(6) << "\033[92m" << std::endl;

std::cout << "⣿⣿⣿⣿⣿⣿⣿⣿⢸⣿⣿⡿⣿⣿⣿⣿⣿⡿⣸⡷⠾⠿⣿⢶⡇⣿⡿⣡⣿⣿   processes: ";
std::cout << "\033[37m" << proc.substr(11) << "\033[92m" << std::endl;

std::cout << "⣿⣿⣿⣿⣿⣿⣿⡿⢸⣿⣿⡇⣿⣿⣿⣿⣿⢣⣁⠬⣽⣿⣒⠓⣁⠿⣡⣿⣿⣿   gpu: ";
std::cout << "\033[37m" << gpu.substr(5) << "\033[92m" << std::endl;

std::cout << "⣿⣿⣿⣿⣿⣿⣿⠇⣿⣿⣿⣵⣿⣿⣿⣿⣿⣿⣿⣷⢖⣉⢱⣾⡟⣴⣿⣿⣿⣿   shell: ";
std::cout << "\033[37m" << sh.substr(7) << "\033[92m" << std::endl;

std::cout << "⣿⣿⣿⣿⣿⣿⢏⣾⣿⣿⢟⣻⣿⣿⣿⣿⣿⣿⣿⣿⣿⠟⣋⣭⣾⣿⣿⣿⣿⣿   term: ";
std::cout << "\033[37m" << term.substr(6) << "\033[92m" << std::endl;

std::cout << "⣿⣿⡿⢟⣛⣁⣾⣿⣟⣣⣿⣿⣿⣿⣿⣿⣿⣿⣯⣯⣥⣿⣬⣝⣛⣛⣛⣛⡻⠿   date: ";
std::cout << "\033[37m" << date.substr(6) << "\033[92m" << std::endl;

std::cout << "⣶⣶⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣭⣝⠻⠟⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿   arch: ";
std::cout << "\033[37m" << arch.substr(6) << "\033[92m" << std::endl;

std::cout << "                                 mac: ";
std::cout << "\033[37m" << mac.substr(5) << "\033[92m" << std::endl;

std::cout << "\033[0m";

return 0;
}

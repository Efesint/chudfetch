#include <iostream>
#include <stdlib.h>
#include <string>

int main()
{
std::string host, os, hardware, kernel, hostname, cpu, ram, ip, disk, uptime, load, proc, gpu, sh, term, date, arch, de, wm, mac, bios;
char arr[128];
FILE* pipe;
// hostname
pipe = popen("echo $(whoami)@$(hostname)", "r");
fgets(arr, 128, pipe);
host = arr;
host.pop_back();
pclose(pipe);

//os
pipe = popen("echo \"os: $(lsb_release -sd 2>/dev/null | sed 's/\"//g')\"", "r");
fgets(arr, 128, pipe);
os = arr;
os.pop_back();
pclose(pipe);

//hardware
pipe = popen("hostnamectl 2>/dev/null | grep -i 'hardware model' | sed 's/^[[:space:]]*//'", "r");
    if (fgets(arr, 128, pipe)) 
    {
        hardware = arr;
        hardware.pop_back();
    }
    pclose(pipe);
    
//kernel
pipe = popen("echo \"kernel version: $(uname -r)\"", "r");
fgets(arr,128,pipe);
kernel = arr;
kernel.pop_back();
pclose(pipe);

//hostname 
pipe = popen("echo \"hostname: $(hostname)\"", "r");
fgets(arr,128,pipe);
hostname = arr;
hostname.pop_back();
pclose(pipe);

//cpu
pipe = popen("echo \"cpu: $(lscpu | grep 'Model name' | cut -d':' -f2- | xargs)\"", "r");
fgets(arr,128,pipe);
cpu = arr;
cpu.pop_back();
pclose(pipe);

//ram 
pipe = popen("echo \"ram: $(free -h | awk '/Mem:/ {print $3 \" / \" $2}')\"", "r");
fgets(arr, 128, pipe);
ram = arr;
ram.pop_back();
pclose(pipe);

//ip
pipe = popen("echo \"ip: $(ip -4 addr show | grep -oP '(?<=inet\\s)\\d+(\\.\\d+){3}' | grep -v 127.0.0.1 | head -1)\"", "r");
fgets(arr, 128, pipe);
ip = arr;
ip.pop_back();
pclose(pipe);

// disk usage
pipe = popen("echo \"disk: $(df -h / | awk 'NR==2 {print $3 \"/\" $2 \" (\" $5 \")\"}')\"", "r");
fgets(arr, 128, pipe);
disk = arr;
disk.pop_back();
pclose(pipe);

//uptime
pipe = popen("echo \"uptime: $(uptime -p | sed 's/up //')\"", "r");
fgets(arr, 128, pipe);
uptime = arr;
uptime.pop_back();
pclose(pipe);

// load average
pipe = popen("echo \"load: $(uptime | awk -F'load average:' '{print $2}' | xargs)\"", "r");
fgets(arr, 128, pipe);
load = arr;
load.pop_back();
pclose(pipe);

//proc, gpu, sh, term;

//proc
pipe = popen("echo \"processes: $(ps aux | wc -l | xargs)\"", "r");
fgets(arr, 128, pipe);
proc = arr;
proc.pop_back();
pclose(pipe);

//gpu
pipe = popen("echo \"gpu: $(lspci | grep -i 'vga\\|3d\\|display' | sed 's/.*: //')\"", "r");
fgets(arr, 128, pipe);
gpu = arr;
gpu.pop_back();
pclose(pipe);

//sh
pipe = popen("echo \"shell: $(basename $SHELL)\"", "r");
fgets(arr, 128, pipe);
sh = arr;
sh.pop_back();
pclose(pipe);

//term
pipe = popen("echo \"term: $(basename $TERM 2>/dev/null)\"", "r");
fgets(arr, 128, pipe);
term = arr;
term.pop_back();
pclose(pipe);

//date, arch, de, wm, mac, bios;
// date
pipe = popen("echo \"date: $(date '+%Y-%m-%d %H:%M:%S')\"", "r");
fgets(arr, 128, pipe);
date = arr;
date.pop_back();
pclose(pipe);

// arch
pipe = popen("echo \"arch: $(uname -m)\"", "r");
fgets(arr, 128, pipe);
arch = arr;
arch.pop_back();
pclose(pipe);

// de
pipe = popen("echo \"de: ${XDG_CURRENT_DESKTOP:-${DESKTOP_SESSION:-none}}\"", "r");
fgets(arr, 128, pipe);
de = arr;
de.pop_back();
pclose(pipe);

// wm
pipe = popen("echo \"wm: $(wmctrl -m 2>/dev/null | grep 'Name:' | awk '{print $2}' || echo 'unknown')\"", "r");
fgets(arr, 128, pipe);
wm = arr;
wm.pop_back();
pclose(pipe);

// mac
pipe = popen("echo \"mac: $(ip link | grep ether | awk '{print $2}' | head -1)\"", "r");
fgets(arr, 128, pipe);
mac = arr;
mac.pop_back();
pclose(pipe);

// bios
pipe = popen("echo \"bios: $(dmidecode -s bios-version 2>/dev/null || echo 'N/A')\"", "r");
fgets(arr, 128, pipe);
bios = arr;
bios.pop_back();
pclose(pipe);

std::cout << "\033[92m";
std::cout << "⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠿⠿⠿⠿⠿⠿⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿   " << host << std::endl;
std::cout << "⣿⣿⣿⣿⣿⣿⣿⣿⣿⠿⠛⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠙⠻⠿⣿⣿⣿⣿   " << "- - - - -" << std::endl;
std::cout << "⣿⣿⣿⣿⣿⣿⣿⣿⠋⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣀⣀⡀⠀⢀⠀⠙⣿⣿   " << os << std::endl;
std::cout << "⣿⣿⣿⣿⣿⣿⣿⡇⠀⠀⠀⠀⠀⣠⣴⣶⣶⣶⣶⣿⣿⣿⣿⣿⣿⣿⣷⡌⣿⣿   " << hardware << std::endl;
std::cout << "⣿⣿⣿⣿⣿⣿⣿⡇⠀⠀⠀⠀⣴⣿⣿⣿⣿⣿⣿⣻⣿⣿⣿⡿⣿⣿⣿⣿⡜⣿   " << kernel << std::endl;
std::cout << "⣿⣿⣿⣿⣿⣿⣿⡇⠀⠀⠀⢀⣿⣿⣿⣿⣿⣿⣿⣷⢿⣿⣿⣇⣿⣿⣿⣿⣧⣿   " << hostname << std::endl;
std::cout << "⣿⣿⣿⣿⣿⣿⣿⡇⡆⠀⠀⣸⣿⣯⡉⠙⠛⠿⣿⣿⢺⣿⣿⡇⢿⡿⠿⠛⠉⣿   " << cpu << std::endl;
std::cout << "⣿⣿⣿⣿⣿⣿⣿⢁⡟⣀⣘⣛⣛⡛⢩⣤⣤⣤⣤⣀⠻⠿⠿⡇⢊⣀⣐⣚⡃⢻   " << ram << std::endl;
std::cout << "⣿⣿⣿⣿⣿⣿⣿⠸⣧⣽⣿⣿⣿⡇⢼⠰⠀⠈⠙⣻⠆⣾⣷⡆⢘⡋⠉⣽⡇⢸   " << ip << std::endl;
std::cout << "⣿⣿⣿⣿⣿⣿⣿⡅⣿⣿⣿⣿⣿⣧⣬⣉⣂⣚⣛⢋⣠⣿⣿⣿⢀⡐⢀⢛⡃⣸   " << uptime<< std::endl;
std::cout << "⣿⣿⣿⣿⣿⣿⣿⣧⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⢸⣿⣿⣿⣿⡘⣿⣿⣿⡇⣿   " << disk << std::endl;
std::cout << "⣿⣿⣿⣿⣿⣿⣿⣿⢸⣿⣿⣿⣿⣿⣿⣿⣿⣿⡏⠩⡿⠛⢿⠿⢃⣿⣿⡿⢣⣿   " << load << std::endl;
std::cout << "⣿⣿⣿⣿⣿⣿⣿⣿⢸⣿⣿⡿⣿⣿⣿⣿⣿⡿⣸⡷⠾⠿⣿⢶⡇⣿⡿⣡⣿⣿   " << proc << std::endl;
std::cout << "⣿⣿⣿⣿⣿⣿⣿⡿⢸⣿⣿⡇⣿⣿⣿⣿⣿⢣⣁⠬⣽⣿⣒⠓⣁⠿⣡⣿⣿⣿   " << gpu << std::endl;
std::cout << "⣿⣿⣿⣿⣿⣿⣿⠇⣿⣿⣿⣵⣿⣿⣿⣿⣿⣿⣿⣷⢖⣉⢱⣾⡟⣴⣿⣿⣿⣿   " << sh << std::endl;
std::cout << "⣿⣿⣿⣿⣿⣿⢏⣾⣿⣿⢟⣻⣿⣿⣿⣿⣿⣿⣿⣿⣿⠟⣋⣭⣾⣿⣿⣿⣿⣿   " << term << std::endl;
std::cout << "⣿⣿⡿⢟⣛⣁⣾⣿⣟⣣⣿⣿⣿⣿⣿⣿⣿⣿⣯⣯⣥⣿⣬⣝⣛⣛⣛⣛⡻⠿   " << date << std::endl;
std::cout << "⣶⣶⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣭⣝⠻⠟⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿   " << arch << std::endl;
std::cout << "                                 " << mac << std::endl;
std::cout << "                                 " << std::endl;
std::cout << "                                 " << std::endl;
std::cout << "                                 " << std::endl;
std::cout << "\033[0m";

return 0;
}

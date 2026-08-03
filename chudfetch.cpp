#include <iostream>
#include <stdlib.h>
#include <string>

int main()
{
std::string host, os, hardware, kernel, hostname, cpu, ram;
char arr[128];
FILE* pipe;

// hostname
pipe = popen("echo $(whoami)@$(hostname)", "r");
fgets(arr, 128, pipe);
host = arr;
host.pop_back();
pclose(pipe);

//os
pipe = popen("echo \"OS: $(lsb_release -sd 2>/dev/null | sed 's/\"//g')\"", "r");
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

std::cout << "\033[37m";
std::cout << "⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠿⠿⠿⠿⠿⠿⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿   " << host << std::endl;
std::cout << "⣿⣿⣿⣿⣿⣿⣿⣿⣿⠿⠛⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠙⠻⠿⣿⣿⣿⣿   " << "- - - - -" << std::endl;
std::cout << "⣿⣿⣿⣿⣿⣿⣿⣿⠋⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣀⣀⡀⠀⢀⠀⠙⣿⣿   " << os << std::endl;
std::cout << "⣿⣿⣿⣿⣿⣿⣿⡇⠀⠀⠀⠀⠀⣠⣴⣶⣶⣶⣶⣿⣿⣿⣿⣿⣿⣿⣷⡌⣿⣿   " << hardware << std::endl;
std::cout << "⣿⣿⣿⣿⣿⣿⣿⡇⠀⠀⠀⠀⣴⣿⣿⣿⣿⣿⣿⣻⣿⣿⣿⡿⣿⣿⣿⣿⡜⣿   " << kernel << std::endl;
std::cout << "⣿⣿⣿⣿⣿⣿⣿⡇⠀⠀⠀⢀⣿⣿⣿⣿⣿⣿⣿⣷⢿⣿⣿⣇⣿⣿⣿⣿⣧⣿   " << hostname << std::endl;
std::cout << "⣿⣿⣿⣿⣿⣿⣿⡇⡆⠀⠀⣸⣿⣯⡉⠙⠛⠿⣿⣿⢺⣿⣿⡇⢿⡿⠿⠛⠉⣿   " << cpu << std::endl;
std::cout << "⣿⣿⣿⣿⣿⣿⣿⢁⡟⣀⣘⣛⣛⡛⢩⣤⣤⣤⣤⣀⠻⠿⠿⡇⢊⣀⣐⣚⡃⢻   " << ram << std::endl;
std::cout << "⣿⣿⣿⣿⣿⣿⣿⠸⣧⣽⣿⣿⣿⡇⢼⠰⠀⠈⠙⣻⠆⣾⣷⡆⢘⡋⠉⣽⡇⢸" << std::endl;
std::cout << "⣿⣿⣿⣿⣿⣿⣿⡅⣿⣿⣿⣿⣿⣧⣬⣉⣂⣚⣛⢋⣠⣿⣿⣿⢀⡐⢀⢛⡃⣸" << std::endl;
std::cout << "⣿⣿⣿⣿⣿⣿⣿⣧⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⢸⣿⣿⣿⣿⡘⣿⣿⣿⡇⣿" << std::endl;
std::cout << "⣿⣿⣿⣿⣿⣿⣿⣿⢸⣿⣿⣿⣿⣿⣿⣿⣿⣿⡏⠩⡿⠛⢿⠿⢃⣿⣿⡿⢣⣿" << std::endl;
std::cout << "⣿⣿⣿⣿⣿⣿⣿⣿⢸⣿⣿⡿⣿⣿⣿⣿⣿⡿⣸⡷⠾⠿⣿⢶⡇⣿⡿⣡⣿⣿" << std::endl;
std::cout << "⣿⣿⣿⣿⣿⣿⣿⡿⢸⣿⣿⡇⣿⣿⣿⣿⣿⢣⣁⠬⣽⣿⣒⠓⣁⠿⣡⣿⣿⣿" << std::endl;
std::cout << "⣿⣿⣿⣿⣿⣿⣿⠇⣿⣿⣿⣵⣿⣿⣿⣿⣿⣿⣿⣷⢖⣉⢱⣾⡟⣴⣿⣿⣿⣿" << std::endl;
std::cout << "⣿⣿⣿⣿⣿⣿⢏⣾⣿⣿⢟⣻⣿⣿⣿⣿⣿⣿⣿⣿⣿⠟⣋⣭⣾⣿⣿⣿⣿⣿" << std::endl;
std::cout << "⣿⣿⡿⢟⣛⣁⣾⣿⣟⣣⣿⣿⣿⣿⣿⣿⣿⣿⣯⣯⣥⣿⣬⣝⣛⣛⣛⣛⡻⠿" << std::endl;
std::cout << "⣶⣶⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣭⣝⠻⠟⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿" << std::endl;
std::cout << "\033[0m";

return 0;
}

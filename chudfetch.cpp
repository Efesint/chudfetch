#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <algorithm>

#include <unistd.h>
#include <pwd.h>
#include <sys/utsname.h>
#include <sys/sysinfo.h>
#include <sys/statfs.h>
#include <ifaddrs.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main() {
std::string host;
std::string os;
std::string hw;
std::string kern;
std::string hn;
std::string cpu;
std::string ram;
std::string ip;
std::string disk;
std::string upt;
std::string load;
std::string proc;
std::string gpu;
std::string sh;
std::string term;
std::string date;
std::string arch;
std::string mac;
std::string user = getpwuid(getuid())->pw_name;

char buf[256];
gethostname(buf, sizeof(buf));

host = user + "@" + buf;

std::ifstream f1("/etc/os-release");
std::string l1;
bool f_os = false;
    while (std::getline(f1, l1)) 
    {
        if (l1.find("PRETTY_NAME") != std::string::npos) 
        {
            size_t p1 = l1.find('=');
            if (p1 != std::string::npos)
            {
                os = l1.substr(p1 + 1);
                os.erase(std::remove(os.begin(), os.end(), '"'), os.end());
                os.erase(std::remove(os.begin(), os.end(), ' '), os.end());
                f_os = true;
                break;
            }
        }
    }
   f1.close();
   if (!f_os)
    {
        std::ifstream f1b("/etc/os-release");
        std::string l1b;
        while (std::getline(f1b, l1b))
        {
            if (l1b.find("NAME") != std::string::npos)
            {
                size_t p1b = l1b.find('=');
                if (p1b != std::string::npos)
                {
                    os = l1b.substr(p1b + 1);
                    os.erase(std::remove(os.begin(), os.end(), '"'), os.end());
                    os.erase(std::remove(os.begin(), os.end(), ' '), os.end());
                    f_os = true;
                    break;
                }
            }
        }
        f1b.close();
    }

    if (!f_os)
    {
        os = "unknown";
    }

std::ifstream f2("/sys/devices/virtual/dmi/id/product_name");
   if (f2)
    {
        std::getline(f2, hw);
        hw.erase(std::remove(hw.begin(), hw.end(), '\n'), hw.end());
        f2.close();
      } else {
        hw = "unknown";
    }

struct utsname u1;
uname(&u1);
kern = u1.release;
hn = buf;

std::ifstream f3("/proc/cpuinfo");
std::string l3;
bool f_cpu = false;
  while (std::getline(f3, l3))
    {
        if (l3.find("model name") != std::string::npos)
        {
            size_t p3 = l3.find(':');
            if (p3 != std::string::npos)
            {
                cpu = l3.substr(p3 + 1);
                size_t st = cpu.find_first_not_of(' ');
                if (st != std::string::npos)
                {
                    cpu = cpu.substr(st);
                }
                f_cpu = true;
                break;
            }
        }
    }
    f3.close();

    if (!f_cpu) 
    {
std::ifstream f3b("/proc/cpuinfo");
std::string l3b;
       while (std::getline(f3b, l3b)) {
            if (l3b.find("Model Name") != std::string::npos) 
            {
                size_t p3b = l3b.find(':');
                if (p3b != std::string::npos)
                {
                    cpu = l3b.substr(p3b + 1);
                    size_t st_b = cpu.find_first_not_of(' ');
                    if (st_b != std::string::npos)
                    {
                        cpu = cpu.substr(st_b);
                    }
                    f_cpu = true;
                    break;
                 }
            }
        }
        f3b.close();
    }

    if (!f_cpu)
     {
        cpu = "unknown";
    }

std::ifstream f4("/proc/meminfo");
std::string l4;
long mem_t = 0;
long mem_a = 0;
   while (std::getline(f4, l4)) 
    {
        if (l4.find("MemTotal") != std::string::npos) 
         {
             std::sscanf(l4.c_str(), "MemTotal: %ld kB", &mem_t);
        }
        if (l4.find("MemAvailable") != std::string::npos) 
        {
            std::sscanf(l4.c_str(), "MemAvailable: %ld kB", &mem_a);
        }
    }
    f4.close();

    double mem_u = (mem_t - mem_a) / 1024.0 / 1024.0;
    double mem_all = mem_t / 1024.0 / 1024.0;
    std::ostringstream ss1;
    ss1.precision(2);
    ss1 << std::fixed << mem_u << " GB / " << mem_all << " GB";
    ram = ss1.str();

    ip = "unknown";
    struct ifaddrs* ifa;
    if (getifaddrs(&ifa) == 0) {
        for (struct ifaddrs* p = ifa; p != nullptr; p = p->ifa_next) {
            if (p->ifa_addr && p->ifa_addr->sa_family == AF_INET) {
                struct sockaddr_in* sa = (struct sockaddr_in*)p->ifa_addr;
                std::string adr = inet_ntoa(sa->sin_addr);
                if (adr != "127.0.0.1") {
                    ip = adr;
                    break;
                 }
            }
        }
        freeifaddrs(ifa);
    }

    struct statfs s1;
  if (statfs("/", &s1) == 0) 
    {
        unsigned long long all = s1.f_blocks * s1.f_bsize;
        unsigned long long free = s1.f_bavail * s1.f_bsize;
        unsigned long long used = all - free;
        double used_gb = used / 1024.0 / 1024.0 / 1024.0;
        double all_gb = all / 1024.0 / 1024.0 / 1024.0;
        double pr = (double)used / all * 100.0;
        std::ostringstream ss2;
        ss2.precision(2);
        ss2 << std::fixed << used_gb << " GB / " << all_gb << " GB (" << (int)pr << "%)";
        disk = ss2.str();
    }

    struct sysinfo inf;
    sysinfo(&inf);
    long sec = inf.uptime;
    long days = sec / 86400;
    long hrs = (sec % 86400) / 3600;
    long min = (sec % 3600) / 60;
    std::ostringstream ss3;
    if (days > 0)
     {
        ss3 << days << " days, ";
    }

    if (hrs > 0)
   {
        ss3 << hrs << " hours, ";
    }
    ss3 << min << " min";
    upt = ss3.str();

    std::ostringstream ss4;
    ss4.precision(2);
    ss4 << std::fixed << inf.loads[0] << ", " << inf.loads[1] << ", " << inf.loads[2];
    load = ss4.str();

    proc = std::to_string(inf.procs);

    std::ifstream f5("/sys/class/drm/card0/device/product_name");
    if (f5) 
    {
        std::getline(f5, gpu);
        gpu.erase(std::remove(gpu.begin(), gpu.end(), '\n'), gpu.end());
        f5.close();
     } else {
        gpu = "unknown";
    }

    sh = getenv("SHELL") ? getenv("SHELL") : "unknown";
    size_t p4 = sh.find_last_of('/');
    if (p4 != std::string::npos)
    {
        sh = sh.substr(p4 + 1);
    }

    term = getenv("TERM") ? getenv("TERM") : "unknown";

    auto now = std::chrono::system_clock::now();
    std::time_t t1 = std::chrono::system_clock::to_time_t(now);
    std::tm* tm1 = std::localtime(&t1);
    char buf2[64];
    std::strftime(buf2, sizeof(buf2), "%Y-%m-%d %H:%M:%S", tm1);
    date = buf2;

    arch = u1.machine;

    std::ifstream f6("/sys/class/net/eth0/address");
    bool f6_o = false;
    if (f6) 
    {
        f6_o = true;
    } else {
        f6.open("/sys/class/net/enp0s3/address");
        if (f6) 
        {
            f6_o = true;
        }
    }

    if (f6_o) 
//i dont wanna fix this shit do it yourself
    {
        std::getline(f6, mac);
        mac.erase(std::remove(mac.begin(), mac.end(), '\n'), mac.end());
        f6.close();
     } else {
        mac = "unknown";
    }

    std::cout << "\033[92m";

    std::cout << "⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠿⠿⠿⠿⠿⠿⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿   ";
    std::cout << host << std::endl;

    std::cout << "⣿⣿⣿⣿⣿⣿⣿⣿⣿⠿⠛⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠙⠻⠿⣿⣿⣿⣿   ";
    std::cout << "- - - - -" << std::endl;

    std::cout << "⣿⣿⣿⣿⣿⣿⣿⣿⠋⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣀⣀⡀⠀⢀⠀⠙⣿⣿   os: ";
    std::cout << "\033[37m" << os << "\033[92m" << std::endl;

    std::cout << "⣿⣿⣿⣿⣿⣿⣿⡇⠀⠀⠀⠀⠀⣠⣴⣶⣶⣶⣶⣿⣿⣿⣿⣿⣿⣿⣷⡌⣿⣿   hardware: ";
    std::cout << "\033[37m" << hw << "\033[92m" << std::endl;

    std::cout << "⣿⣿⣿⣿⣿⣿⣿⡇⠀⠀⠀⠀⣴⣿⣿⣿⣿⣿⣿⣻⣿⣿⣿⡿⣿⣿⣿⣿⡜⣿   kernel: ";
    std::cout << "\033[37m" << kern << "\033[92m" << std::endl;

    std::cout << "⣿⣿⣿⣿⣿⣿⣿⡇⠀⠀⠀⢀⣿⣿⣿⣿⣿⣿⣿⣷⢿⣿⣿⣇⣿⣿⣿⣿⣧⣿   hostname: ";
    std::cout << "\033[37m" << hn << "\033[92m" << std::endl;

    std::cout << "⣿⣿⣿⣿⣿⣿⣿⡇⡆⠀⠀⣸⣿⣯⡉⠙⠛⠿⣿⣿⢺⣿⣿⡇⢿⡿⠿⠛⠉⣿   cpu: ";
    std::cout << "\033[37m" << cpu << "\033[92m" << std::endl;

    std::cout << "⣿⣿⣿⣿⣿⣿⣿⢁⡟⣀⣘⣛⣛⡛⢩⣤⣤⣤⣤⣀⠻⠿⠿⡇⢊⣀⣐⣚⡃⢻   ram: ";
    std::cout << "\033[37m" << ram << "\033[92m" << std::endl;

    std::cout << "⣿⣿⣿⣿⣿⣿⣿⠸⣧⣽⣿⣿⣿⡇⢼⠰⠀⠈⠙⣻⠆⣾⣷⡆⢘⡋⠉⣽⡇⢸   ip: ";
    std::cout << "\033[37m" << ip << "\033[92m" << std::endl;

    std::cout << "⣿⣿⣿⣿⣿⣿⣿⡅⣿⣿⣿⣿⣿⣧⣬⣉⣂⣚⣛⢋⣠⣿⣿⣿⢀⡐⢀⢛⡃⣸   uptime: ";
    std::cout << "\033[37m" << upt << "\033[92m" << std::endl;

    std::cout << "⣿⣿⣿⣿⣿⣿⣿⣧⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⢸⣿⣿⣿⣿⡘⣿⣿⣿⡇⣿   disk: ";
    std::cout << "\033[37m" << disk << "\033[92m" << std::endl;

    std::cout << "⣿⣿⣿⣿⣿⣿⣿⣿⢸⣿⣿⣿⣿⣿⣿⣿⣿⣿⡏⠩⡿⠛⢿⠿⢃⣿⣿⡿⢣⣿   load: ";
    std::cout << "\033[37m" << load << "\033[92m" << std::endl;

    std::cout << "⣿⣿⣿⣿⣿⣿⣿⣿⢸⣿⣿⡿⣿⣿⣿⣿⣿⡿⣸⡷⠾⠿⣿⢶⡇⣿⡿⣡⣿⣿   processes: ";
    std::cout << "\033[37m" << proc << "\033[92m" << std::endl;

    std::cout << "⣿⣿⣿⣿⣿⣿⣿⡿⢸⣿⣿⡇⣿⣿⣿⣿⣿⢣⣁⠬⣽⣿⣒⠓⣁⠿⣡⣿⣿⣿   gpu: ";
    std::cout << "\033[37m" << gpu << "\033[92m" << std::endl;

    std::cout << "⣿⣿⣿⣿⣿⣿⣿⠇⣿⣿⣿⣵⣿⣿⣿⣿⣿⣿⣿⣷⢖⣉⢱⣾⡟⣴⣿⣿⣿⣿   shell: ";
    std::cout << "\033[37m" << sh << "\033[92m" << std::endl;

    std::cout << "⣿⣿⣿⣿⣿⣿⢏⣾⣿⣿⢟⣻⣿⣿⣿⣿⣿⣿⣿⣿⣿⠟⣋⣭⣾⣿⣿⣿⣿⣿   term: ";
    std::cout << "\033[37m" << term << "\033[92m" << std::endl;

    std::cout << "⣿⣿⡿⢟⣛⣁⣾⣿⣟⣣⣿⣿⣿⣿⣿⣿⣿⣿⣯⣯⣥⣿⣬⣝⣛⣛⣛⣛⡻⠿   date: ";
    std::cout << "\033[37m" << date << "\033[92m" << std::endl;

    std::cout << "⣶⣶⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣭⣝⠻⠟⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿   arch: ";
    std::cout << "\033[37m" << arch << "\033[92m" << std::endl;

    std::cout << "                                 mac: ";
    std::cout << "\033[37m" << mac << "\033[92m" << std::endl;

    std::cout << "\033[0m";
    return 0;
}


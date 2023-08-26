#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cstdio>

// Structure to hold process details
struct ProcessDetails {

    int pid;
    int ppid;
    std::string cmd;
    float cpu;
    float mem;
};

void show_process_details()
{
    int pid;
    std::cout << "Enter process ID: ";
    std::cin >> pid;

    char command[256];
    snprintf(command, sizeof(command), "ps -p %d -o pid,ppid,cmd,%%cpu,%%mem", pid);

    FILE* cmd_output = popen(command, "r");
    if (!cmd_output)
    {
        perror("popen");
        return;
    }

    char line[256];
    // Skip the header line
    fgets(line, sizeof(line), cmd_output);

    while (fgets(line, sizeof(line), cmd_output))
    {
        // Convert the line to a C++ string for easier manipulation
        std::string outputLine = line;

        // Parse the line using stringstream and space as delimiter
        std::stringstream ss(outputLine);
        ProcessDetails process;

        // Extract data using stringstream and push into the struct
        ss >> process.pid >> process.ppid >> process.cmd >> process.cpu >> process.mem;

        // Display parsed data
        std::cout << "PID: " << process.pid << ", PPID: " << process.ppid << ", Cmd: " << process.cmd
                  << ", CPU: " << process.cpu << "%, Mem: " << process.mem << "%" << std::endl;
    }

    pclose(cmd_output);
}

int main()
{
    show_process_details();
    return 0;
}

#include <iostream>
#include <string>
#include <cstdio>

void show_process_details()
{
    int pid;
    std::cout << "Enter process ID: ";
    std::cin >> pid;
    char command[256];
    snprintf(command, sizeof(command), "ps -p %d -o pid,ppid,cmd,%%cpu,%%mem", pid);

    // Capture the output of the command
    FILE* cmd_output = popen(command, "r");
    if (!cmd_output)
    {
        perror("popen");
        return;
    }

    // Read and parse the captured output
    char line[256];
    while (fgets(line, sizeof(line), cmd_output))
    {
        // Parse the line and extract relevant information
        // For example, tokenize the line to extract columns
        std::string outputLine = line;
        // ... Perform parsing and data extraction here ...
        std::cout << "Parsed Line: " << outputLine << std::endl;
    }

    pclose(cmd_output);
}

int main()
{
    show_process_details();
    return 0;
}

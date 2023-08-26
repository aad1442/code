#include <iostream>
#include <string>
#include <cstdio>
#include <fstream> // Include the necessary header for file operations

void list_open_files()
{
    int pid;
    std::cout << "Enter process ID: ";
    std::cin >> pid;

    std::string filename = "open_files_process_" + std::to_string(pid) + ".txt";
    std::string command = "ls -l /proc/" + std::to_string(pid) + "/fd > " + filename;
    
    // Execute the command and redirect the output to the specified file
    int result = system(command.c_str());
    
    if (result == 0) {
        std::cout << "Open files information written to " << filename << std::endl;
    } else {
        std::cerr << "Failed to execute the command." << std::endl;
    }
}

int main()
{
    list_open_files();
    return 0;
}

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cstdio>
#include <fstream> // Include the necessary header for file operations

// Structure to hold open file details
struct OpenFileDetails {
    std::string name;
    std::string type;
    int size;
};

void list_open_files()
{
    // Open the output file for writing
    std::ofstream outputFile("open_files_data.txt", std::ios_base::app);

    int pid;
    std::cout << "Enter process ID: ";
    std::cin >> pid;

    std::string command = "ls -l /proc/" + std::to_string(pid) + "/fd";

    // Execute the command and redirect the output to a temporary file
    std::string tempFilename = "temp_open_files.txt";
    command += " > " + tempFilename;
    int result = system(command.c_str());

    if (result != 0) {
        std::cerr << "Failed to execute the command." << std::endl;
        outputFile.close();
        return;
    }

    // Open the temporary file for reading
    std::ifstream tempFile(tempFilename);
    if (!tempFile.is_open()) {
        std::cerr << "Failed to open the temporary file." << std::endl;
        outputFile.close();
        return;
    }

    std::string line;
    while (std::getline(tempFile, line)) {
        // Parse the line using stringstream
        std::istringstream ss(line);
        OpenFileDetails fileDetails;
        ss >> fileDetails.type >> fileDetails.size >> fileDetails.name;

        // Write parsed data to the output file
        outputFile << "Type: " << fileDetails.type << ", Size: " << fileDetails.size
                   << ", Name: " << fileDetails.name << std::endl;
    }

    // Close the temporary file
    tempFile.close();

    // Close the output file
    outputFile.close();
}

int main()
{
    list_open_files();

    return 0;
}

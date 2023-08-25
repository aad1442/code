#include <iostream>
#include "menu_functions.cpp" // Include the menu-related functions

int main() {
    int choice;
    while (true) {
        print_menu();
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        switch (choice) {
            case 1:
                list_processes();
                break;
            case 2:
                show_process_details();
                break;
            case 3:
                kill_process();
                break;
            case 4:
                list_open_files();
                break;
            case 5:
                list_network_connections();
                break;
            case 6:
                monitor_cpu_usage();
                break;
            case 7:
                show_memory_usage();
                break;
            case 8:
                show_disk_usage();
                break;
            case 9:
                show_running_processes_per_user();
                break;
            case 10:
                kill_processes_by_time();
                break;
            case 11:
                show_process_hierarchy();
                break;
            case 12:
                list_processes_by_string();
                break;
            case 13:
                exit(EXIT_SUCCESS);
            default:
                std::cout << "Invalid choice. Try again." << std::endl;
                break;
        }
    }
    return 0;
}

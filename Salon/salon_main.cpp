#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
#include "Employee.hpp"
#include "SalonManagerment.hpp"






int main() {
    SalonManagement system;
    
    while (true) {
        std::cout << "Employee Management System" << std::endl;
        std::cout << "1. Search Employee" << std::endl;
        std::cout << "2. Add Employee" << std::endl;
        std::cout << "3. Remove Employee" << std::endl;
        std::cout << "4. Edit Employee" << std::endl;
        std::cout << "5. View Employee List" << std::endl;
        std::cout << "6. Calculate Paycheck" << std::endl;
        std::cout << "7. Exit" << std::endl;

        int choice;
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        std::cin.ignore();

        switch (choice) {
            case 1: {
                std::string searchFullName;
                std::cout << "Enter employee full name to search: ";
                std::getline(std::cin, searchFullName);
                system.searchEmployee(searchFullName);
                break;
            }
            case 2: {
                std::string fullName;
                double payRate;
                std::string workDays;

                std::cout << "Enter employee full name: ";
                std::getline(std::cin, fullName);
                std::cout << "Enter employee pay rate: ";
                std::cin >> payRate;
                std::cout << "Enter employee work days: ";
                std::cin >> workDays;

                system.addEmployee(fullName, payRate, workDays);
                break;
            }
            case 3: {
                std::string removeFullName;
                std::cout << "Enter employee full name to remove: ";
                std::getline(std::cin, removeFullName);
                system.removeEmployee(removeFullName);
                break;
            }
            case 4: {
                std::string editFullName;
                std::cout << "Enter employee full name to edit: ";
                std::getline(std::cin, editFullName);
                system.editEmployee(editFullName);
                break;
            }
            case 5:
                system.viewEmployeeList();
                break;
            case 6: {
                std::string employeeFullName;
                int daysWorked;

                std::cout << "Enter employee full name: ";
                std::getline(std::cin, employeeFullName);
                std::cout << "Enter number of days worked: ";
                std::cin >> daysWorked;

                system.calculatePaycheck(employeeFullName, daysWorked);
                break;
            }
            case 7:
                std::cout << "Exiting program..." << std::endl;
                return 0;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
                continue;
        }

        std::cout << std::endl;
    }

    return 0;
}

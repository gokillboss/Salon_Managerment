#include <iostream>
#include <iomanip>
#include <fstream>
#include "SalonManagerment.hpp"




// Function to search for employees by substring
void SalonManagement::searchEmployee(const std::string &fullName)
{
    std::vector<std::string> foundEmployees;

    for (const auto &employee : employees)
    {
        if (employee.getFullName().find(fullName) != std::string::npos)
        {
            foundEmployees.push_back(employee.getFullName());
        }
    }

    if (!foundEmployees.empty())
    {
        std::cout << "Employees found:" << std::endl;
        for (const auto &name : foundEmployees)
        {
            std::cout << "Full Name: " << name << std::endl;
        }
    }
    else
    {
        std::cout << "No employees found." << std::endl;
    }
}




// Function to add a new employee
void SalonManagement::addEmployee(const std::string &fullName, double payRate, const std::string &workDays)
{
    employees.push_back(Employee(fullName, payRate, workDays));
    std::cout << "Employee added successfully." << std::endl;
}



// Function to remove an employee by name
void SalonManagement::removeEmployee(const std::string &fullName)
{
    for (auto it = employees.begin(); it != employees.end(); ++it)
    {
        if (it->getFullName() == fullName)
        {
            employees.erase(it);
            std::cout << "Employee removed successfully." << std::endl;
            return;
        }
    }
    std::cout << "Employee not found." << std::endl;
}



// Function to edit an employee's information
void SalonManagement::editEmployee(const std::string &fullName)
{
    for (auto &employee : employees)
    {
        if (employee.getFullName() == fullName)
        {
            std::string newFullName;
            double newPayRate;
            std::string newWorkDays;

            std::cout << "Enter new employee full name: ";
            std::getline(std::cin, newFullName);
            employee.setFullName(newFullName);

            std::cout << "Enter new employee pay rate: ";
            std::cin >> newPayRate;
            std::cout << "Enter new employee work days: ";
            std::cin >> newWorkDays;

            employee.setPayRate(newPayRate);
            employee.setWorkDays(newWorkDays);

            std::cout << "Employee information updated successfully." << std::endl;
            return;
        }
    }
    std::cout << "Employee not found." << std::endl;
}



// Function to view the list of employees
void SalonManagement::viewEmployeeList()
{
    std::cout << "Employee List:" << std::endl;
    std::cout << std::left << std::setw(20) << "Full Name" << std::setw(10) << "Pay Rate" << std::setw(15) << "Work Days" << std::endl;
    std::cout << "------------------------------------------------------------" << std::endl;
    for (const auto &employee : employees)
    {
        std::cout << std::left << std::setw(20) << employee.getFullName() << std::setw(10) << employee.getPayRate() << std::setw(15) << employee.getWorkDays() << std::endl;
    }

    std::cout << "Do you want to save the employee list to a file? (y/n): ";
    char choice;
    std::cin >> choice;
    if (choice == 'y' || choice == 'Y')
    {
        std::string filename;
        std::cout << "Enter the filename: ";
        std::cin >> filename;
        std::cin.ignore();

        std::ofstream outputFile(filename);
        if (outputFile.is_open())
        {
            outputFile << std::left << std::setw(20) << "Full Name" << std::setw(10) << "Pay Rate" << std::setw(15) << "Work Days" << std::endl;
            outputFile << "------------------------------------------------------------" << std::endl;
            for (const auto &employee : employees)
            {
                outputFile << std::left << std::setw(20) << employee.getFullName() << std::setw(10) << employee.getPayRate() << std::setw(15) << employee.getWorkDays() << std::endl;
            }
            outputFile.close();
            std::cout << "Employee list saved to " << filename << " successfully." << std::endl;
        }
        else
        {
            std::cout << "Error opening file for writing." << std::endl;
        }
    }
}




// Function to calculate the paycheck for an employee
void SalonManagement::calculatePaycheck(const std::string &fullName, int daysWorked)
{
    for (const auto &employee : employees)
    {
        if (employee.getFullName() == fullName)
        {
            double paycheck = employee.calculatePaycheck(daysWorked);
            std::cout << "Paycheck for " << employee.getFullName() << ": $" << paycheck << std::endl;
            return;
        }
    }
    std::cout << "Employee not found." << std::endl;
}
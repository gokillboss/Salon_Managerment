#ifndef SALONMANAGEMENT_HPP
#define SALONMANAGEMENT_HPP

#include <string>
#include <vector>
#include <fstream>
#include "Employee.hpp"



class SalonManagement {
private:
    std::vector<Employee> employees;

public:

    void searchEmployee(const std::string& fullName);
    void addEmployee(const std::string& fullName, double payRate, const std::string& workDays);
    void removeEmployee(const std::string& fullName);
    void editEmployee(const std::string& fullName);
    void viewEmployeeList();
    void calculatePaycheck(const std::string& fullName, int daysWorked);

};

#endif
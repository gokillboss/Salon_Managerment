#include "Employee.hpp"
#include <string>

Employee::Employee(const std::string& fullName, double payRate, const std::string& workDays)
    : fullName(fullName), payRate(payRate), workDays(workDays) {}

std::string Employee::getFullName() const {
    return fullName;
}


double Employee::getPayRate() const {
    return payRate;
}

std::string Employee::getWorkDays() const {
    return workDays;
}

void Employee::setFullName(const std::string& newFullName) {
    fullName = newFullName;
}

void Employee::setPayRate(double newPayRate) {
    payRate = newPayRate;
}

void Employee::setWorkDays(const std::string& newWorkDays) {
    workDays = newWorkDays;
}

double Employee::calculatePaycheck(int daysWorked) const {
    return payRate * daysWorked;
}

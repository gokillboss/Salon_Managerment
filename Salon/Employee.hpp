#ifndef EMPLOYEE_HPP
#define EMPLOYEE_HPP

#include <string>

class Employee {
private:
    std::string fullName;
    double payRate;
    std::string workDays;

public:
    Employee(const std::string& fullName, double payRate, const std::string& workDays);

    std::string getFullName() const;
    double getPayRate() const;
    std::string getWorkDays() const;

    void setFullName(const std::string& newFullName);
    void setPayRate(double newPayRate);
    void setWorkDays(const std::string& newWorkDays);

    double calculatePaycheck(int daysWorked) const;
};

#endif

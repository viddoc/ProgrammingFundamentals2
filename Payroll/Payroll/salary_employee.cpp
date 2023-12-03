#include "salary_employee.h"

SalaryEmployee::SalaryEmployee(std::string empID, std::string firstName, std::string lastName, double weeklySalary)
:Employee(empID, firstName, lastName), weeklySalary(weeklySalary){}

double SalaryEmployee::calculatePay(double hours)
{
    return weeklySalary;
}

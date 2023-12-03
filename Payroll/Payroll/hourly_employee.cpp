#include "hourly_employee.h"

HourlyEmployee::HourlyEmployee(std::string empID, std::string firstName, std::string lastName, double hourlyWage)
:Employee(empID,firstName,lastName), hourlyWage(hourlyWage){}

double HourlyEmployee::calculatePay(double hours)
{
    if (hours <= 40)
    {
        return hours * hourlyWage;
    }
    else
    {
        return ((hourlyWage * 40) + ((hours - 40) * (hourlyWage * 1.5)));
    }
}

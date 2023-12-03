#ifndef _HOURLY_EMPLOYEE_H_
#define _HOURLY_EMPLOYEE_H_

#include <string>

#include "employee.h"

class HourlyEmployee : public Employee
{
private:
	double hours;
	double hourlyWage;

public:
	HourlyEmployee(std::string empID, std::string firstName, std::string lastName, double hourlyWage);

	double calculatePay(double hours = 0) override;


};
#endif // !_HOURLY_EMPLOYEE_H_

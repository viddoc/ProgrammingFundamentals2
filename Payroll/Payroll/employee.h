#ifndef _EMPLOYEE_H_
#define _EMPLOYEE_H_

#include <string>

class Employee
{
private:
	std::string empID;
	std::string firstName;
	std::string lastName;

public:
	Employee(std::string empID, std::string firstName, std::string lastName);

	std::string getEmpID() const;
	std::string getFirstName() const;
	std::string getLastName() const;

	bool operator == (const Employee& rhs) const;
	bool operator < (const Employee& rhs) const;

	virtual double calculatePay(double hours = 0) = 0;
};

#endif // !_EMPLOYEE_H_

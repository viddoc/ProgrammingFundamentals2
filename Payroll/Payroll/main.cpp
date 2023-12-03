//Tommy Hudson Payroll program
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cstring>
#include <algorithm>
#include <iomanip>
#include <stdexcept>

#include "employee.h"
#include "salary_employee.h"
#include "hourly_employee.h"

//Global variables
const int EMPID_LENGTH = 7; //Length of an ID is 6
const int FIRSTNAME_LENGTH = 12; //Length of first name is less than 12
const int LASTNAME_LENGTH = 12; //Length of last name is less than 12
const std::string EMPDATA_FILENAME = "employees.dat";
const std::string TIMEDATA_FILENAME = "emp_time.dat";
const std::string PAYROLL_REPORT_FILENAME = "payroll.txt";

struct EmployeeRecord
{
	char employeeType; //H for hourly employee, S for salary
	char id[EMPID_LENGTH]; //ID for employee
	char firstName[FIRSTNAME_LENGTH];
	char lastName[LASTNAME_LENGTH];
	double grossPay; //weekly salary or weekly hourly depending on type
}; //40 bytes

struct EmployeeTime
{
	char id[EMPID_LENGTH];
	double hours;
};
//Function Prototypes
void loadEmployees(std::vector<Employee*>& employees, std::string fileName);
void loadEmployeeTime(std::vector<EmployeeTime>& empTime, std::string fileName);
void createPayrollReport(const std::vector<Employee*>& employees, const std::vector<EmployeeTime>& empTime, std::string fileName);
std::vector<Employee*>::const_iterator findEmployee(const std::vector<Employee*>& employees, std::string id);


int main()
{
	std::vector<Employee*> employees;
	std::vector<EmployeeTime> timeCards;

	loadEmployees(employees, EMPDATA_FILENAME);
	loadEmployeeTime(timeCards, TIMEDATA_FILENAME);
	createPayrollReport(employees, timeCards, PAYROLL_REPORT_FILENAME);

	std::cout << "Complete...";

	return 0;
}

void loadEmployees(std::vector<Employee*>& employees, std::string fileName)
{
	std::fstream file(fileName, std::ios::in | std::ios::binary);
	if (!file)
	{
		throw std::runtime_error("File could not be opened.");
	}
	EmployeeRecord er;
	while (file.read(reinterpret_cast<char*>(&er), sizeof(er)))
	{
		if (er.employeeType == 'H')
		{
			employees.push_back(new HourlyEmployee(er.id, er.firstName, er.lastName, er.grossPay));
		}
		else if (er.employeeType == 'S')
		{
			employees.push_back(new SalaryEmployee(er.id, er.firstName, er.lastName, er.grossPay));
		}
	}
	file.close();
}

void loadEmployeeTime(std::vector<EmployeeTime>& empTime, std::string fileName)
{
	std::fstream file(fileName, std::ios::in | std::ios::binary);
	if (!file)
	{
		throw std::runtime_error("File could not be opened.");
	}
	EmployeeTime et;
	while (file.read(reinterpret_cast<char*>(&et), sizeof(et)))
	{
		empTime.push_back(et);
	}
	file.close();
	
}

void createPayrollReport(const std::vector<Employee*>& employees, const std::vector<EmployeeTime>& empTime, std::string fileName)
{
	std::ofstream file(fileName);
	if (!file)
	{
		throw std::runtime_error("File could not be opened.");
	}
	file << "Payroll Report\n\n";
	file << std::fixed << std::showpoint << std::setprecision(2);
	file << std::setw(EMPID_LENGTH + 1) << std::left << "Emp ID"
		<< std::setw(FIRSTNAME_LENGTH + LASTNAME_LENGTH + 2) << "Employee Name"
		<< std::setw(6) << std::right << "Hours" << " "
		<< std::setw(11) << "Gross Pay\n";

	for (EmployeeTime et : empTime)
	{
		auto it = findEmployee(employees, et.id);
		if (it == employees.end())
		{
			file << "******" << et.id << "NOT FOUND!!!";
		}
		double pay = (*it)->calculatePay(et.hours);
		
		std::string name = (*it)->getLastName() + ", " + (*it)->getFirstName();
		file << std::fixed << std::showpoint << std::setprecision(2);
		file << std::setw(EMPID_LENGTH + 1) << std::left << et.id
			<< std::setw(FIRSTNAME_LENGTH + LASTNAME_LENGTH + 2) << name
			<< std::setw(6) << std::right << et.hours
			<< std::setw(11) << pay << std::endl;
	}
	file.close();

}

std::vector<Employee*>::const_iterator findEmployee(const std::vector<Employee*>& employees, std::string id)
{
	std::vector<Employee*>::const_iterator it;
	for (it = employees.begin(); it != employees.end(); it++)
	{
		if ((*it)->getEmpID() == id)
		{
			return it;
		}
	}
	return it;
}

#include "employee.h"

Employee::Employee(std::string empID, std::string firstName, std::string lastName)
:empID(empID), firstName(firstName),lastName(lastName){}

std::string Employee::getEmpID() const
{
    return empID;
}

std::string Employee::getFirstName() const
{
    return firstName;
}

std::string Employee::getLastName() const
{
    return lastName;
}

bool Employee::operator==(const Employee& rhs) const
{
    return empID == rhs.empID;
}

bool Employee::operator<(const Employee& rhs) const
{
    if (lastName < rhs.lastName)
    {
        return true;
    }
    else if (lastName == rhs.lastName && firstName < rhs.firstName)
    {
        return true;
    }
    else if (lastName == rhs.lastName && firstName == rhs.firstName && empID < rhs.empID)
    {
        return true;
    }
    else
    {
        return false;
    }
}

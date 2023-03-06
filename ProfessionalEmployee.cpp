#include "ProfessionalEmployee.h"

ProfessionalEmployee::ProfessionalEmployee(int healthCare, int hoursWorked, double monthlySalary, int vacationDays) : Employee(healthCare, hoursWorked)
{
	this->monthlySalary = monthlySalary;
	this->vacationDays = vacationDays;
}

// Pre: None
// Post: returns a double representing the weekly salary
double ProfessionalEmployee::calcWeeklySalary()
{
	return (monthlySalary / 5.0);
}

// Pre: None
// Post: returns a double representing the health care earned
double ProfessionalEmployee::calcHealthcare()
{
	// Completely random equation, wasn't sure what to make here
	return hoursWorked * healthCare;
}

// Pre: None
// Post: returns a double representing vacation days that the employee has earned
double ProfessionalEmployee::calcVacationDays() 
{
	// Completely random equation, wasn't sure what to make here
	return (hoursWorked / 8.0) / 10.0;
}
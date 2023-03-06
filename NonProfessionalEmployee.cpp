#include "NonProfessionalEmployee.h"

NonProfessionalEmployee::NonProfessionalEmployee(int healthCare, int hoursWorked, double hourlySalary, int vacationHours) : Employee(healthCare, hoursWorked)
{
	this->hourlySalary = hourlySalary;
	this->vacationHours = vacationHours;
}

// Pre: None
// Post: returns a double representing the weekly salary
double NonProfessionalEmployee::calcWeeklySalary()
{
	return (hoursWorked * hourlySalary * 7.0);
}

// Pre: None
// Post: returns a double representing the health care earned
double NonProfessionalEmployee::calcHealthcare()
{
	// Completely random equation, wasn't sure what to make here
	return hoursWorked * healthCare;
}

// Pre: None
// Post: returns a double representing vacation days that the employee has earned
double NonProfessionalEmployee::calcVacationDays()
{
	// Completely random equation, wasn't sure what to make here
	return ((hoursWorked / 8.0) / 15.0);
}
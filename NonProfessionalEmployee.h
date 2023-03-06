#pragma once
#ifndef NONPROFESSIONALEMPLOYEE_H_
#define NONPROFESSIONALEMPLOYEE_H_

#include "Employee.h"

class NonProfessionalEmployee : public Employee {
public:
	// Constructor
	NonProfessionalEmployee(int healthCare, int hoursWorked, double hourlySalary, int vacationHours);
	// Functions
	double calcWeeklySalary();
	double calcHealthcare();
	double calcVacationDays();
protected:
	double hourlySalary;
	int vacationHours;
};

#endif
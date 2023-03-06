#pragma once
#ifndef PROFESSIONALEMPLOYEE_H_
#define PROFESSIONALEMPLOYEE_H_

#include "Employee.h"

class ProfessionalEmployee : public Employee {
public:
	// Constructor
	ProfessionalEmployee(int healthCare, int hoursWorked, double monthlySalary, int vacationDays);
	// Functions
	double calcWeeklySalary();
	double calcHealthcare();
	double calcVacationDays();
protected:
	double monthlySalary;
	int vacationDays;
};

#endif

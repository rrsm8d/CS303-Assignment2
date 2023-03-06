#pragma once
#ifndef EMPLOYEE_H_
#define EMPLOYEE_H_
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Employee {
public:
	// Constructor
	Employee(int healthCare, int hoursWorked);
	// Pure virtual functions
	virtual double calcWeeklySalary() = 0;
	virtual double calcHealthcare() = 0;
	virtual double calcVacationDays() = 0;

protected:
	int healthCare;
	int hoursWorked;
};

#endif
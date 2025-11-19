#pragma once
#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <string>
using namespace std;

struct Employee {
	int id = 0;
	string Name;
	string Last_Name;
	string Address;
	double Salary = 0.0;
	string Hire_Date;
	int Bank_Branch=1;
};

#endif
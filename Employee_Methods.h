#pragma once
#ifndef EMPLOYEE_METHODS_H
#define EMPLOYEE_METHODS_H
#include "Employee.h"

void AddEmployee(Employee* employees, int& EmployeeCount, int& capacity);
void NewArray(Employee*& employees, int& capacity, int EmployeeCount);
int FindEmployee(Employee* employees, int ID, int EmployeeCount);
void DeleteEmployee(Employee* employees, int& EmployeeCount);
void ModifyEmployee(Employee* employees, int EmployeeCount);
void DisplayEmployees(Employee* employees, int EmployeeCount);
void DisplayEmployeesSortedByAlphabeticalOrder(Employee* employees, int EmployeeCount);

#endif
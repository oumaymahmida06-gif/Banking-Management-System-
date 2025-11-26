#pragma once
#ifndef EMPLOYEE_METHODS_H
#define EMPLOYEE_METHODS_H
#include "Employee.h"
#include "Customer.h"


void AddEmployee(Employee* employees, int& EmployeeCount, int& capacity);
void NewArray(Employee*& employees, int& capacity, int EmployeeCount);
bool Verify_Id(const int& ID);
bool Verify_Salary(const double& Salary);
bool Verify_Bank_Branch(const int& Bank_Branch);
bool Verify_Address(const string& Address);
bool Verify_Name(const string& Name);
bool Verify_Last_Name(const string& Last_Name);
bool Verify_Hire_Date(const string& date);
int FindEmployee(Employee* employees, int ID, int EmployeeCount);
void DeleteEmployee(Employee* employees, int& EmployeeCount);
void ModifyEmployee(Employee* employees, int EmployeeCount);
void PrintEmployee(const Employee& e);
void DisplayEmployees(Employee* employees, int EmployeeCount);
void DisplayEmployeesSortedByAlphabeticalOrder(Employee* employees, int EmployeeCount);
void DisplayEmployeesGroupedByBankBranch(Employee* employees, int EmployeeCount);
void DisplayEarliestAndRecentEmployees(Employee* employees, int EmployeeCount);
string Reformulate(string hiredate);


void employee_interface(Employee*& employees, int& EmployeeCount, int& capacity, customer*& customers, int& CustomerCount, int& Customer_Capacity);
#endif

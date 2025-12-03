#pragma once
#ifndef STATISTICSMETHS_H
#define STATISTICSMETHS_H
#include "DoublyLinkedListMeths.h"
#include "SinglyLinkedListMeths.h"
#include "TransactionMeths.h"
#include "QueueMeths.h"
#include "Customer_Methods.h"
#include "Employee_Methods.h"
#include "DailyTransactionsLogListMeths.h"
#include "TodaysDate.h"

void Total_Number_of_Loans(const customer* customers, int CustomerCount);
void Number_of_Loans_By_Type(const customer* customers, int CustomerCount);
void Number_of_loans_by_status(const customer* customers, int CustomerCount, int ArchivedCount);
void Active_loans_within_a_specified_date_range(const customer* customers, int CustomerCount);
void Customer_with_the_highest_number_of_loans(const customer* customers, int CustomerCount);
void Customer_with_the_highest_account_balance(const customer* customers, int CustomerCount);
void Customer_with_the_lowest_account_balance(const customer* customers, int CustomerCount);
void Total_number_of_employees(const Employee* employees, int EmployeeCount);
void Number_of_employees_per_bank_branch(const Employee* employees, int EmployeeCount);

void statistics_interface(const customer* customers, int CustomerCount, const Employee* employees, int EmployeeCount, int ArchivedCount);
#endif

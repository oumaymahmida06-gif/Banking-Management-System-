#pragma once
#ifndef DATA_H
#define DATA_H
#include "DoublyLinkedListMeths.h"
#include "SinglyLinkedListMeths.h"
#include "TransactionMeths.h"
#include "QueueMeths.h"
#include "Customer_Methods.h"
#include "Employee_Methods.h"
#include "DailyTransactionsLogListMeths.h"
#include "TodaysDate.h"

void LoadDemoData(customer*& customers, int& CustomerCount, int& Customer_Capacity, Employee*& employees, int& EmployeeCount, int capacity);
#endif

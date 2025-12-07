#include <iostream>
#include "Employee_Methods.h"
#include "Customer_Methods.h"
#include "SinglyLinkedListMeths.h"
#include "DailyTransactionsLogListMeths.h"
#include "StatisticsMeths.h"
#include "TodaysDate.h"
#include "Data.h"
using namespace std;

int main() {
    int Customer_Capacity = 200;
    customer* customers = new customer[Customer_Capacity];
    int CustomerCount = 0;

    int Archived_Capacity = 200;
    customer* archived = new customer[Archived_Capacity];
    int ArchivedCount = 0;
    

    int capacity = 200;
    Employee* employees = new Employee[capacity];
    int EmployeeCount = 0;

    CompletedLoanList CompletedLoansList = Create_Completed_Loan_List();
    Queue* Loan_Requests = CreateQueue();
    DailyTransactionsLogList  Daily_Transactions_Log_List = Create_Daily_Transactions_Log_List();
    string TodaysDate = GetTodayDate();
	char choice;

    LoadDemoData(customers, CustomerCount, Customer_Capacity,employees, EmployeeCount, capacity);

    do {
        cout << "============================================================================================" << endl;
        cout << "============================================================================================" << endl;
        cout << "                    Welcome to the Banking Management System" << endl;
        cout << "\n";
        cout << "                              Today's Date : " << TodaysDate << endl;
        cout << "============================================================================================" << endl;
        cout << "============================================================================================" << endl;
        cout << "                            1. Employee Interface\n";
        cout << "                            2. Customer Interface\n";
        cout << "============================================================================================" << endl;
        cout << "============================================================================================" << endl;
        cout << "                                 0. Exit\n";
        cout << "============================================================================================" << endl;
        cout << "============================================================================================" << endl;
        cout << "                          PLEASE CHOOSE AN OPERATION: ";
        cin >> choice;

        switch (choice) {
        case '1':
            employee_interface(employees, EmployeeCount, capacity, customers, CustomerCount, Customer_Capacity, archived, ArchivedCount, Archived_Capacity, CompletedLoansList, Loan_Requests, &Daily_Transactions_Log_List);
            break;
        case '2':
            customer_interface(customers, CustomerCount, Customer_Capacity, *Loan_Requests);
            break;
        case '0':
            cout << "Exiting program.......\n";
            break;
        default:
            cout << "Invalid option. Try again.\n";
        }

    } while (choice != '0');
	delete[] customers;
    delete[] employees;
	delete[] archived;
	DestroyQueue(Loan_Requests);
    return 0;
}

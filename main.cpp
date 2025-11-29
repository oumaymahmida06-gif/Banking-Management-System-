#include <iostream>
#include "Employee_Methods.h"
#include "Customer_Methods.h"
using namespace std;

int main() {
    int Customer_Capacity = 200;
    customer* customers = new customer[Customer_Capacity];
    int CustomerCount = 0;

    int Archived_Capacity = 200;
    customer* archived = new customer[200];
    int ArchivedCount = 0;
    

    int capacity = 200;
    Employee* employees = new Employee[capacity];
    int EmployeeCount = 0;

	int choice;


    do {
        cout << "============================================================================================" << endl;
        cout << "============================================================================================" << endl;
        cout << "                    Welcome to the Banking Management System" << endl;
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
        case 1:
            employee_interface(employees, EmployeeCount, capacity, customers, CustomerCount, Customer_Capacity, archived, ArchivedCount, Archived_Capacity);
            break;
        case 2:
            customer_interface(customers, CustomerCount, Customer_Capacity);
            break;
        case 0:
            cout << "Exiting program.......\n";
            break;
        default:
            cout << "Invalid option. Try again.\n";
        }

    } while (choice != 0);
	delete[] customers;
	delete[] employees;
	delete[] archived;
    return 0;
}

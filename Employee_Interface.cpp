#include <iostream>
#include "Employee_Methods.h"
using namespace std;

int main()
{
    int capacity = 200;
    Employee* employees = new Employee[capacity];
    int EmployeeCount = 0;

    int choice;

    do {
        cout << "\n============= EMPLOYEE MANAGEMENT SYSTEM =============\n";
        cout << "1. Add Employee\n";
        cout << "2. Delete Employee\n";
        cout << "3. Modify Employee\n";
        cout << "4. Display All Employees\n";
        cout << "5. Display All Employees Sorted By Alphabetical Order\n";
        cout << "0. Exit\n";
        cout << "Choose an operation : ";
        cin >> choice;

        switch (choice) {
        case 1:
            AddEmployee(employees, EmployeeCount, capacity);
            break;
        case 2:
            DeleteEmployee(employees, EmployeeCount);
            break;
        case 3:
            ModifyEmployee(employees, EmployeeCount);
            break;
        case 4:
            DisplayEmployees(employees, EmployeeCount);
            break;
        case 5:
            DisplayEmployeesSortedByAlphabeticalOrder(employees, EmployeeCount);
            break;
        case 0:
            cout << "Exiting program.......\n";
            break;
        default:
            cout << "Invalid option. Try again.\n";
        }

    } while (choice != 0);

    delete[] employees;
    return 0;
}
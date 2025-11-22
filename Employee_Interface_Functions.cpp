#include <iostream>
#include "Employee_Methods.h"
using namespace std;

void AddEmployee(Employee* employees, int& EmployeeCount, int& capacity) {
	if (EmployeeCount == capacity) {
		NewArray(employees, capacity, EmployeeCount);
	}
	Employee e;
	cout << "Enter the ID of the employee:" << endl;
	cin >> e.id;
	cin.ignore();
	cout << "Enter the Name of the employee:" << endl;
	getline(cin, e.Name);
	cout << "Enter the Last Name of the employee:" << endl;
	getline(cin, e.Last_Name);
	cout << "Enter the Address of the employee:" << endl;
	getline(cin, e.Address);
	cout << "Enter the Salary of the employee:" << endl;
	cin >> e.Salary;
	cin.ignore();
	cout << "Enter the Hire Date of the employee:" << endl;
	getline(cin, e.Hire_Date);
	cout << "Enter the Bank Branch of the employee:" << endl;
	cin >> e.Bank_Branch;
	employees[EmployeeCount] = e;
	EmployeeCount++;
}

void NewArray(Employee*& employees, int& capacity, int EmployeeCount) {
	int NewSize = capacity * 2;
	Employee* NewArr = new Employee[NewSize];
	for (int i = 0; i < EmployeeCount; i++) {
		NewArr[i] = employees[i];
	}
	delete[] employees;
	employees = NewArr;
	capacity = NewSize;
}


int FindEmployee(Employee* employees, int ID, int EmployeeCount) {
	for (int i = 0; i < EmployeeCount; i++) {
		if (employees[i].id == ID) {
			return i;
		}
	}
	return -1;
}

void DeleteEmployee(Employee* employees, int& EmployeeCount) {
	if (EmployeeCount == 0) {
		cout << "There's no existant employees\n";
		return;
	}
	else {
		int ID,p;
		cout << "Enter the employee's ID to delete: ";
		cin >> ID;
		p = FindEmployee(employees, ID, EmployeeCount);
		if (p!=-1) {
			for (int j = p; j < EmployeeCount - 1; j++) {
				employees[j] = employees[j + 1];
			}
			EmployeeCount--;
			cout << "Employee deleted successfully!\n";
		}
		else {
			cout << "Employee not found!\n";
		}
		
	}
}


void ModifyEmployee(Employee* employees, int EmployeeCount) {
	if (EmployeeCount == 0) {
		cout << "There's no existant employees\n";
		return;
	}
	else {
		int ID, p;
		cout << "Enter the employee's ID to Modify: ";
		cin >> ID;
		p = FindEmployee(employees, ID, EmployeeCount);
		if (p != -1) {
			cout << "Enter new ID: ";
			int newID;
			cin >> newID;
			int exist = FindEmployee(employees, newID, EmployeeCount);
			if (exist != -1 && exist != p) {
				cout << "This ID is already used by another employee.\n";
			}
			else {
				employees[p].id = newID;
				cin.ignore();
				cout << "Enter new name: ";
				getline(cin, employees[p].Name);
				cout << "Enter new last name: ";
				getline(cin, employees[p].Last_Name);
				cout << "Enter new address: ";
				getline(cin, employees[p].Address);
				cout << "Enter new salary: ";
				cin >> employees[p].Salary;
				cin.ignore();
				cout << "Enter new hire date: ";
				getline(cin, employees[p].Hire_Date);
				cout << "Enter new branch code: ";
				cin >> employees[p].Bank_Branch;
				cout << "Employee modified successfully!\n";
			}
		}
		else {
			cout << "Employee not found!\n";
		}

	}
}
void DisplayEmployees(Employee* employees, int EmployeeCount) {
	if (EmployeeCount == 0) {
		cout << "No employees to display.\n";
		return;
	}

	cout << "\n------ Employee List ------\n";

	for (int i = 0; i < EmployeeCount; i++) {
		cout << "Employee #" << i + 1 << ":\n";
		cout << "ID: " << employees[i].id << "\n";
		cout << "Name: " << employees[i].Name << "\n";
		cout << "Last Name: " << employees[i].Last_Name << "\n";
		cout << "Address: " << employees[i].Address << "\n";
		cout << "Salary: " << employees[i].Salary << "\n";
		cout << "Hire Date: " << employees[i].Hire_Date << "\n";
		cout << "Bank Branch: " << employees[i].Bank_Branch << "\n";
		cout << "-------------------------\n";
	}
}

void DisplayEmployeesSortedByAlphabeticalOrder(Employee* employees, int EmployeeCount) {
	if (EmployeeCount == 0) {
		cout << "There's no existant employees\n";
		return;
	}
	Employee* Sorted = new Employee[EmployeeCount];
	for (int i = 0; i < EmployeeCount; i++) {
		Sorted[i] = employees[i];
	}
	for (int i = 0; i < EmployeeCount; i++) {
		for (int j = 0; j < EmployeeCount - 1; j++) {
			if (Sorted[j].Last_Name > Sorted[j + 1].Last_Name) {
				Employee temp = Sorted[j];
				Sorted[j] = Sorted[j + 1];
				Sorted[j + 1] = temp;
			}
		}

	}
	cout << "\n========= Employees (Alphabetical by Last Name) =========\n";
	for (int i = 0; i < EmployeeCount; i++) {
		cout << "ID: " << Sorted[i].id << endl;
		cout << "Name: " << Sorted[i].Name << endl;
		cout << "Last Name: " << Sorted[i].Last_Name << endl;
		cout << "Address: " << Sorted[i].Address << endl;
		cout << "Salary: " << Sorted[i].Salary << endl;
		cout << "Hire Date: " << Sorted[i].Hire_Date << endl;
		cout << "Bank Branch: " << Sorted[i].Bank_Branch << endl;
		cout << "------------------------------------\n";
	}

	delete[] Sorted;

}

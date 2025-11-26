#include <iostream>
#include "Employee_Methods.h"
#include "Customer_Methods.h"
using namespace std;

void AddEmployee(Employee* employees, int& EmployeeCount, int& capacity) {
	if (EmployeeCount == capacity) {
		NewArray(employees, capacity, EmployeeCount);
	}
	Employee e;
	int ID;
	do {
		cout << "Enter the ID of the employee:" << endl;
		cin >> ID;
	} while (!Verify_Id(ID));
	e.id = ID;
	cin.ignore();
	string Name;
	do {
		cout << "Enter the Name of the employee: ";
		getline(cin, Name);
	} while (!Verify_Name(Name));
	e.Name = Name;
	string Last_Name;
	do {
		cout << "Enter the Last Name of the employee: ";
		getline(cin, Last_Name);
	} while (!Verify_Last_Name(Last_Name));
	e.Last_Name = Last_Name;
	string Address;
	do {
		cout << "Enter the Adress of the employee: ";
		getline(cin, Address);
	} while (!Verify_Address(Address));
	e.Address = Address;
	double salary;
	do {
		cout << "Enter the Salary of the employee:" << endl;
		cin >> salary;
	} while (!Verify_Salary(salary));
	e.Salary = salary;
	cin.ignore();
	string date;
	do {
		cout << "Enter the Hire Date of the employee: ";
		getline(cin, date);
	} while (!Verify_Hire_Date(date));
	e.Hire_Date = date;
	int bank_branch;
	do {
		cout << "Enter the bank branch of the employee:" << endl;
		cin >> bank_branch;
	} while (!Verify_Bank_Branch(bank_branch));
	e.Bank_Branch= bank_branch;
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

bool Verify_Id(const int& ID) {
	if ((ID > 9999) || (ID<999)) {
		cout << "The ID must be a positive number containing 4 digits.\n";
		return false;
	}
	return true;
}
bool Verify_Salary(const double& Salary) {
	if (Salary < 0) {
		cout << "The Salary must be a positive number.\n";
		return false;
	}
	return true;
}
bool Verify_Bank_Branch(const int& Bank_Branch) {
	if (Bank_Branch < 1) {
		cout << "The bank branch must be a number >=1 .\n";
		return false;
	}
	return true;
}
bool Verify_Address(const string& Address) {
	if (Address.empty()) {
		cout << "The address cannot be empty.\n";
		return false;
	}
	return true;
}
bool Verify_Name(const string& Name) {

	if (Name.length() < 3) {
		cout << "The name must be at least 3 characters long.\n";
		return false;
	}

	if (!isupper(Name[0])) {
		cout << "The first letter must be uppercase.\n";
		return false;
	}

	for (int i = 1; i < Name.length(); i++) {
		if (!isalpha(Name[i])) {
			cout << "The name must contain only alphabetical letters.\n";
			return false;
		}
		if (!islower(Name[i])) {
			cout << "All letters except the first one must be lowercase.\n";
			return false;
		}
	}

	return true;
}


bool Verify_Last_Name(const string& Last_Name) {

	if (Last_Name.length() < 3) {
		cout << "The last name must be at least 3 characters long.\n";
		return false;
	}

	if (!isupper(Last_Name[0])) {
		cout << "The first letter must be uppercase.\n";
		return false;
	}

	for (int i = 1; i < Last_Name.length(); i++) {
		if (!isalpha(Last_Name[i])) {
			cout << "The last name must contain only alphabetical letters.\n";
			return false;
		}
		if (!islower(Last_Name[i])) {
			cout << "All letters except the first one must be lowercase.\n";
			return false;
		}
	}

	return true;
}
bool Verify_Hire_Date(const string& date) {
	if (date.length() != 10) {
		cout << "The date must be in the format DD-MM-YYYY.\n";
		return false;
	}
	if (!isdigit(date[0]) || !isdigit(date[1]) || date[2] != '-' || !isdigit(date[3]) || !isdigit(date[4]) || date[5] != '-' || !isdigit(date[6]) || !isdigit(date[7]) || !isdigit(date[8]) || !isdigit(date[9])) {
		cout << "The date must be in the format DD-MM-YYYY.\n";
		return false;
	}
	int day = stoi(date.substr(0, 2));
	int month = stoi(date.substr(3, 2));
	int year = stoi(date.substr(6, 4));
	if (day < 1 || day > 31 || month < 1 || month > 12) {
		cout << "the day must be between 1 and 31; the month must be between 1 and 12.\n ";
		return false;
	}
	return true;
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
			int newID;
			bool ValidID = true;
			do {
				cout << "Enter the new ID of the Employee:" << endl;
				cin >> newID;
				if (!Verify_Id(newID)) {
					ValidID = false;
				}
				else {
					int exist = FindEmployee(employees, newID, EmployeeCount);
					if (exist != -1 && exist != p) {
						cout << "This ID is already used by another employee. Try again.\n";
						ValidID = false;
					}
					else {
						ValidID = true;
					}
				}
			} while (ValidID==false);
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
		else {
			cout << "Employee not found!\n";
			return;
		}

	}
}
void PrintEmployee(const Employee& e) {
	cout << "ID: " << e.id << endl;
	cout << "Name: " << e.Name << endl;
	cout << "Last Name: " << e.Last_Name << endl;
	cout << "Address: " << e.Address << endl;
	cout << "Salary: " << e.Salary << endl;
	cout << "Hire Date: " << e.Hire_Date << endl;
	cout << "Bank Branch: " << e.Bank_Branch << endl;
	cout << "------------------------------------\n";
}
void DisplayEmployees(Employee* employees, int EmployeeCount) {
	if (EmployeeCount == 0) {
		cout << "No employees to display.\n";
		return;
	}

	cout << "\n------ Employee List ------\n";

	for (int i = 0; i < EmployeeCount; i++) {
		PrintEmployee(employees[i]);
	}
}

void DisplayEmployeesSortedByAlphabeticalOrder(Employee* employees, int EmployeeCount) {
	if (EmployeeCount == 0) {
		cout << "There's no existant employees to display.\n";
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
	cout << "\n========= Employees (Sorted By Alphabetical Order Of The Last Name) =========\n";
	for (int i = 0; i < EmployeeCount; i++) {
		PrintEmployee(Sorted[i]);
	}

	delete[] Sorted;
}
void DisplayEmployeesGroupedByBankBranch(Employee* employees, int EmployeeCount) {
	if (EmployeeCount == 0) {
		cout << "There's no existant employees to display.\n";
		return;
	}
	Employee* BranchSort = new Employee[EmployeeCount];
	for (int i = 0; i < EmployeeCount; i++) {
		BranchSort[i] = employees[i];
	}
	for (int i = 0; i < EmployeeCount; i++) {
		for (int j = 0; j < EmployeeCount - 1; j++) {
			if (BranchSort[j].Bank_Branch > BranchSort[j + 1].Bank_Branch) {
				Employee temp = BranchSort[j];
				BranchSort[j] = BranchSort[j + 1];
				BranchSort[j + 1] = temp;
			}
		}

	}
	cout << "\n============= Employees (Grouped By Bank Branch) =============\n";
	int i = 0;
	while (i < EmployeeCount) {
		int CurrentBranch = BranchSort[i].Bank_Branch;
		cout << "\n=========Bank Branch: " << BranchSort[i].Bank_Branch <<"=========\n";
		while (i < EmployeeCount && BranchSort[i].Bank_Branch == CurrentBranch) {
			PrintEmployee(BranchSort[i]);
			i++;
		}
	}
	delete[] BranchSort;
}
string Reformulate(string hiredate) {
	string day = hiredate.substr(0, 2);
	string month = hiredate.substr(3, 2);
	string year = hiredate.substr(6, 4);
	return year + month + day;
}
void DisplayEarliestAndRecentEmployees(Employee* employees, int EmployeeCount) {
	if (EmployeeCount == 0) {
		cout << "There's no existant employees to display.\n";
		return;
	}
	Employee* HireDateSort = new Employee[EmployeeCount];
	for (int i = 0; i < EmployeeCount; i++)
		HireDateSort[i] = employees[i];
	for (int i = 0; i < EmployeeCount; i++) {
		for (int j = 0; j < EmployeeCount - 1; j++) {
			if (Reformulate(HireDateSort[j].Hire_Date) > Reformulate(HireDateSort[j + 1].Hire_Date)) {
				Employee temp = HireDateSort[j];
				HireDateSort[j] = HireDateSort[j + 1];
				HireDateSort[j + 1] = temp;
			}
		}

	}

	cout << "\n======== The Earliest Employee ========\n";
	PrintEmployee(HireDateSort[0]);
	cout << "---------------------------------------------\n";
	cout << "\n======== The Most Recent Employees ========\n";
	PrintEmployee(HireDateSort[EmployeeCount - 1]);
	cout << "---------------------------------------------\n";
	delete[] HireDateSort;
}

void employee_interface(Employee*& employees, int& EmployeeCount, int& capacity,customer*& customers, int& CustomerCount, int& Customer_Capacity)
{
	int employee_choice;

	do {
		cout << "============================================================================================" << endl;
		cout << "============================================================================================" << endl;
		cout << "                    Welcome to the EMPLOYEE MANAGEMENT SYSTEM" << endl;
		cout << "============================================================================================" << endl;
		cout << "============================================================================================" << endl;
		cout << "1. Add Employee\n";
		cout << "2. Delete Employee\n";
		cout << "3. Modify Employee\n";
		cout << "4. Display All Employees\n";
		cout << "5. Display All Employees Sorted By Alphabetical Order\n";
		cout << "6. Display All Employees Grouped By Bank Branch\n";
		cout << "7. Display Earliest And Most Recent Employees\n";
		cout << "8. Add Customer\n";
		cout << "9. Display All Customers\n";
		cout << "10. Change Customer Account Status\n";
		cout << "0. Return to Home\n";
		cout << "Choose an operation : ";
		cin >> employee_choice;

		switch (employee_choice) {
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
		case 6:
			DisplayEmployeesGroupedByBankBranch(employees, EmployeeCount);
			break;
		case 7:
			DisplayEarliestAndRecentEmployees(employees, EmployeeCount);
			break;
		case 8:
			AddCustomer(customers, CustomerCount, Customer_Capacity);
			break;
		case 9:
			DisplayCustomers(customers, CustomerCount);
			break;
		case 10:
			ChangeCustomerAccountStatus(customers, CustomerCount);
			break;
		case 0:
			cout << "Returning.......\n";
			break;
		default:
			cout << "Invalid option. Try again.\n";
		}

	} while (employee_choice != 0);

}

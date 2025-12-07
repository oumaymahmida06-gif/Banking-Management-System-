#include <iostream>
#include "Customer_Methods.h"
#include "Employee_Methods.h"
#include "TransactionMeths.h"
#include "DoublyLinkedListMeths.h"
#include "SinglyLinkedListMeths.h"
#include "QueueMeths.h"
#include "DailyTransactionsLogListMeths.h"
#include "StatisticsMeths.h"
#include "TodaysDate.h"
#include <limits>
using namespace std;

//------------------------ARRAY--------------------------

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
int FindEmployee(Employee* employees, int ID, int EmployeeCount) {
	for (int i = 0; i < EmployeeCount; i++) {
		if (employees[i].id == ID) {
			return i;
		}
	}
	return -1;
}
//DYNAMIC ALLOCATION:
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

//------------------------VERIFICATION--------------------------

bool Verify_Id(const int& ID) {
	if ((ID > 9999) || (ID < 999)) {
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

//------------------------EMPLOYEE INTERFACE FUNCTIONS--------------------------

void AddEmployee(Employee* employees, int& EmployeeCount, int& capacity) {
	if (EmployeeCount == capacity) {
		NewArray(employees, capacity, EmployeeCount);
	}
	Employee e;
	do {
		cout << "Enter the ID of the employee:" << endl;
		cin >> e.id;

		if (cin.fail()) {
			cout << "Invalid input. Please enter numbers only.\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			continue;
		}

	} while (!Verify_Id(e.id));

	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	do {
		cout << "Enter the Name of the employee: ";
		getline(cin, e.Name);
	} while (!Verify_Name(e.Name));

	do {
		cout << "Enter the Last Name of the employee: ";
		getline(cin, e.Last_Name);
	} while (!Verify_Last_Name(e.Last_Name));

	do {
		cout << "Enter the Adress of the employee: ";
		getline(cin, e.Address);
	} while (!Verify_Address(e.Address));

	do {
		cout << "Enter the Salary of the employee:" << endl;
		cin >> e.Salary;

		if (cin.fail()) {
			cout << "Invalid input. Please enter a valid number.\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			continue;
		}

	} while (!Verify_Salary(e.Salary));

	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	do {
		cout << "Enter the Hire Date of the employee: ";
		getline(cin, e.Hire_Date);
	} while (!Verify_Hire_Date(e.Hire_Date));

	do {
		cout << "Enter the bank branch of the employee:" << endl;
		cin >> e.Bank_Branch;

		if (cin.fail()) {
			cout << "Invalid input. Please enter numbers only.\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			continue;
		}

	} while (!Verify_Bank_Branch(e.Bank_Branch));
	employees[EmployeeCount] = e;
	EmployeeCount++;
}

void DeleteEmployee(Employee* employees, int& EmployeeCount) {
	if (EmployeeCount == 0) {
		cout << "There's no existant employees\n";
		return;
	}
	int ID, p;
	do {
		cout << "Enter the employee's ID to delete: ";
		cin >> ID;

		if (cin.fail()) {
			cout << "Invalid input. Please enter numbers only.\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			continue;
		}

		break;

	} while (!Verify_Id(ID));

	p = FindEmployee(employees, ID, EmployeeCount);
	if (p != -1) {
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


void ModifyEmployee(Employee* employees, int EmployeeCount) {
	if (EmployeeCount == 0) {
		cout << "There's no existant employees\n";
		return;
	}
	int ID, p;
	do {
		cout << "Enter the employee's ID to Modify: ";
		cin >> ID;

		if (cin.fail()) {
			cout << "Invalid input. Please enter numbers only.\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			continue;
		}

	} while (!Verify_Id(ID));
	p = FindEmployee(employees, ID, EmployeeCount);
	if (p != -1) {
		int newID;
		bool ValidID = true;

		do {
			cout << "Enter the new ID of the Employee:" << endl;
			cin >> newID;

			if (cin.fail()) {
				cout << "Invalid input. Please enter numbers only.\n";
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				ValidID = false;
				continue;
			}

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
		} while (ValidID == false);

		employees[p].id = newID;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		do {
			cout << "Enter the new Name of the employee: ";
			getline(cin, employees[p].Name);
		} while (!Verify_Name(employees[p].Name));
		do {
			cout << "Enter the new Last Name of the employee: ";
			getline(cin, employees[p].Last_Name);
		} while (!Verify_Last_Name(employees[p].Last_Name));
		do {
			cout << "Enter the new Adress of the employee: ";
			getline(cin, employees[p].Address);
		} while (!Verify_Address(employees[p].Address));
		do {
			cout << "Enter the Salary of the employee:" << endl;
			cin >> employees[p].Salary;

			if (cin.fail()) {
				cout << "Invalid input. Please enter a valid number.\n";
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				continue;
			}

		} while (!Verify_Salary(employees[p].Salary));
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		do {
			cout << "Enter the Hire Date of the employee: ";
			getline(cin, employees[p].Hire_Date);
		} while (!Verify_Hire_Date(employees[p].Hire_Date));
		do {
			cout << "Enter the bank branch of the employee:" << endl;
			cin >> employees[p].Bank_Branch;

			if (cin.fail()) {
				cout << "Invalid input. Please enter numbers only.\n";
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				continue;
			}

		} while (!Verify_Bank_Branch(employees[p].Bank_Branch));
		cout << "Employee modified successfully!\n";
	}
	else {
		cout << "Employee not found!\n";
		return;
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
		cout << "\n=========Bank Branch: " << BranchSort[i].Bank_Branch << "=========\n";
		while (i < EmployeeCount && BranchSort[i].Bank_Branch == CurrentBranch) {
			PrintEmployee(BranchSort[i]);
			i++;
		}
	}
	delete[] BranchSort;
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
string Reformulate(string hiredate) {
	string day = hiredate.substr(0, 2);
	string month = hiredate.substr(3, 2);
	string year = hiredate.substr(6, 4);
	return year + month + day;
}

void Delete_Closed_Accounts_And_Store_Them(customer*& customers, int& CustomerCount, customer*& archived, int& ArchivedCount, int& ArchivedCapacity) {
	int i = 0;
	while (i < CustomerCount) {

		if (ArchivedCount == ArchivedCapacity)
		{
			NewCustomerArray(archived, ArchivedCapacity, ArchivedCount);
		}

		if (customers[i].Status == "Closed") {

			archived[ArchivedCount] = customers[i];
			ArchivedCount++;

			for (int j = i; j < CustomerCount - 1; j++) {
				customers[j] = customers[j + 1];
			}

			CustomerCount--;
		}
		else {
			i++;
		}
	}

	cout << "You have successfuly deleted all closed accounts and archived them in the archived accounts setion.\n";
}

void Display_Archived_Accounts(customer* archived, int ArchivedCount) {
	if (ArchivedCount == 0) {
		cout << "No arhived customers.\n";
		return;
	}
	cout << "\n---------- Archived Accounts ----------\n";
	for (int i = 0; i < ArchivedCount; i++) {
		PrintCustomer(archived[i]);
	}
}
void Manage_Loan_Requests(Queue& Q, customer* customers, int CustomerCount) {
	if (IsEmpty(Q)) {
		cout << "No loan requests to manage.\n";
		return;
	}
	int i = 1;
	while (!IsEmpty(Q)) {
		loan current_request = FrontElement(Q);
		int customer_account_number_having_the_loan_request = current_request.Account_Holder_Number;
		cout << "Processing Loan Request number  " << i << ":\n"
			<< "Type: " << current_request.Loan_Type << "\n"
			<< "Principal Amount: " << current_request.Principle_Amount << "\n"
			<< "Start Date: " << current_request.Start_Date << "\n"
			<< "End Date: " << current_request.End_Date << "\n";
		string decision;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		do {
			cout << "Approve this loan request? (Yes or No): ";
			getline(cin, decision);
		} while ((decision != "Yes") && (decision != "No"));

		if (decision == "Yes") {
			double interest_rate_to_approve = 0.0;
			string input;
			while (true) {
				cout << "Please enter the interest rate of this loan (%) : ";
				cin >> input;
				if (!input.empty() && input.back() == '%')
					input.pop_back();

				try {
					interest_rate_to_approve = stod(input);
				}
				catch (...) {
					cout << "Invalid format. Please enter a number like 5 or 5%.\n";
					continue;
				}

				if (interest_rate_to_approve < 0 || interest_rate_to_approve > 20) {
					cout << "The interest rate should be between 0% and 20%.\n";
					continue;
				}

				current_request.Interest_Rate = interest_rate_to_approve;
				int j = 0;
				while (j < CustomerCount) {
					if (customers[j].Account_Number == customer_account_number_having_the_loan_request) {
						current_request.Loan_Status = "Active";
						insert(customers[j].Loan_List, current_request, customers[j].Loan_List.size + 1);
						Dequeue(Q);
						cout << "Loan request approved and added to customer's loan list.\n";
						return;
					}
					j++;
				}
			}
		}
		else {
			cout << "Loan request denied and deleted .\n";
			Dequeue(Q);
		}
		i++;
	}
}

void Display_List_Of_Loans_For_Specific_Customer(customer* customers, int CustomerCount) {
	if (CustomerCount == 0) {
		cout << "There's no existant customers\n";
		return;
	}
	else {
		int account_number_to_display_its_loan_list = 0, p;
		bool ValidAccountNumber = false;
		do {
			cout << "Enter the customer's Account Number to display its loan list: " << endl;
			cin >> account_number_to_display_its_loan_list;
			if (cin.fail()) {
				cout << "Invalid input. Please enter numbers only.\n";
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				ValidAccountNumber = false;
				continue;
			}
			if (!VerifyExistingAccountNumber(account_number_to_display_its_loan_list, customers, CustomerCount)) {
				ValidAccountNumber = false;
				continue;
			}
			p = FindCustomer(customers, account_number_to_display_its_loan_list, CustomerCount);
			if ((p == -1) && (VerifyExistingAccountNumber(account_number_to_display_its_loan_list, customers, CustomerCount))) {
				cout << "Customer not found. Please make sure of the Account Number.\n";
				ValidAccountNumber = false;
			}
			else {
				ValidAccountNumber = true;
			}
		} while (!VerifyExistingAccountNumber(account_number_to_display_its_loan_list, customers, CustomerCount));
		Display_Loan_List(customers[p]);
	}
}
void AddCustomer(customer*& customers, int& CustomerCount, int& Customer_Capacity) {
	if (CustomerCount == Customer_Capacity) {
		NewCustomerArray(customers, Customer_Capacity, CustomerCount);
	}
	customer c;
	do {
		cout << "Enter the account number of the customer:" << endl;
		cin >> c.Account_Number;

		if (cin.fail()) {
			cout << "Invalid input. Please enter numbers only.\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			continue;
		}

		cin.ignore(numeric_limits<streamsize>::max(), '\n');

	} while (!(VerifyAccountNumber(c.Account_Number, customers, CustomerCount)));

	do {
		cout << "Enter the IBAN of the customer:" << endl;
		cin >> c.IBAN;

		if (cin.fail()) {
			cout << "Invalid input. Please enter numbers only.\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			continue;
		}

		cin.ignore(numeric_limits<streamsize>::max(), '\n');

	} while (!VerifyIBAN(c.IBAN));

	do {
		cout << "Enter the the branch code of the customer:" << endl;
		cin >> c.Branch_Code;

		if (cin.fail()) {
			cout << "Invalid input. Please enter valid input.\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			continue;
		}

		cin.ignore(numeric_limits<streamsize>::max(), '\n');

	} while (!VerifyBranchCode(c.Branch_Code));

	do {
		cout << "Enter the Account holder name of the customer:" << endl;
		getline(cin, c.Account_Holder_Name);
	} while (!VerifyAccountHolderName(c.Account_Holder_Name));

	do {
		cout << "Enter the Opening date of the customer account:" << endl;
		getline(cin, c.Opening_date);
	} while (!VerifyOpeningDate(c.Opening_date));

	do {
		cout << "Enter the status of the customer account:" << endl;
		getline(cin, c.Status);
	} while (!VerifyStatus(c.Status));

	do {
		cout << "Enter the Balance of the customer account:" << endl;
		cin >> c.Balance;

		if (cin.fail()) {
			cout << "Invalid input. Please enter a valid number.\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			continue;
		}

	} while (!VerifyBalance(c.Balance));

	do {
		cout << "Enter the PIN of the customer:" << endl;
		cin >> c.PIN;

		if (cin.fail()) {
			cout << "Invalid input. Please enter numbers only.\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			continue;
		}

	} while (!VerifyPIN(c.PIN));

	c.Loan_List = create_List();
	c.Transaction_Stack.Top = 0;
	customers[CustomerCount] = c;
	CustomerCount++;
}


void ChangeCustomerAccountStatus(customer* customers, int CustomerCount) {
	if (CustomerCount == 0) {
		cout << "There are no existing customers.\n";
		return;
	}

	int accountNumber;
	int index = -1;


	do {
		cout << "Enter the customer's Account Number to change its status: ";
		cin >> accountNumber;


		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid input. Please enter a numeric 6-digit account number.\n";
			continue;
		}


		if (!VerifyExistingAccountNumber(accountNumber, customers, CustomerCount)) {
			cout << "Account number not found or invalid. Please enter a valid existing 6-digit account number.\n";
			continue;
		}

		index = FindCustomer(customers, accountNumber, CustomerCount);
		if (index == -1) {
			cout << "Customer not found. Please make sure of the Account Number.\n";
		}

	} while (index == -1);


	string newStatus;
	do {
		cout << "Enter the new account status ('Active', 'Inactive', or 'Closed'): ";
		cin >> newStatus;

		if (!VerifyStatus(newStatus)) {
			cout << "Invalid status. Please enter 'Active', 'Inactive', or 'Closed'.\n";
		}

	} while (!VerifyStatus(newStatus));


	customers[index].Status = newStatus;
	cout << "Customer account status changed successfully!\n";
}

void Change_Status_Of_A_Loan(customer* customers, int CustomerCount, CompletedLoanList* completed_loans) {
	int loanID;
	do {
		cout << "Enter a loan ID: ";
		cin >> loanID;

		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid input. Please enter a numeric Loan ID.\n";
			continue;
		}

		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		if (!VerifyLoanID(loanID)) {
			cout << "Invalid Loan ID format. Please enter a valid 6-digit Loan ID.\n";
		}

	} while (!VerifyLoanID(loanID));

	int i = 0;
	while (i < CustomerCount) {
		node* current = customers[i].Loan_List.head;
		while (current) {
			if (current->data.Loan_ID == loanID) {
				string newStatus;
				do {
					cout << "Enter the new loan status: " << endl;
					cin >> newStatus;
				} while (!VerifyLoanStatus(newStatus));
				current->data.Loan_Status = newStatus;
				Move_Single_Completed_Loan_for_a_single_customer(current->data, completed_loans, customers, CustomerCount); // Pass customers instead of &customers[i]
				cout << "Loan status changed successfully" << endl;
				return;
			}
			current = current->next;
		}
		i++;
	}
	cout << "Loan with ID " << loanID << " not found." << endl;
}
void Move_Single_Completed_Loan_for_a_single_customer(const loan& Completed_Loan, CompletedLoanList* L, customer* customers, int CustomerCount)
{
	if (Completed_Loan.Loan_Status != "Completed")
		return;

	// STEP 1: Insert into completed list
	Insert_Completed_Loan(L, Completed_Loan, L->size + 1);

	// STEP 2: Find which customer has this loan
	int customerIndex = -1;
	int loanPos = -1;

	for (int i = 0; i < CustomerCount; i++) {
		loanPos = Find_Loan_Position(&customers[i].Loan_List, Completed_Loan);
		if (loanPos != -1) {
			customerIndex = i;
			break;
		}
	}

	if (customerIndex == -1) {
		cout << "ERROR: Loan not found in ANY customer list\n";
		return;
	}

	// STEP 3: Remove it from the customer's loan list
	removeAt(&customers[customerIndex].Loan_List, loanPos);
}

int Find_Loan_Position(list* L, const loan& target_loan) {
	node* current = L->head;     // LOCAL POINTER (not global!)
	int position = 1;

	while (current) {
		if (current->data.Loan_ID == target_loan.Loan_ID) {
			return position;
		}
		current = current->next;
		position++;
	}
	return -1;
}
void Move_Completed_Loans_for_a_single_customer(customer& c, CompletedLoanList* completed_loans) {

	node* current = c.Loan_List.head;
	int pos = 1;

	while (current) {
		node* nextNode = current->next;

		if (current->data.Loan_Status == "Completed") {

			Insert_Completed_Loan(completed_loans, current->data, completed_loans->size + 1);
			removeAt(&c.Loan_List, pos);
		}
		else {
			pos++;
		}
		current = nextNode;

	}
}

void Move_All_Completed_Loans(customer* customers, int CustomerCount, CompletedLoanList* CompletedLoansList) {
	for (int i = 0; i < CustomerCount; i++) {
		Move_Completed_Loans_for_a_single_customer(customers[i], CompletedLoansList);
	}
	cout << "Completed loans moved from all customers.\n";
}


void Finalize_Day(customer* customers, int CustomerCount, DailyTransactionsLogList* DailyLogList) {
	string current_date = GetTodayDate();
	string choice;
	cin.ignore();

	do {
		cout << " are you sure you want to finalize the day? This action will copy all daily transactions into the Daily Log List and clear all customers' transaction stacks. (Yes/No): ";
		getline(cin, choice);
		if ((choice != "Yes") && (choice != "No")) {
			cout << "Invalid input. Please enter 'Yes' or 'No'.\n";
		}
	} while ((choice != "Yes") && (choice != "No"));
	if (choice == "No") return;
	else {
		cout << "Finalizing the day: " << current_date << "...\n";
		for (int i = 0; i < CustomerCount; i++) {
			while (!IsEmpty(customers[i].Transaction_Stack)) {
				transaction t = Pop(customers[i].Transaction_Stack);
				Insert_Completed_Transaction(DailyLogList, t, DailyLogList->size + 1);
			}
		}
		cout << "All daily transactions have been copied into the Log List successfully.\n";
	}
}

//-----------------------------------------------INTERFACE FUNTION--------------------------------------------------


void employee_interface(Employee*& employees, int& EmployeeCount, int& capacity, customer*& customers, int& CustomerCount, int& Customer_Capacity, customer*& archived, int& ArchivedCount, int& Archived_Capacity, CompletedLoanList& CompletedLoansList, Queue* Q, DailyTransactionsLogList* Daily_Transactions_Log_List)
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
		cout << "11. Delete all accounts whose status is closed\n";
		cout << "12. Display archived accounts\n";
		cout << "13. Display the list of loans for a specific customer\n";
		cout << "14. Change the status of a loan\n";
		cout << "15. Delete Loans Whose Status is completed\n";
		cout << "16. Display Completed Loans\n";
		cout << "17. Manage Loan Requests\n";
		cout << "18. Finalize the Day\n";
		cout << "19. View Statistics\n";
		cout << "0. Return to Home\n";
		cout << "============================================================================================" << endl;
		cout << "\n";
		cout << "Please Choose an operation : ";
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
		case 11:
			Delete_Closed_Accounts_And_Store_Them(customers, CustomerCount, archived, ArchivedCount, Archived_Capacity);
			break;
		case 12:
			Display_Archived_Accounts(archived, ArchivedCount);
			break;
		case 13:
			Display_List_Of_Loans_For_Specific_Customer(customers, CustomerCount);
			break;
		case 14:
			Change_Status_Of_A_Loan(customers, CustomerCount, &CompletedLoansList);
			break;
		case 15:
			Move_All_Completed_Loans(customers, CustomerCount, &CompletedLoansList);
			break;
		case 16:
			Display_Completed_Loans(CompletedLoansList);
			break;
		case 17:
			Manage_Loan_Requests(*Q, customers, CustomerCount);
			break;
		case 18:
			Finalize_Day(customers, CustomerCount, Daily_Transactions_Log_List);
			break;
		case 19:
			statistics_interface(customers, CustomerCount, employees, EmployeeCount, ArchivedCount);
			break;
		case 0:
			cout << "Returning.......\n";
			break;
		default:
			cout << "Invalid option. Try again.\n";
		}

	} while (employee_choice != 0);

}

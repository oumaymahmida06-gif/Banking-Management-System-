#include <iostream>
#include "Customer_Methods.h"
#include "Employee_Methods.h"
#include "TransactionMeths.h"
#include "DoublyLinkedListMeths.h"
#include "SinglyLinkedListMeths.h"
#include "QueueMeths.h"
using namespace std;

//------------------------LOGIN--------------------------

int CheckCustomerLogin(customer* customers, int CustomerCount) {
	int AccountNumber, pin;
	cout << "Enter Account Number: ";
	cin >> AccountNumber;
	cout << "\nEnter PIN: ";
	cin >> pin;
	for (int i = 0; i < CustomerCount; i++) {
		if (customers[i].Account_Number == AccountNumber && customers[i].PIN == pin) {
			cout << "\nLogin successful!\n";
			return i;
		}
	}
	cout << "\nLogin failed. Please check your account informations.\n";
	return -1;
}
//------------------------ARRAY--------------------------

//DYNAMIC ALLOCATION:
void NewCustomerArray(customer*& customers, int& Customer_Capacity, int CustomerCount) {
	int NewCustomerSize = Customer_Capacity * 2;
	customer* NewCustomerArray = new customer[NewCustomerSize];
	for (int i = 0; i < CustomerCount; i++) {
		NewCustomerArray[i] = customers[i];
	}
	delete[] customers;
	customers = NewCustomerArray;
	Customer_Capacity = NewCustomerSize;
}

int FindCustomer(customer* customers, int number, int CustomerCount) {
	for (int i = 0; i < CustomerCount; i++) {
		if (customers[i].Account_Number == number) {
			return i;
		}
	}
	return -1;
}
void PrintCustomer(const customer& c) {
	cout << "Account Number " << c.Account_Number << endl;
	cout << "Account Type: " << c.Account_Type << endl;
	cout << "IBAN: " << c.IBAN << endl;
	cout << "Branch Code: " << c.Branch_Code << endl;
	cout << "Account Holder Name: " << c.Account_Holder_Name << endl;
	cout << "Opening date: " << c.Opening_date << endl;
	cout << "Status: " << c.Status << endl;
	cout << "Balance: " << c.Balance << endl;
	cout << "PIN: " << c.PIN << endl;
	cout << "------------------------------------\n";
}

void DisplayCustomers(customer* customers, int CustomerCount) {
	if (CustomerCount == 0) {
		cout << "No customers to display.\n";
		return;
	}

	cout << "\n------ Customer List ------\n";

	for (int i = 0; i < CustomerCount; i++) {
		PrintCustomer(customers[i]);
	}
}

//------------------------VERIFICATIONS--------------------------

// for the customer :
bool isNumber(string str) {
	for (int i = 0; i < str.length(); i++) {
		if (!('0' <= str[i] && str[i] <= '9')) {
			return false;
		}
	}
	return true;
}
bool VerifyAccountNumber(int AccountNumber) {
	if (AccountNumber < 100000 || AccountNumber > 999999) {
		cout << "The account number should be a 6-digit number ." << endl;
		return false;
	}
	return true;
}
bool VerifyAccountType(string AccountType) {
	if (AccountType != "Savings" && AccountType != "Current" && AccountType != "Fixed Deposit") {
		cout << "Invalid account type. Please enter 'Savings', 'Current', or 'Fixed Deposit'." << endl;
		return false;
	}
	return true;
}
bool VerifyIBAN(int IBAN) {
	if (IBAN < 10000000 || IBAN > 99999999) {
		cout << "The IBAN should be an 8-digits number. " << endl;
		return false;
	}
	return true;
}
bool VerifyBranchCode(string BranchCode)
{
	char c1 = BranchCode[0], c2 = BranchCode[1];
	if (BranchCode.length() == 5 && isalpha(c1) && isupper(c1) && isalpha(c2) && isupper(c2))
	{
		for (int i = 2; i < BranchCode.length(); i++)
		{
			if (!isdigit(BranchCode[i]))
			{
				cout << "Invalid branch code. The first and second character must be followed by digits." << endl;
				return false;
			}
		}
		return true;
	}
	cout << "Invalid branch code. The branch code must follow this format : AB123." << endl;
	return false;
}
bool VerifyAccountHolderName(string AccountHolderName) {
	if (AccountHolderName.length() < 3) {
		cout << "The name must be at least 3 characters long.\n";
		return false;
	}
	if (!isupper(AccountHolderName[0])) {
		cout << "The first letter must be uppercase.\n";
		return false;
	}
	for (int i = 1; i < AccountHolderName.length(); i++) {
		if (!isalpha(AccountHolderName[i])) {
			cout << "The name must contain only alphabetical letters.\n";
			return false;
		}
		if (!islower(AccountHolderName[i])) {
			cout << "All letters except the first one must be lowercase.\n";
			return false;
		}
	}
	return true;
}
bool VerifyOpeningDate(string OpeningDate)
{
	if (OpeningDate.length() != 10 || OpeningDate[2] != '-' || OpeningDate[5] != '-')
	{
		cout << "Invalid opening date format. Please use DD-MM-YYYY." << endl;
		return false;
	}
	if (OpeningDate.substr(0, 2) < "01" || OpeningDate.substr(0, 2) > "31" || OpeningDate.substr(3, 2) < "01" || OpeningDate.substr(3, 2) > "12" || OpeningDate.substr(6, 4) < "1900")
	{
		cout << "Invalid opening date. Please ensure the date is valid." << endl;
		return false;
	}
	return true;
}
bool VerifyStatus(string Status)
{
	if (Status != "Active" && Status != "Inactive" && Status != "Closed")
	{
		cout << "Invalid status. Please enter 'Active', 'Inactive', or 'Closed'." << endl;
		return false;
	}
	return true;
}

bool VerifyBalance(double Balance)
{
	if (Balance < 0)
	{
		cout << "Invalid balance. Balance cannot be negative." << endl;
		return false;
	}
	return true;
}
bool VerifyPIN(int PIN)
{
	if (PIN < 1000 || PIN > 9999)
	{
		cout << "Invalid PIN. PIN should be a 4-digit number." << endl;
		return false;
	}
	return true;
}

// for the loans :

bool VerifyLoanID(int loanID) {
	if (loanID < 100000 || loanID > 999999) {
		cout << "The LOAN ID is a 6-digit number ." << endl;
		return false;
	}
	return true;
}
bool VerifyLoanStatus(string Status)
{
	if (Status != "Active" && Status != "Completed" && Status != "Overdue")
	{
		cout << "Invalid status. Please enter 'Active', 'Completed', or 'Overdue'." << endl;
		return false;
	}
	return true;
}
bool Verify_End_Date(string Start_Date, string End_Date) {
	if (End_Date.length() != 10 || End_Date[2] != '-' || End_Date[5] != '-')
	{
		cout << "Invalid opening date format. Please use DD-MM-YYYY." << endl;
		return false;
	}
	if (End_Date.substr(0, 2) < "01" || End_Date.substr(0, 2) > "31" || End_Date.substr(3, 2) < "01" || End_Date.substr(3, 2) > "12" || End_Date.substr(6, 4) < "1900")
	{
		cout << "Invalid opening date. Please ensure the date is valid." << endl;
		return false;
	}
	if (End_Date.substr(6, 4) < Start_Date.substr(6, 4)) {
		cout << "Invalid end date. Please ensure the end date is after the start date." << endl;
		return false;
	}
	if (End_Date.substr(6, 4) == Start_Date.substr(6, 4)) {
		if (End_Date.substr(3, 2) < Start_Date.substr(3, 2)) {
			cout << "Invalid end date. Please ensure the end date is after the start date." << endl;
			return false;
		}
		if (End_Date.substr(3, 2) == Start_Date.substr(3, 2)) {
			if (End_Date.substr(0, 2) <= Start_Date.substr(0, 2)) {
				cout << "Invalid end date. Please ensure the end date is after the start date." << endl;
				return false;
			}
		}
	}
	return true;
}


//------------------------TO USE FOR THE CUSTOMER--------------------------


void Display_Loan_List(const customer& c) {
	node* current = c.Loan_List.head;
	if (current == nullptr) {
		cout << "No loans found for this customer." << endl;
		return;
	}
	cout << "Loans for Customer Account Number: " << c.Account_Number << endl;
	while (current) {
		cout << "Loan ID : " << current->data.Loan_ID << endl;;
		cout << "Loan Type: " << current->data.Loan_Type << endl;
		cout << "Principle Amount: " << current->data.Principle_Amount << "TND" << endl;
		cout << "Interest Rate: " << current->data.Interest_Rate << endl;
		cout << "Amount paid: " << current->data.Amount_paid << "TND" << endl;
		cout << "Remaining Balance: " << current->data.Remaining_Balance << "TND" << endl;
		cout << "Start Date: " << current->data.Start_Date << endl;
		cout << "End Date: " << current->data.End_Date << endl;
		cout << "Loan Status: " << current->data.Loan_Status << endl;
		cout << "============================================================================================" << endl;
		current = current->next;
	}
}

void Submit_Loan_Request(customer& c, Queue& Q) {
	loan newLoan;
	newLoan.Account_Holder_Number = c.Account_Number;
	cout << "Enter Loan Type: ";
	cin.ignore();
	getline(cin, newLoan.Loan_Type);

	do {
		cout << "Enter Principle Amount: ";
		cin >> newLoan.Principle_Amount;
		if (newLoan.Principle_Amount < 0) {
			cout << "The Principle amount cannot be negative.\n";
		}
	} while (newLoan.Principle_Amount < 0);
	newLoan.Interest_Rate = 0.0;
	newLoan.Amount_paid = 0.0;
	newLoan.Remaining_Balance = newLoan.Principle_Amount;

	cin.ignore();

	do {
		cout << "Enter Start Date (DD-MM-YYYY): ";
		getline(cin, newLoan.Start_Date);
	} while (!VerifyOpeningDate(newLoan.Start_Date));

	do {
		cout << "Enter End Date (DD-MM-YYYY): ";
		getline(cin, newLoan.End_Date);
	} while (!Verify_End_Date(newLoan.Start_Date, newLoan.End_Date));

	newLoan.Loan_Status = "Pending";

	Enqueue(Q, newLoan);
	cout << "Loan request submitted successfully!" << endl;
}

int Withdraw_Money(customer& c) {
	int choice;
	double amount = 0.0;
	do {
		cout << "Enter amount to withdraw: " << endl;
		cout << "1. 10TND\n2. 20TND\n3. 50TND\n4. 100TND\n5. Other amount\n";
		cin >> choice;
		switch (choice) {
		case 1:
			amount = 10;
			break;
		case 2:
			amount = 20;
			break;
		case 3:
			amount = 50;
			break;
		case 4:
			amount = 100;
			break;
		case 5:
			cout << "Enter other amount: ";
			cin >> amount;
			break;
		default:
			cout << "Invalid choice." << endl;
			return 0;
		}

	} while (amount <= 0);
	if (c.Balance < amount) {
		cout << "Insufficient balance." << endl;
		cout << " Enter 0 to exit.";
		cin >> choice;
		if (choice == 0) {
			return 0;
		}
		return 0;
	}
	c.Balance -= amount;
	cout << "Withdrawal successful. New balance: " << c.Balance << " TND" << endl;
	Push(&c.Transaction_Stack, transaction{ rand() % 10000 + 1, c.Account_Number, "Withdrawal", amount, "Today" });
	return 1;
}

int Deposit_Money(customer& c, double amount) {
	if (amount <= 0) {
		cout << "Invalid deposit amount." << endl;
		return 0;
	}
	c.Balance += amount;
	cout << "Deposit successful. New balance: " << c.Balance << " TND" << endl;
	Push(&c.Transaction_Stack, transaction{ rand() % 10000 + 1, c.Account_Number, "Deposit", amount, "Today" });
	return 1;
}

void Display_Transactions(const customer& c) {
	if (IsEmpty(c.Transaction_Stack)) {
		cout << "No transactions to display." << endl;
		return;
	}
	cout << "Today's Transactions for Account Number: " << c.Account_Number << endl;
	DisplayStack(c.Transaction_Stack);
}

void Undo_Last_Transaction(customer& c) { 
	if (IsEmpty(c.Transaction_Stack)) {
		cout << "No transactions to undo." << endl;
		return;
	}
	transaction lastTransaction = Pop(&c.Transaction_Stack);
	if (lastTransaction.Transaction_Type == "Withdrawal") {
		c.Balance += lastTransaction.Transaction_Amount;
		cout << "Last withdrawal transaction undone. New balance: " << c.Balance << " TND" << endl;
	}
	else if (lastTransaction.Transaction_Type == "Deposit") {
		c.Balance -= lastTransaction.Transaction_Amount;
		cout << "Last deposit transaction undone. New balance: " << c.Balance << " TND" << endl;
	}
	else {
		cout << "Unknown transaction type." << endl;
	}
}

//------------------------FOR EMPLOYEE INTERFACE--------------------------

void AddCustomer(customer*& customers, int& CustomerCount, int& Customer_Capacity) {
	if (CustomerCount == Customer_Capacity) {
		NewCustomerArray(customers, Customer_Capacity, CustomerCount);
	}
	customer c;
	do {
		cout << "Enter the account number of the customer:" << endl;
		cin >> c.Account_Number;
		cin.ignore();
	} while (!(VerifyAccountNumber(c.Account_Number)));
	do {
		cout << "Enter the account type of the customer:" << endl;
		getline(cin, c.Account_Type);
	} while (!(VerifyAccountType(c.Account_Type)));

	do {
		cout << "Enter the IBAN of the customer:" << endl;
		cin >> c.IBAN;
		cin.ignore();
	} while (!VerifyIBAN(c.IBAN));
	do {
		cout << "Enter the the branch code of the customer:" << endl;
		cin >> c.Branch_Code;
		cin.ignore();
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
	} while (!VerifyBalance(c.Balance));

	do {
		cout << "Enter the PIN of the customer:" << endl;
		cin >> c.PIN;
	} while (!VerifyPIN(c.PIN));
	c.Loan_List = create_List();
	c.Transaction_Stack.Top = 0;
	customers[CustomerCount] = c;
	CustomerCount++;
}
void ChangeCustomerAccountStatus(customer* customers, int CustomerCount) {
	if (CustomerCount == 0) {
		cout << "There's no existant customers\n";
		return;
	}
	else {
		int account_number_to_change_its_status = 0, p;
		bool ValidAccount = false;
		do {
			cout << "Enter the customer's Account Number to change its status: " << endl;
			cin >> account_number_to_change_its_status;
			if (!VerifyAccountNumber(account_number_to_change_its_status)) {
				ValidAccount = false;
			}
			p = FindCustomer(customers, account_number_to_change_its_status, CustomerCount);
			if ((p == -1) && (VerifyAccountNumber(account_number_to_change_its_status))) {
				cout << "Customer not found. Please make sure of the Account Number.\n";
				ValidAccount = false;
			}
			else {
				ValidAccount = true;
			}
		} while (!ValidAccount);
		p = FindCustomer(customers, account_number_to_change_its_status, CustomerCount);
		string newStatus;
		bool ValidStatus = false;
		do {
			cout << "Enter the new account status: " << endl;
			cin >> newStatus;
			if (!VerifyStatus(newStatus)) {
				ValidStatus = false;
			}
			else {
				ValidStatus = true;
			}
		} while (!ValidStatus);
		customers[p].Status = newStatus;
		cout << "Customer account status changed successfully!\n";
	}
}
void Change_Status_Of_A_Loan(customer* customers, int CustomerCount) {
	int loanID;
	do {
		cout << "Enter a loan ID: " << endl;
		cin >> loanID;
	} while (!VerifyLoanID(loanID));

	int i = 0;
	while (i< CustomerCount){
		node* current = customers[i].Loan_List.head;
		while (current) {
			if (current->data.Loan_ID == loanID) {
				string newStatus;
				do {
					cout << "Enter the new loan status: " << endl;
					cin >> newStatus;
				} while (!VerifyLoanStatus(newStatus));
				current->data.Loan_Status = newStatus;
				cout << "Loan status changed successfuly" << endl;
				return;
			}
			current = current->next;
		}
		i++;
	}
	cout << "Loan with ID " << loanID << " not found." << endl;
}

vvoid Move_Completed_Loans_for_a_single_customer(customer& c, CompletedLoanList* completed_loans) {

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
		current = current->next;

	}
}
void Move_All_Completed_Loans(customer* customers, int CustomerCount, CompletedLoanList* CompletedLoansList){
	for (int i = 0; i < CustomerCount; i++) {
		Move_Completed_Loans_for_a_single_customer(customers[i], CompletedLoansList);
	}
	cout << "Completed loans moved from all customers.\n";
}



//------------------------------------------------INTERFACE FUNCTION-------------------------------------------------------

void customer_interface(customer*& customers, int& CustomerCount, int& Customer_Capacity, Queue& Q) {
	int customer_choice = -1, operation_choice = -1;
	int c;

	do {
		c = CheckCustomerLogin(customers, CustomerCount);
	} while (c == -1);
	cout << "============================================================================================" << endl;


	if (c != -1) {
		do {
			cout << "============================================================================================" << endl;
			cout << "============================================================================================" << endl;
			cout << "                    Welcome to the CUSTOMER MANAGEMENT SYSTEM" << endl;
			cout << "============================================================================================" << endl;
			cout << "============================================================================================" << endl;
			cout << "                            1.View loan list. " << endl;
			cout << "                            2.Submit loan request" << endl;
			cout << "                            3.Perform transaction." << endl;
			cout << "                            4.View list of today's transactions." << endl;
			cout << "                            5.Undo last transaction." << endl;
			cout << "                            0.Return to Home." << endl;
			cout << "============================================================================================" << endl;
			cout << "                            Enter your choice: ";
			cin >> customer_choice;

			switch (customer_choice)
			{
			case 1:
				cout << "============================================================================================" << endl;
				Display_Loan_List(customers[c]);
				break;
				cout << "============================================================================================" << endl;

			case 2:
				cout << "============================================================================================" << endl;
				Submit_Loan_Request(customers[c], Q);
				break;
				cout << "============================================================================================" << endl;

			case 3:
				cout << "============================================================================================" << endl;

				do
				{
					cout << "Choose an operation to perform: " << endl;
					cout << "                            1.Withdraw money. " << endl;
					cout << "                            2.Deposit money. " << endl;
					cout << "                            0.Return to Home. " << endl;
					cin >> operation_choice;
					switch (operation_choice)
					{
					case 1:
						Withdraw_Money(customers[c]);
						break;
					case 2:
						cout << "                            Enter amount to deposit: ";
						double depositAmount;
						cin >> depositAmount;
						Deposit_Money(customers[c], depositAmount);
						break;
					case 0:
						cout << "                            Returning...." << endl;
						break;
					default:
						cout << "--------------------------------------------------------------------------------------------" << endl;
						cout << "                            Invalid choice. Please try again." << endl;
						cout << "============================================================================================" << endl;
					}
				} while (operation_choice != 0);
				cout << "============================================================================================" << endl;
				break;

			case 4:
				cout << "============================================================================================" << endl;
				Display_Transactions(customers[c]);
				cout << "============================================================================================" << endl;
				break;

			case 5:
				cout << "============================================================================================" << endl;
				Undo_Last_Transaction(customers[c]);
				cout << "============================================================================================" << endl;
				break;
			case 0:
				cout << "Returning...." << endl;
				break;

			default:
				cout << "--------------------------------------------------------------------------------------------" << endl;
				cout << "Invalid choice. Please try again." << endl;
				cout << "============================================================================================" << endl;
			}
		} while (customer_choice != 0);
	}
}

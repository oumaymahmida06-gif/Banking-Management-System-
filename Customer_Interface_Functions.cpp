#include <iostream>
#include "Customer_Methods.h"
using namespace std;


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

	customers[CustomerCount] = c;
	CustomerCount++;
}
bool CheckCustomerLogin(customer* customers, int CustomerCount) {
	string AccountNumber, pin;
	bool test = false;
	do {
		cout << "Enter Account Number: ";
		cin >> AccountNumber;
		cout << "Enter PIN: ";
		cin >> pin;

		for (int i = 0; i < CustomerCount; i++) {
			if (customers[i].Account_Number == AccountNumber && customers[i].PIN == stoi(pin)) {
				cout << "Login successful!\n";
				return true;

			}
		}
		cout << "Login failed. Please check your credentials.\n";
		return false;
	} while (!test);
}
bool isNumber(string str) {
	for (int i = 0; i<str.length(); i++) {
		if (!('0' <= str[i] && str[i] <='9')) {
			return false;
		}
	}
	return true;
}
bool VerifyAccountNumber(string AccountNumber) {
	if (isNumber(AccountNumber) == false) {
		cout << "The account number should be composed only of digits "<< endl;
		return false;
	}
	else if (AccountNumber.length()!=6) {
		cout << "The account number should be between 100000 and 999999 " << endl;
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
		cout << "The IBAN should be between 10000000 and 99999999 " << endl;
		return false;
	}
	return true;
}
bool VerifyBranchCode(string BranchCode)
{
	char c1= BranchCode[0], c2 = BranchCode[1];
	if (BranchCode.length() != 5 && isalpha(c1) && isupper(c1) && isalpha(c2) && isupper(c2))
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
	cout << "Invalid branch code. The first and second character must be uppercase letters followed by digits." << endl;
	return false;
}
bool VerifyAccountHolderName(string AccountHolderName)
{
	if (!isupper(AccountHolderName[0])) {
		cout << "Invalid account holder name. It should start with an uppercase letter." << endl;
		return false;
	}
	for (int i = 0; i < AccountHolderName.length(); i++)
	{
		if (!isalpha(AccountHolderName[i]) && AccountHolderName[i] != ' ')
		{
			cout << "Invalid account holder name. It should contain only alphabetic characters and spaces." << endl;
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



















bool isEmpty(const list& L) {
	return L.size == 0;
}
bool isFull(const list& L) {
	node* test = new (nothrow) node;
	if (!test) return true;
	delete test;
	return false;
}
int listSize(const list& L) {
	return L.size;
}
node* create_Node(const loan& value) {
    node* Node = new (nothrow) node;
    if (!Node) {
        cout << "\nMemory allocation failed for node\n";
        return nullptr;
    }
    // Affectation explicite (requiert que node::data soit de type `loan`)
    Node->data = value;
    Node->next = nullptr;
    Node->prev = nullptr;
    return Node;
}

void destroy_Node(node* Node) {
	delete Node;
}
list create_List() {
	return list{ nullptr, nullptr, 0 };
};
void destroy_List(list* L) {
	if (!L) return;
	node* current = L->head;
	while (current) {
		node* temp = current;
		current = current->next;
		destroy_Node(temp);
	}
	L->head = nullptr;
	L->size = 0;
}

int insert(list* L, loan Loan, int pos) {
	if (!L) return 0;
	if (pos < 1 || pos > L->size + 1) {
		cout << "\nInvalid position";
		return 0;
	}
	node* n = create_Node(Loan);
	if (!n) return 0;
	if (isEmpty(*L)) {
		L->head = n;
		L->tail = n;
	}
	else if (pos == 1) {
		n->next = L->head;
		L->head->prev = n;
		L->head = n;
	}
	else if (pos == L->size + 1) {
		n->prev = L->tail;
		L->tail->next = n;
		L->tail = n;
	}
	else {
		node* prev = nullptr;
		node* current = L->head;
		for (int i = 1; i < pos; i++) {
			prev = current;
			current = current->next;
		}
		prev->next = n;
		n->prev = prev;
		n->next = current;
		current->prev = n;
	}
	L->size++;
	return 1;
}
int removeAt(list* L, int pos) {
	if (!L || isEmpty(*L)) {
		cout << "\nList is empty";
		return 0;
	}
	if (pos < 1 || pos > L->size) {
		cout << "\nInvalid position";
		return 0;
	}
	node* current;
	if (L->size == 1) {
		current = L->head;
		L->head = nullptr;
		L->tail = nullptr;
	}
	else if (pos == 1) {
		current = L->head;
		L->head = L->head->next;
		L->head->prev = nullptr;
	}
	else if (pos == L->size) {
		current = L->tail;
		L->tail = L->tail->prev;
		L->tail->next = nullptr;
	} return 0;
}
loan get_Element(const list& L, int pos) {
	if (isEmpty(L)) {
		cerr << "\nList is empty\n";
		return loan{};
	}

	if (pos < 1 || pos > L.size) {
		cerr << "\nInvalid position\n";
		return loan{};
	}
	node* current = L.head;
	for (int i = 1; i < pos; i++) {
		current = current->next;
	}
	return current->data; 
}
void display_Loan_List(const list& L) {
	if (isEmpty(L)) {
		cout << "List is empty\n";
		return;
	}
	node* current = L.head;
	while (current) {
		cout << "Loan ID : "<< current->data.Loan_ID
			 << "Loan Type" << current->data.Loan_Type
			<< "Principle Amount" << current->data.Principle_Amount
			<< "Interest Rate :" << current->data.Interest_Rate
			<< "Amount paid :" << current->data.Amount_paid
			<< "Remaining Balance :"<<current->data.Remaining_Balance
			<< "Start Date :" << current->data.Start_Date
			<< "End Date : " << current->data.End_Date
			<< "Loan Status : " << current->data.Loan_Status
			<< " -> ";
		current = current->next;
	}
	cout << "NULL\n";
}
list CopyList(const list& L) {
	list newList = create_List();
	node* current = L.head;
	node* tail = nullptr;

	while (current) {
		node* n = create_Node(current->data);
		if (!n) {
			cerr << "\nMemory allocation failed while copying\n";
			destroy_List(&newList);
			return create_List();
		}
		if (!newList.head) {
			newList.head = n;
			tail = n;
		}
		else {
			tail->next = n;
			tail = n;
		}
		current = current->next;
	}
	newList.size = L.size;
	return newList;
};


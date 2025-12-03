#pragma once
#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <string>
#include "DoublyLinkedList.h"
#include "SinglyLinkedList.h"
#include "Stack.h"
using namespace std;

struct customer {
	int Account_Number = 000000;
	string Account_Type;
	int IBAN = 0;
	string Branch_Code;
	string Account_Holder_Name;
	string Opening_date;
	string Status;
	double Balance = 0.0;
	int PIN = 0;
	list Loan_List;
	Stack Transaction_Stack;
	bool Last_transaction_undone = false;
};

#endif

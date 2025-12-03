#include <iostream>
#include "TransactionMeths.h"
#include "Customer_Methods.h"
using namespace std;

Stack* CreateStack() {
	Stack* S = new (nothrow) Stack;

	if (!S) {
		cout << "\n Error: unable to allocate memory";
	}
	else {
		S->Top = 0;
	}
	return S;
}

void DestroyStack(Stack* S) {
	delete S;
}

void DisplayStack(const Stack& S) {
	for (int i = S.Top; i >= 1; i--) {
		cout << " the transaction ID is :" << S.transactions[i].Transaction_ID
			<< " \nthe Account Number is :" << S.transactions[i].Account_Number
			<< " \nthe Transaction Type is :" << S.transactions[i].Transaction_Type
			<< " \nthe transaction amount is : " << S.transactions[i].Transaction_Amount
			<< " \nthe Transaction Date is :" << S.transactions[i].Transaction_Date << endl;
	}
	cout << endl;
}

bool IsEmpty(const Stack& S) {
	return (S.Top == 0);
}

bool IsFull(const Stack& S) {
	return S.Top >= Max; // Top is count of elements (0..Max)
}

int StackSize(const Stack& S) {
	return S.Top;
}

int Push(Stack* S, transaction e) {  // add element to the top 
	if (IsFull(*S)) {
		cout << "\nStack is full";
		return 0;
	}
	else {
		S->Top++;
		S->transactions[S->Top] = e;
		return 1;
	}
}

transaction Pop(Stack* S) { // remove the top element from the stack
	transaction e = transaction{ 0,0,"",0.0,"" };
	if (IsEmpty(*S)) {
		cout << "\nStack is empty";
	}
	else {
		e = S->transactions[S->Top]; // get the top element
		S->Top--; // move the top index down
	}
	return e;
}

transaction Top(const Stack& S) { // look at the top element without removing it 
	transaction e = transaction{ 0,0,"",0.0,"" };

	if (IsEmpty(S)) {
		cout << "\nStack is empty";
	}
	else {
		e = S.transactions[S.Top];
	}

	return e;
}

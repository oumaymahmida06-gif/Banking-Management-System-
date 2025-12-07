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
		cout << "The transaction ID is : " << S.transactions[i].Transaction_ID<<"\n";
		cout << "The Transaction Type is : " << S.transactions[i].Transaction_Type << "\n";
		cout << "The transaction amount is : " << S.transactions[i].Transaction_Amount << "\n";
		cout << "The Transaction Date is :" << S.transactions[i].Transaction_Date << "\n";
	}
	cout << endl;
}

bool IsEmpty(const Stack& S) {
	return (S.Top == 0);
}

bool IsFull(const Stack& S) {
	return S.Top >= Max; 
}

int StackSize(const Stack& S) {
	return S.Top;
}

int Push(Stack* S, transaction e) {
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

transaction Pop(Stack& S) { 
	transaction e = transaction{ 0,0,"",0.0,"" };
	if (IsEmpty(S)) {
		cout << "\nStack is empty";
	}
	else {
		e = S.transactions[S.Top];
		S.Top--;
	}
	return e;
}

transaction Top(const Stack& S) { 
	transaction e = transaction{ 0,0,"",0.0,"" };

	if (IsEmpty(S)) {
		cout << "\nStack is empty";
	}
	else {
		e = S.transactions[S.Top];
	}

	return e;
}

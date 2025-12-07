#include <iostream>
#include "QueueMeths.h"
#include "Customer_Methods.h"
#include "DoublyLinkedListMeths.h"
using namespace std;

Queue* CreateQueue() {

	Queue* Q = new (nothrow) Queue;
	if (!Q) {
		cout << "\nError: unable to allocate memory";
	}
	else {
		Q->Front = 0;
		Q->Tail = 0;
	}
	return Q;
}
void DestroyQueue(Queue* Q) {
	delete Q;
}
void DisplayQueue(const Queue& Q) {
	if (IsEmpty(Q)) {
		cout << "Queue is empty.\n";
		return;
	}

	cout << "Loan requests in queue:\n";
	for (int i = Q.Front; i <= Q.Tail; ++i) {
		const loan& L = Q.Loan_Requests[i];
		cout << "Loan ID: " << L.Loan_ID
			<< " Type: " << L.Loan_Type
			<< " Principal Amount: " << L.Principle_Amount
			<< " Interest Rate: " << L.Interest_Rate
			<< " Amount paid: " << L.Amount_paid
			<< " Remaining Balance: " << L.Remaining_Balance
			<< " Start Date: " << L.Start_Date
			<< " End Date: " << L.End_Date
			<< " Loan Status: " << L.Loan_Status
			<< '\n';
	}
}

bool IsEmpty(const Queue& Q) {
	return (Q.Front == 0);
}
bool IsFull(const Queue& Q) {
	return (Q.Tail == QueueMax - 1);
}
int QueueSize(const Queue& Q) {
	if (IsEmpty(Q)) return 0;
	return Q.Tail - Q.Front + 1;
}
int Enqueue(Queue& Q, loan loan_request) {
	if (IsFull(Q)) {
		cout << "\nQueue is full";
		return 0;
	}
	if (IsEmpty(Q)) {
		Q.Front = 1;
		Q.Tail = 1;
	}
	else {
		Q.Tail++;
	}
	Q.Loan_Requests[Q.Tail] = loan_request;
	return 1;
}

bool Dequeue(Queue& Q) {
	if (IsEmpty(Q)) {
		cout << "\nQueue is empty";
		return false;
	}
	if (Q.Front == Q.Tail) {
		Q.Front = 0;
		Q.Tail = 0;
	}
	else {
		Q.Front++;
	}
	return true;
}
loan FrontElement(const Queue& Q) {
	if (IsEmpty(Q)) {
		cout << "\nQueue is empty";
		return { 0,0,"", 0.0, 0.0, 0.0, 0.0, "", "", "" };
	}
	return Q.Loan_Requests[Q.Front];
}

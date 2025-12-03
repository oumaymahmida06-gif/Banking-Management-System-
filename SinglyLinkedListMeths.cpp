#include <iostream>
#include "SinglyLinkedListMeths.h"
#include "Customer_Methods.h"
using namespace std;

CompletedLoanNode* Create_Completed_Loan_Node(loan completed_loan) {
	CompletedLoanNode* node = new (nothrow) CompletedLoanNode{ completed_loan, nullptr };
	if (!node) {
		cerr << "\nMemory allocation failed for node\n";
	}
	return node;
}
void Destroy_Completed_Loan_Node(CompletedLoanNode* node) {
	delete node;
}
CompletedLoanList Create_Completed_Loan_List() {
	return CompletedLoanList{ nullptr, 0 };
}
void Destroy_Completed_Loan_List(CompletedLoanList* L) {
	if (!L) return;
	CompletedLoanNode* current = L->head;
	while (current) {
		CompletedLoanNode* temp = current;
		current = current->next;
		Destroy_Completed_Loan_Node(temp);
	}
	L->head = nullptr;
	L->size = 0;
}
bool Completed_Loan_List_Is_Empty(const CompletedLoanList& L) {
	return L.size == 0;
}
bool Completed_Loan_List_Is_Full(const CompletedLoanList& L) {
	CompletedLoanNode* test = new (nothrow) CompletedLoanNode;
	if (!test) return true;
	delete test;
	return false;
}
int Completed_Loans_list_Size(const CompletedLoanList& L) {
	return L.size;
}
void Display_Completed_Loans(const CompletedLoanList& L) {
	if (!L.head) {
		cout << "There is no completed loans to display.\n";
		return;
	}
	cout << "-------- Completed Loans ---------\n";
	CompletedLoanNode* current = L.head;
	while (current) {
		cout << "Loan ID: " << current->data.Loan_ID << "\n"
			<< "Type: " << current->data.Loan_Type << "\n"
			<< "Principal: " << current->data.Principle_Amount << "\n"
			<< "Remaining: " << current->data.Remaining_Balance << "\n"
			<< "Start: " << current->data.Start_Date << "\n"
			<< "End :" << current->data.End_Date << "\n"
			<< "Status: " << current->data.Loan_Status << "\n"
			<< "----------------------------------\n";
		current = current->next;
	}
}
int Insert_Completed_Loan(CompletedLoanList* L, const loan& e, int pos) {
	if (!L) return 0;
	if (pos < 1 || pos > L->size + 1) {
		cerr << "\nInvalid position";
		return 0;
	}
	CompletedLoanNode* n = Create_Completed_Loan_Node(e);
	if (!n) return 0;
	if (pos == 1) {
		n->next = L->head;
		L->head = n;
	}
	else {
		CompletedLoanNode* prev = nullptr;
		CompletedLoanNode* current = L->head;
		for (int i = 1; i < pos - 1; i++) {
			prev = current;
			current = current->next;
		}
		prev->next = n;
		n->next = current;
	}

	L->size++;
	return 1;
}

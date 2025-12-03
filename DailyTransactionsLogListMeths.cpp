#include <iostream>
#include "DailyTransactionsLogListMeths.h"
#include "Customer_Methods.h"
using namespace std;

DailyTransactionNode* Create_Daily_Transaction_Node(transaction completed_transaction) {
	DailyTransactionNode* node = new (nothrow) DailyTransactionNode{ completed_transaction, nullptr };
	if (!node) {
		cerr << "\nMemory allocation failed for node\n";
	}
	return node;
}

void Destroy_Daily_Transaction_Node(DailyTransactionNode* node){
	delete node;
}
DailyTransactionsLogList Create_Daily_Transactions_Log_List() {
	return DailyTransactionsLogList{ nullptr, 0 };
}
void Destroy_Daily_Transactions_Log_List(DailyTransactionsLogList* L) {
	if (!L) return;
	DailyTransactionNode* current = L->head;
	while (current) {
		DailyTransactionNode* temp = current;
		current = current->next;
		Destroy_Daily_Transaction_Node(temp);
	}
	L->head = nullptr;
	L->size = 0;
}
bool Daily_Transactions_Log_List_Is_Empty(const DailyTransactionsLogList& L) {
	return L.size == 0;
}
bool Daily_Transactions_Log_List_Is_Full(const DailyTransactionsLogList& L) {
	DailyTransactionNode* test = new (nothrow) DailyTransactionNode;
	if (!test) return true;
	delete test;
	return false;
}
int Daily_Transactions_Log_List_Size(const DailyTransactionsLogList& L) {
	return L.size;
}
void Display_Daily_Transactions_Log_List(const DailyTransactionsLogList& L) {
	if (!L.head) {
		cout << "There is no transactions to display.\n";
		return;
	}
	cout << "-------- Daily Transactions Log ---------\n";
	DailyTransactionNode* current = L.head;
	while (current) {
		cout << "Transaction ID: " << current->data.Transaction_ID << "\n"
			<< "Account Number: " << current->data.Account_Number << "\n"
			<< "Type: " << current->data.Transaction_Type << "\n"
			<< "Amount: " << current->data.Transaction_Amount << "\n"
			<< "Date: " << current->data.Transaction_Date << "\n"
			<< "----------------------------------\n";
		current = current->next;
	}
}
int Insert_Completed_Transaction(DailyTransactionsLogList* L, transaction& e, int pos) {
	if (!L) return 0;
	if (pos < 1 || pos > L->size + 1) {
		cerr << "\nInvalid position";
		return 0;
	}
	DailyTransactionNode* n = Create_Daily_Transaction_Node(e);
	if (!n) return 0;
	if (pos == 1) {
		n->next = L->head;
		L->head = n;
	}
	else {
		DailyTransactionNode* prev = nullptr;
		DailyTransactionNode* current = L->head;
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

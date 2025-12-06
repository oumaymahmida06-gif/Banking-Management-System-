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

				// Remove trailing %
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
				int j=0;
				while( j< CustomerCount) {
					if (customers[j].Account_Number == customer_account_number_having_the_loan_request) {
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

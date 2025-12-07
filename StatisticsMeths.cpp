#include <iostream>
#include "StatisticsMeths.h"
using namespace std;

void Total_Number_of_Loans(const customer* customers, int CustomerCount) {
	int total_loans = 0;
	for (int i = 0; i < CustomerCount; i++) {
		total_loans += customers[i].Loan_List.size;
	}
	cout << "Total Number of Loans: " << total_loans << "\n";

}
void Number_of_Loans_By_Type(const customer* customers, int CustomerCount) {
	int Car_loan_count = 0;
	int Home_loan_count = 0;
	int Student_loan_count = 0;
	int Business_loan_count = 0;
	for (int i = 0; i < CustomerCount; i++) {
		node* current = customers[i].Loan_List.head;
		while (current) {
			if (current->data.Loan_Type == "Car") {
				Car_loan_count++;
			}
			else if (current->data.Loan_Type == "Home") {
				Home_loan_count++;
			}
			else if (current->data.Loan_Type == "Student") {
				Student_loan_count++;
			}
			else if (current->data.Loan_Type == "Business") {
				Business_loan_count++;
			}
			current = current->next;
		}
	}
	cout << "Number of Loans by Type:\n";
	cout << "Car Loans: " << Car_loan_count << "\n";
	cout << "Home Loans: " << Home_loan_count << "\n";
	cout << "Student Loans: " << Student_loan_count << "\n";
	cout << "Business Loans: " << Business_loan_count << "\n";
}
void Number_of_loans_by_status(const customer* customers, int CustomerCount, int ArchivedCount) {
	int Active_loan_count = 0;
	int Overdue_loan_count = 0;
	int Completed_loan_count = 0;
	for (int i = 0; i < CustomerCount; i++) {
		node* current = customers[i].Loan_List.head;
		while (current) {
			if (current->data.Loan_Status == "Active") {
				Active_loan_count++;
			}
			else if (current->data.Loan_Status == "Overdue") {
				Overdue_loan_count++;
			}
			else if (current->data.Loan_Status == "Completed") {
				Completed_loan_count++;
			}
			current = current->next;
		}
	}
	cout << "Number of Loans by Status:\n";
	cout << "Active Loans: " << Active_loan_count << "\n";
	cout << "Overdue Loans: " << Overdue_loan_count << "\n";
	cout << "Completed Loans: " << Completed_loan_count + ArchivedCount << "\n";

}
void Active_loans_within_a_specified_date_range(const customer* customers, int CustomerCount) {
	string start_date, end_date;
	do {
		cout << "Enter the start date (DD-MM-YYYY): \n";
		getline(cin, start_date);
		cout << "Enter the end date (DD-MM-YYYY):\n ";
		getline(cin, end_date);
	} while (!Verify_End_Date(start_date, end_date));
	cout << "Active Loans within the specified date range: from  " << start_date << "   to   " << end_date << "\n";
	for (int i = 0; i < CustomerCount; i++) {
		node* current = customers[i].Loan_List.head;
		while (current) {
			if (current->data.Loan_Status == "Active" && current->data.Start_Date >= start_date && current->data.End_Date <= end_date) {
				cout << "Customer Account Number: " << customers[i].Account_Number << "\n";
				cout << "Loan ID: " << current->data.Loan_ID << "\n";
				cout << "Loan Type: " << current->data.Loan_Type << "\n";
				cout << "Loan Status: " << current->data.Loan_Status << "\n";
				cout << "Principle Amount: " << current->data.Principle_Amount << "\n";
				cout << "Interest Rate: " << current->data.Interest_Rate << "\n";
				cout << "Amount Paid: " << current->data.Amount_paid << "\n";
				cout << "Remaining Balance: " << current->data.Remaining_Balance << "\n";
				cout << "Start Date: " << current->data.Start_Date << "\n";
				cout << "End Date: " << current->data.End_Date << "\n";
				cout << "-----------------------------------\n";
			}
			current = current->next;
		}
	}

}
void Customer_with_the_highest_number_of_loans(const customer* customers, int CustomerCount) {
	if (CustomerCount == 0) {
		cout << "No customers found.\n";
		return;
	}
	int max_loans = 0;
	int customer_index = -1;
	for (int i = 0; i < CustomerCount; i++) {
		if (customers[i].Loan_List.size > max_loans) {
			max_loans = customers[i].Loan_List.size;
			customer_index = i;
		}
	}
	if (max_loans == 0) {
		cout << "No loans found for any customer.\n";
		return;
	}
	if (customer_index != -1) {
		cout << "Customer with the highest number of loans:\n";
		cout << "Account Number: " << customers[customer_index].Account_Number << "\n";
		cout << "Account Holder Name: " << customers[customer_index].Account_Holder_Name << "\n";
		cout << "Number of Loans: " << max_loans << "\n";
	}

}
void Customer_with_the_highest_account_balance(const customer* customers, int CustomerCount) {
	if (CustomerCount == 0) {
		cout << "No customers found.\n";
		return;
	}
	double max_balance = customers[0].Balance;
	int customer_index = -1;
	for (int i = 0; i < CustomerCount; i++) {
		if (customers[i].Balance > max_balance) {
			max_balance = customers[i].Balance;
			customer_index = i;
		}
	}
	if (customer_index != -1) {
		cout << "Customer with the highest account balance:\n";
		cout << "Account Number: " << customers[customer_index].Account_Number << "\n";
		cout << "Account Holder Name: " << customers[customer_index].Account_Holder_Name << "\n";
		cout << "Account Balance: " << max_balance << " TND\n";
	}

}

void Customer_with_the_lowest_account_balance(const customer* customers, int CustomerCount) {
	if (CustomerCount == 0) {
		cout << "No customers found.\n";
		return;
	}
	double min_balance = customers[0].Balance;
	int customer_index = 0;
	for (int i = 1; i < CustomerCount; i++) {
		if (customers[i].Balance < min_balance) {
			min_balance = customers[i].Balance;
			customer_index = i;
		}
	}
	if (customer_index != -1) {
		cout << "Customer with the lowest account balance:\n";
		cout << "Account Number: " << customers[customer_index].Account_Number << "\n";
		cout << "Account Holder Name: " << customers[customer_index].Account_Holder_Name << "\n";
		cout << "Account Balance: " << min_balance << " TND\n";
	}

}

void Total_number_of_employees(const Employee* employees, int EmployeeCount) {
	if (EmployeeCount == 0) {
		cout << "No employees found.\n";
		return;
	}
	cout << "Total number of employees: " << EmployeeCount << "\n";
}

void Number_of_employees_per_bank_branch(const Employee* employees, int EmployeeCount) {
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
	cout << "\n============= Number of Employees per Bank Branch =============\n";
	int i = 0;
	while (i < EmployeeCount) {
		int CurrentBranch = BranchSort[i].Bank_Branch;
		int branch_employee_count = 0;
		while (i < EmployeeCount && BranchSort[i].Bank_Branch == CurrentBranch) {
			branch_employee_count++;
			i++;
		}
		cout << "Bank Branch " << CurrentBranch << ": " << branch_employee_count << " employees\n";
	}
	delete[] BranchSort;
}
void statistics_interface(const customer* customers, int CustomerCount, const Employee* employees, int EmployeeCount, int ArchivedCount) {
	char stats_choice;
	do {
		cout << "================== Statistics Menu ==================\n";
		cout << "1. Total Number of Loans\n";
		cout << "2. Number of Loans by Type\n";
		cout << "3. Number of Loans by Status\n";
		cout << "4. Active Loans within a Specified Date Range\n";
		cout << "5. Customer with the Highest Number of Loans\n";
		cout << "6. Customer with the Highest Account Balance\n";
		cout << "7. Customer with the Lowest Account Balance\n";
		cout << "8. Total Number of Employees\n";
		cout << "9. Number of Employees per Bank Branch\n";
		cout << "0. Exit Statistics Menu\n";
		do {
			cout << "Enter your choice: ";
			cin >> stats_choice;
			if (stats_choice < 0 || stats_choice > 9) {
				cout << "Invalid choice. Please try again.\n";
			}
		} while (stats_choice < 0 || stats_choice > 9);
		cin.ignore();
		switch (stats_choice) {
		case '1':
			Total_Number_of_Loans(customers, CustomerCount);
			break;
		case '2':
			Number_of_Loans_By_Type(customers, CustomerCount);
			break;
		case '3':
			Number_of_loans_by_status(customers, CustomerCount, ArchivedCount);
			break;
		case '4':
			Active_loans_within_a_specified_date_range(customers, CustomerCount);
			break;
		case '5':
			Customer_with_the_highest_number_of_loans(customers, CustomerCount);
			break;
		case '6':
			Customer_with_the_highest_account_balance(customers, CustomerCount);
			break;
		case '7':
			Customer_with_the_lowest_account_balance(customers, CustomerCount);
			break;
		case '8':
			Total_number_of_employees(employees, EmployeeCount);
			break;
		case '9':
			Number_of_employees_per_bank_branch(employees, EmployeeCount);
			break;
		case '0':
			cout << "Exiting Statistics Menu.\n";
			break;
		default:
			cout << "Invalid choice. Please try again.\n";
		}
	} while (stats_choice != '0');
}

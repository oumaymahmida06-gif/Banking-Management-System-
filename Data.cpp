#include <iostream>
#include "Data.h"
using namespace std;

void LoadDemoData(customer*& customers, int& CustomerCount, int& Customer_Capacity, Employee*& employees, int& EmployeeCount, int capacity)
{
	// ------------ CUSTOMER 0 ------------
	customers[0].Account_Number = 123456;
	customers[0].Account_Type = "Savings";
	customers[0].IBAN = 12345678;
	customers[0].Branch_Code = "AB123";
	customers[0].Account_Holder_Name = "John Doe";
	customers[0].Opening_date = "01-01-2020";
	customers[0].Status = "Active";
	customers[0].Balance = 1000.0;
	customers[0].PIN = 1234;
	customers[0].Loan_List = create_List();
	customers[0].Transaction_Stack.Top = 0;

	// ------------ CUSTOMER 1 ------------
	customers[1].Account_Number = 234567;
	customers[1].Account_Type = "Savings";
	customers[1].IBAN = 23456789;
	customers[1].Branch_Code = "TU227";
	customers[1].Account_Holder_Name = "Sarra Ali";
	customers[1].Opening_date = "01-01-2020";
	customers[1].Status = "Active";
	customers[1].Balance = 2000.45;
	customers[1].PIN = 2345;
	customers[1].Loan_List = create_List();
	customers[1].Transaction_Stack.Top = 0;

	// ------------ CUSTOMER 2 ------------
	customers[2].Account_Number = 345678;
	customers[2].Account_Type = "Current";
	customers[2].IBAN = 87654321;
	customers[2].Branch_Code = "TN111";
	customers[2].Account_Holder_Name = "Omar Said";
	customers[2].Opening_date = "15-03-2021";
	customers[2].Status = "Active";
	customers[2].Balance = 3500.0;
	customers[2].PIN = 3456;
	customers[2].Loan_List = create_List();
	customers[2].Transaction_Stack.Top = 0;

	// ------------ CUSTOMER 3 ------------
	customers[3].Account_Number = 456789;
	customers[3].Account_Type = "Fixed Deposit";
	customers[3].IBAN = 99887766;
	customers[3].Branch_Code = "TN222";
	customers[3].Account_Holder_Name = "Mouna Cherif";
	customers[3].Opening_date = "10-11-2019";
	customers[3].Status = "Active";
	customers[3].Balance = 50000.0;
	customers[3].PIN = 4567;
	customers[3].Loan_List = create_List();
	customers[3].Transaction_Stack.Top = 0;

	// ------------ CUSTOMER 4 ------------
	customers[4].Account_Number = 567890;
	customers[4].Account_Type = "Current";
	customers[4].IBAN = 88776655;
	customers[4].Branch_Code = "TN333";
	customers[4].Account_Holder_Name = "Yassine Hannachi";
	customers[4].Opening_date = "20-07-2022";
	customers[4].Status = "Active";
	customers[4].Balance = 7800.75;
	customers[4].PIN = 5678;
	customers[4].Loan_List = create_List();
	customers[4].Transaction_Stack.Top = 0;
	CustomerCount = 5;


	// ===================== EMPLOYEES =====================

	employees[0] = { 1001, "Rabii", "Zarrouki" , "Ariana", 1250.00, "12-03-2019", 2 };
	employees[1] = { 1002, "Wajdi", "Bedoui" , "Tunis", 2500.00, "27-07-2020", 2 };
	employees[2] = { 1003, "Yassine", "Ahmed" , "Ghazela", 1350.00, "05-11-2021", 1 };
	employees[3] = { 1004, "Meriem", "Cherni" , "Menzah 5", 2400.00, "18-04-2022", 3 };
	employees[4] = { 1005, "Hatem", "Aloui" , "Manouba", 3100.00, "07-01-2023", 1 };
	EmployeeCount = 5;


	//===================== Loans and Transactions for Customers =====================
	// 
	// Customer 0: one active personal loan, two transactions
	{
		loan L{ customers[0].Account_Number, 100001, "Personal", 5000.0, 5.0, 1000.0, 4000.0, "01-01-2021", "01-01-2024", "Active" };
		insert(customers[0].Loan_List, L, customers[0].Loan_List.size + 1);
		Push(&customers[0].Transaction_Stack, transaction{ 1, customers[0].Account_Number, "Deposit", 500.0, "01-02-2021" });
		Push(&customers[0].Transaction_Stack, transaction{ 2, customers[0].Account_Number, "Withdrawal", 200.0, "03-02-2021" });
	}

	// Customer 1: one home loan, one transaction
	{
		loan L{ customers[1].Account_Number, 100002, "Home", 25000.0, 3.5, 5000.0, 20000.0, "15-06-2020", "15-06-2040", "Active" };
		insert(customers[1].Loan_List, L, customers[1].Loan_List.size + 1);
		Push(&customers[1].Transaction_Stack, transaction{ 3, customers[1].Account_Number, "Deposit", 1500.0, "20-06-2020" });
	}

	// Customer 2: one car loan, two transactions
	{
		loan L{ customers[2].Account_Number, 100003, "Car", 12000.0, 4.0, 3000.0, 9000.0, "01-04-2021", "01-04-2026", "Active" };
		insert(customers[2].Loan_List, L, customers[2].Loan_List.size + 1);
		Push(&customers[2].Transaction_Stack, transaction{ 4, customers[2].Account_Number, "Withdrawal", 100.0, "05-04-2021" });
		Push(&customers[2].Transaction_Stack, transaction{ 5, customers[2].Account_Number, "Deposit", 200.0, "06-04-2021" });
	}

	// Customer 3: fixed deposit (no loan), one deposit transaction
	{
		Push(&customers[3].Transaction_Stack, transaction{ 6, customers[3].Account_Number, "Deposit", 10000.0, "12-11-2019" });
	}

	// Customer 4: two small loans and a withdrawal
	{
		loan L1{ customers[4].Account_Number, 100004, "Personal", 2000.0, 6.0, 500.0, 1500.0, "20-07-2022", "20-07-2024", "Active" };
		loan L2{ customers[4].Account_Number, 100005, "Home", 3000.0, 2.5, 0.0, 3000.0, "01-09-2022", "01-09-2025", "Overdue" };
		insert(customers[4].Loan_List, L1, customers[4].Loan_List.size + 1);
		insert(customers[4].Loan_List, L2, customers[4].Loan_List.size + 1);
		Push(&customers[4].Transaction_Stack, transaction{ 7, customers[4].Account_Number, "Withdrawal", 250.0, "25-07-2022" });
	}
}

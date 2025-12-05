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
	CustomerCount++;

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
	CustomerCount++;

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
	CustomerCount++;

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
	CustomerCount++;

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
	CustomerCount++;


	// ===================== EMPLOYEES =====================

	employees[0] = { 1001, "Rabii", "Zarrouki" , "Ariana", 1250.00, "12-03-2019", 2 };
	employees[1] = { 1002, "Wajdi", "Bedoui" , "Tunis", 2500.00, "27-07-2020", 2 };
	employees[2] = { 1003, "Yassine", "Ahmed" , "Ghazela", 1350.00, "05-11-2021", 1 };
	employees[3] = { 1004, "Meriem", "Cherni" , "Menzah 5", 2400.00, "18-04-2022", 3 };
	employees[4] = { 1005, "Hatem", "Aloui" , "Manouba", 3100.00, "07-01-2023", 1 };

	EmployeeCount = 5;
}

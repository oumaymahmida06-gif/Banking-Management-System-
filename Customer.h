#pragma once
#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <string>
using namespace std;

struct customer {
	string Account_Number;
	string Account_Type;
	int IBAN=0;
	string Branch_Code;
	string Account_Holder_Name;
	string Opening_date;
	string Status; 
	double Balance=0.0;
	int PIN=0;
};

struct loan {
	int Loan_ID=0;
	string Loan_Type;
	double Principle_Amount=0.0;
	double Interest_Rate=0.0;
	double Amount_paid=0.0;
	double Remaining_Balance=0.0;
	string Start_Date;
	string End_Date;
	string Loan_Status;
};
struct transaction {
	int Transaction_ID=0;
	int Account_Number=0;
	string Type;
	double Amount=0.0;
	string Date;
};
#endif

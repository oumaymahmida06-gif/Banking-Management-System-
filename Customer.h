#pragma once
#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <string>
using namespace std;

struct customer {
	int Account_Number;
	string Account_Type;
	int IBAN=0;
	string Branch_Code;
	string Account_Holder_Name;
	string Opening_date;
	string Status; 
	double Balance=0.0;
	int PIN=0;
	list Loan_List;
	list Requested_Loan_List;
};



struct transaction {
	int Transaction_ID=0;
	int Account_Number=0;
	string Type;
	double Amount=0.0;
	string Date;
};
#endif

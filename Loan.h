#pragma once
#ifndef LOAN_H
#define LOAN_H
#include<iostream>
#include<string>
using namespace std;

struct loan {
	int Loan_ID = 0;
	string Loan_Type;
	double Principle_Amount = 0.0;
	double Interest_Rate = 0.0;
	double Amount_paid = 0.0;
	double Remaining_Balance = 0.0;
	string Start_Date;
	string End_Date;
	string Loan_Status;
};
#endif

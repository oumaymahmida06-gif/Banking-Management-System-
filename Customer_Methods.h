#pragma once
#ifndef CUSTOMER_METHODS_H
#define CUSTOMER_METHODS_H
#include "Customer.h"
#include "Queue.h"

//------------------------LOGIN--------------------------

int CheckCustomerLogin(customer* customers, int CustomerCount);

//------------------------ARRAY--------------------------

//DYNAMIC ALLOCATION:
void NewCustomerArray(customer*& customers, int& Customer_Capacity, int CustomerCount);

int FindCustomer(customer* customers, int number, int CustomerCount);
void PrintCustomer(const customer& c);
void DisplayCustomers(customer* customers, int CustomerCount);


//------------------------VERIFICATIONS--------------------------

// for the customer :
bool isNumber(string str);
bool VerifyAccountNumber(int AccountNumber, customer* customers, int CustomerCount);
bool VerifyExistingAccountNumber(int accountNumber, customer* customers, int CustomerCount);
bool VerifyAccountType(string AccountType);
bool VerifyIBAN(int IBAN);
bool VerifyBranchCode(string BranchCode);
bool VerifyAccountHolderName(string AccountHolderName);
bool VerifyOpeningDate(string OpeningDate);
bool VerifyStatus(string Status);
bool VerifyBalance(double Balance);
bool VerifyPIN(int PIN);

// for the loans :
bool VerifyLoanID(int loanID);
bool VerifyLoanStatus(string Status);
bool Verify_End_Date(string Start_Date, string End_Date);
bool VerifyLoanType(string LoanType);

//------------------------TO USE FOR THE CUSTOMER--------------------------
void Display_Loan_List(const customer& c);
void Submit_Loan_Request(customer& c, Queue& Q);
int Withdraw_Money(customer& c);
int Deposit_Money(customer& c, double amount);
void Display_Transactions(const customer& c);
void Undo_Last_Transaction(customer& c);

//------------------------INTERFACE FUNCTION--------------------------
void customer_interface(customer*& customers, int& CustomerCount, int& Customer_Capacity, Queue& Q);

#endif

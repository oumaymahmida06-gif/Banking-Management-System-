#pragma once
#ifndef CUSTOMER_METHODS_H
#define CUSTOMER_METHODS_H

#include "Customer.h"

bool isEmpty(const list& L);
bool isFull(const list& L);
int listSize(const list& L);

node* create_Node(const loan& value);
void destroy_Node(node* value);

list create_List();
void destroy_List(list* L);

int insert(list& L, const loan& Loan, int pos);
int removeAt(list* L, int pos);
loan get_Element(const list& L, int pos);

int CheckCustomerLogin(customer* customers, int CustomerCount);
void AddCustomer(customer *& customers, int& CustomerCount, int& Customer_Capacity);
void NewCustomerArray(customer*& customers, int& Customer_Capacity, int CustomerCount);
void ChangeCustomerAccountStatus(customer* customers, int CustomerCount);
int FindCustomer(customer* customers, int number, int CustomerCount);
void DisplayCustomers(customer* customers, int CustomerCount);
void PrintCustomer(const customer& c);

bool isNumber(string str);
bool VerifyAccountNumber(int AccountNumber);
bool VerifyAccountType(string AccountType);
bool VerifyIBAN(int IBAN);
bool VerifyBranchCode(string BranchCode);
bool VerifyAccountHolderName(string AccountHolderName);
bool VerifyOpeningDate(string OpeningDate);
bool VerifyStatus(string Status);
bool VerifyBalance(double Balance);
bool VerifyPIN(int PIN);

void Display_Loan_List(const customer& c);
void Submit_Loan_Request(customer& c);
bool Verify_End_Date(string Start_Date, string End_Date);
void customer_interface(customer*& customers, int& CustomerCount, int& Customer_Capacity);

Stack* CreateStack();
void DestroyStack(Stack* S);
void DisplayStack(const Stack& S);
bool IsEmpty(const Stack& S);
bool IsFull(const Stack& S);
int StackSize(const Stack& S);
int Push(Stack* S, const transaction& e);
transaction Pop(Stack* S);
transaction Top(const Stack& S);

int Withdraw_Money(customer& c);
int Deposit_Money(customer& c);
void Display_Transactions(const customer& c);
void Undo_Last_Transaction(customer& c);

void Change_Status_Of_A_Loan(customer* customers, int CustomerCount);
bool VerifyLoanID(int loanID);
bool VerifyLoanStatus(string Status);


int Home_Page();
int Login_Page();
int Customer_Home_Page();
void Quit_Program();

#endif

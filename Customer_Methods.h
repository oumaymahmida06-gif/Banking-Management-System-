#pragma once
#ifndef CUSTOMER_METHODS_H
#define CUSTOMER_METHODS_H
#include "DoublyLinkedList.h"

bool isEmpty(const list& L);
bool isFull(const list& L);
int listSize(const list& L);

node* create_Node(const loan& value);
void destroy_Node(node* value);

list create_List();
void destroy_List(list* L);

int insert(list* L, loan Loan, int pos);
int removeAt(list* L, int pos);
loan get_Element(const list& L, int pos);
void display_Loan_List(const list& L);

list CopyList(const list& L);

bool CheckCustomerLogin(customer* customers, int CustomerCount);
void AddCustomer(customer *& customers, int& CustomerCount, int& Customer_Capacity);
void NewCustomerArray(customer*& customers, int& Customer_Capacity, int CustomerCount);

bool isNumber(string str);
bool VerifyAccountNumber(string AccountNumber);
bool VerifyAccountType(string AccountType);
bool VerifyIBAN(int IBAN);
bool VerifyBranchCode(string BranchCode);
bool VerifyAccountHolderName(string AccountHolderName);
bool VerifyOpeningDate(string OpeningDate);
bool VerifyStatus(string Status);
bool VerifyBalance(double Balance);
bool VerifyPIN(int PIN);

#endif

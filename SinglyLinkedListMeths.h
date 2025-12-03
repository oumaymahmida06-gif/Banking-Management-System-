#pragma once
#ifndef SINGLYLINKEDLISTMETHS_H
#define SINGLYLINKEDLISTMETHS_H
#include "SinglyLinkedList.h"

CompletedLoanNode* Create_Completed_Loan_Node(loan completed_loan);
void Destroy_Completed_Loan_Node(CompletedLoanNode* node);
CompletedLoanList Create_Completed_Loan_List();
void Destroy_Completed_Loan_List(CompletedLoanList* L);
bool Completed_Loan_List_Is_Empty(const CompletedLoanList& L);
bool Completed_Loan_List_Is_Full(const CompletedLoanList& L);
int Completed_Loans_list_Size(const CompletedLoanList& L);
void Display_Completed_Loans(const CompletedLoanList& L);
int Insert_Completed_Loan(CompletedLoanList* L, const loan& e, int pos);

#endif

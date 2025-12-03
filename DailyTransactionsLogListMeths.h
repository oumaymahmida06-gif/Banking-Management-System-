#pragma once
#ifndef DAILYTRANSACTIONSLOGLISTMETHS_H
#define DAILYTRANSACTIONSLOGLISTMETHS_H
#include "DailyTransactionsLogList.h"

DailyTransactionNode* Create_Daily_Transaction_Node(transaction completed_transaction);
void Destroy_Daily_Transaction_Node(DailyTransactionNode* node);
DailyTransactionsLogList Create_Daily_Transactions_Log_List();
void Destroy_Daily_Transactions_Log_List(DailyTransactionsLogList* L);
bool Daily_Transactions_Log_List_Is_Empty(const DailyTransactionsLogList& L);
bool Daily_Transactions_Log_List_Is_Full(const DailyTransactionsLogList& L);
int Daily_Transactions_Log_List_Size(const DailyTransactionsLogList& L);
void Display_Daily_Transactions_Log_List(const DailyTransactionsLogList& L);
int Insert_Completed_Transaction(DailyTransactionsLogList* L, const transaction& e, int pos);

#endif

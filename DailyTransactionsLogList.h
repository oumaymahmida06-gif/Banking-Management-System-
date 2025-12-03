#pragma once
#ifndef DAILYTRANSACTIONSLOGLIST_H
#define DAILYTRANSACTIONSLOGLIST_H
#include "Transaction.h"

struct DailyTransactionNode {
    transaction data;
    DailyTransactionNode* next = nullptr;
};

struct DailyTransactionsLogList {
    DailyTransactionNode* head = nullptr;
    int size = 0;
};

#endif

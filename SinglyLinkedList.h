#pragma once
#ifndef SINGLYLINKEDLIST_H
#define SINGLYLINKEDLIST_H
#include "Loan.h"

struct CompletedLoanNode {
    loan data;
    CompletedLoanNode* next = nullptr;
};

struct CompletedLoanList {
    CompletedLoanNode* head = nullptr;
    int size = 0;
};

#endif

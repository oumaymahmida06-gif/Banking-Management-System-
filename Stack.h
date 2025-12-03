#pragma once
#ifndef STACK_H
#define STACK_H
#include "Transaction.h"
constexpr int Max = 100;
struct Stack {
	transaction transactions[Max];
	int Top=0;
};

#endif

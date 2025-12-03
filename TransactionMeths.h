#pragma once
#ifndef TRANSACTIONMETHS_H
#define TRANSACTIONMETHS_H
#include "Stack.h"

Stack* CreateStack();
void DestroyStack(Stack* S);
void DisplayStack(const Stack& S);
bool IsEmpty(const Stack& S);
bool IsFull(const Stack& S);
int StackSize(const Stack& S);
int Push(Stack* S, transaction e);
transaction Pop(Stack& S);
transaction Top(const Stack& S);

#endif

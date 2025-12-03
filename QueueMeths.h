#pragma once
#ifndef QUEUEMETHS_H
#define QUEUEMETHS_H
#include "Queue.h"
#include "Customer_Methods.h" 

Queue* CreateQueue();
void DestroyQueue(Queue* Q);
void DisplayQueue(const Queue& Q);
bool IsEmpty(const Queue& Q);
bool IsFull(const Queue& Q);
int QueueSize(const Queue& Q);
int Enqueue(Queue& Q, loan loan_request);
bool Dequeue(Queue& Q);
loan FrontElement(const Queue& Q);
void Manage_Loan_Requests(Queue& Q, customer* customers, int CustomerCount);
#endif

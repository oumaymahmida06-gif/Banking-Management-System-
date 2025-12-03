#pragma once
#ifndef QUEUE_H
#define QUEUE_H
#include "Loan.h"

constexpr int QueueMax = 100;
struct Queue{
	loan Loan_Requests[QueueMax];
	int Front;
	int Tail;
};
#endif

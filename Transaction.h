#pragma once
#ifndef TRANSACTION_H
#define TRANSACTION_H
#include <iostream>
using namespace std;

struct transaction {
	int Transaction_ID = 0;
	int Account_Number = 0;
	string Transaction_Type;
	double Transaction_Amount = 0.0;
	string Transaction_Date;
};
#endif

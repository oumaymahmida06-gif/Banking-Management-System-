#pragma once
#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H
#include "Customer.h"

struct node {
	loan data;
	node* next=nullptr;
	node* prev=nullptr;
};
struct list {
	node* head=nullptr;
	node* tail=nullptr;
	int size=0;
};
#endif 

#pragma once
#ifndef STRUCT_H
#define STRUCT_H
#include "Student.h"

struct Node {
	Student data;
	Node* next;
};

struct List {
	Node* head;
	int size;
};

#endif
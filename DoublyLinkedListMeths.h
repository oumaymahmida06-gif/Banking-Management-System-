#pragma once
#ifndef DOUBLYLINKEDLISTMETHS_H
#define DOUBLYLINKEDLISTMETHS_H
#include "DoublyLinkedList.h"

bool isEmpty(const list& L);
bool isFull(const list& L);
int listSize(const list& L);

node* create_Node(const loan& value);
void destroy_Node(node* value);

list create_List();
void destroy_List(list* L);

int insert(list& L, const loan& Loan, int pos);
int removeAt(list* L, int pos);
loan get_Element(const list& L, int pos);

#endif

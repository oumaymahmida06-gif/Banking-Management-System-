#pragma once
#ifndef METHODS_H
#define METHODS_H
#include "structures.h"

Node* createNode(const Student& value);
void destroyNode(Node* node);
List createList();
void destroyList(List* L);
bool isEmpty(const List& L);
bool isFull(const List& L);
int listSize(const List& L);
int insert(List* L, const Student& e, int pos);
int removeAt(List* L, int pos);
Student getElement(const List& L, int pos);
void displayList(const List& L);
List CopyList(const List& L);
bool CompareLists(const List& L1, const List& L2);

#endif

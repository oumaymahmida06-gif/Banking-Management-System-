#include <iostream>
#include "methods.h"
using namespace std;

Node* createNode(const Student& value) {
	Node* node = new (nothrow) Node{ value, nullptr };
	if (!node)
		cerr << "Memory allocation failed\n";
	return node;
}

void destroyNode(Node* node) {
	delete node;
}

List createList() {
	return List{ nullptr, 0 };
}

void destroyList(List* L) {
	if (!L) return;
	Node* current = L->head;
	while (current) {
		Node* temp = current;
		current = current->next;
		destroyNode(temp);
	}
	L->head = nullptr;
	L->size = 0;
}

bool isEmpty(const List& L) {
	return L.size == 0;
}

bool isFull(const List& L) {
	Node* test = new (nothrow) Node;
	if (!test) return true;
	delete test;
	return false;
}

int listSize(const List& L) {
	return L.size;
}

int insert(List* L, const Student& e, int pos) {
	if (!L) return 0;
	if (pos < 1 || pos > L->size + 1) {
		cerr << "\nInvalid position";
		return 0;
	}
	Node* n = createNode(e);
	if (!n) return 0;
	if (pos == 1) {
		n->next = L->head;
		L->head = n;
	}
	else {
		Node* prev = nullptr;
		Node* current = L->head;
		for (int i = 1; i < pos; i++) {
			prev = current;
			current = current->next;
		}
		prev->next = n;
		n->next = current;
	}
	L->size++;
	return 1;
}

int removeAt(List* L, int pos) {
	if (!L || isEmpty(*L)) {
		cerr << "\nList is empty";
		return 0;
	}
	if (pos < 1 || pos > L->size) {
		cerr << "\nInvalid position";
		return 0;
	}
	Node* prev = nullptr;
	Node* current = L->head;
	if (pos == 1) {
		L->head = current->next;
	}
	else {
		for (int i = 1; i < pos; i++) {
			prev = current;
			current = current->next;
		}
		prev->next = current->next;
	}
	destroyNode(current);
	L->size--;
	return 1;
}
Student getElement(const List& L, int pos) {
	if (isEmpty(L)) {
		cerr << "\nList is empty\n";
		return Student{ -1, "", 0.0, 0 };
	}
	if (pos < 1 || pos > L.size) {
		cerr << "\nInvalid position\n";
		return Student{ -1, "", 0.0, 0 };
	}
	Node* current = L.head;
	for (int i = 1; i < pos; i++) {
		current = current->next;
	}
	return current->data;
}

void displayList(const List& L) {
	if (isEmpty(L)) {
		cout << "List is empty\n";
		return;
	}
	Node* current = L.head;
	while (current) {
		cout << "[ID=" << current->data.id
			 << ", Name=" << current->data.name
			 << ", GPA=" << current->data.gpa
			 << ", Level=" << current->data.level
			 << "] -> ";
		current = current->next;
	}
	cout << "NULL\n";
}

List CopyList(const List& L) {
	List newList = createList();
	Node* current = L.head;
	Node* tail = nullptr;
	while (current) {
		Node* n = createNode(current->data);
		if (!n) {
			cerr << "\nMemory allocation failed while copying\n";
			destroyList(&newList);
			return createList();
		}
		if (!newList.head) {
			newList.head = n;
			tail = n;
		}
		else {
			tail->next = n;
			tail = n;
		}
		current = current->next;
	}
	newList.size = L.size;
	return newList;
}

bool CompareLists(const List& L1, const List& L2) {
	if (L1.size != L2.size) return false;
	Node* p1 = L1.head;
	Node* p2 = L2.head;
	while (p1) {
		Student a = p1->data;
		Student b = p2->data;

		if (a.id != b.id ||
			a.name != b.name ||
			a.gpa != b.gpa ||
			a.level != b.level)
			return false;

		p1 = p1->next;
		p2 = p2->next;
	}
	return true;
}

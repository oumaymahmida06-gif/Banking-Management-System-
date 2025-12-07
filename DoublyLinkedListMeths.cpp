#include <iostream>
#include "DoublyLinkedListMeths.h"
#include "Customer_Methods.h"
using namespace std;

bool isEmpty(const list& L) {
	return L.size == 0;
}
bool isFull(const list& L) {
	node* test = new (nothrow) node;
	if (!test) return true;
	delete test;
	return false;
}
int listSize(const list& L) {
	return L.size;
}
node* create_Node(const loan& value) {
	node* Node = new (nothrow) node;
	if (!Node) {
		cout << "\nMemory allocation failed for node\n";
		return nullptr;
	}
	Node->data = value;
	Node->next = nullptr;
	Node->prev = nullptr;
	return Node;
}

void destroy_Node(node* Node) {
	delete Node;
}
list create_List() {
	return list{ nullptr, nullptr, 0 };
};
void destroy_List(list* L) {
	if (!L) return;
	node* current = L->head;
	while (current) {
		node* temp = current;
		current = current->next;
		destroy_Node(temp);
	}
	L->head = nullptr;
	L->size = 0;
}

int insert(list& L, const loan& Loan, int pos) {
	if (pos < 1 || pos > L.size + 1) {
		cout << "\nInvalid position";
		return 0;
	}
	node* n = create_Node(Loan);
	if (!n) return 0;
	if (isEmpty(L)) {
		L.head = n;
		L.tail = n;
	}
	else if (pos == 1) {
		n->next = L.head;
		L.head->prev = n;
		L.head = n;
	}
	else if (pos == L.size + 1) {
		n->prev = L.tail;
		L.tail->next = n;
		L.tail = n;
	}
	else {
		node* prev = nullptr;
		node* current = L.head;
		for (int i = 1; i < pos; i++) {
			prev = current;
			current = current->next;
		}
		prev->next = n;
		n->prev = prev;
		n->next = current;
		current->prev = n;
	}
	L.size++;
	return 1;
}
int removeAt(list* L, int pos) {
	if (!L || isEmpty(*L)) {
		cout << "\nList is empty";
		return 0;
	}
	if (pos < 1 || pos > L->size) {
		cout << "\nInvalid position";
		return 0;
	}

	node* current = L->head;

	if (L->size == 1) {
		delete current;
		L->head = nullptr;
		L->tail = nullptr;
		L->size--;
		return 1;
	}

	if (pos == 1) {
		L->head = current->next;
		L->head->prev = nullptr;
		delete current;
		L->size--;
		return 1;
	}

	if (pos == L->size) {
		current = L->tail;
		L->tail = current->prev;
		L->tail->next = nullptr;
		delete current;
		L->size--;
		return 1;
	}

	for (int i = 1; i < pos; i++)
		current = current->next;

	current->prev->next = current->next;
	current->next->prev = current->prev;

	delete current;
	L->size--;
	return 1;
}
loan get_Element(const list& L, int pos) {
	if (isEmpty(L)) {
		cerr << "\nList is empty\n";
		return loan{};
	}

	if (pos < 1 || pos > L.size) {
		cerr << "\nInvalid position\n";
		return loan{};
	}
	node* current = L.head;
	for (int i = 1; i < pos; i++) {
		current = current->next;
	}
	return current->data;
}

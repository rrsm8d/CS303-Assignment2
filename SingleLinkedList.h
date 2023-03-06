#pragma once
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// What each node will contain
struct Item_Type {
	int value;
};

struct Node {
	Item_Type item;
	Node* nextPtr;
};

class SingleLinkedList {
public:
	SingleLinkedList();
	SingleLinkedList(Item_Type item);
	void printSingleLinkedList();

	void push_front(Item_Type item);
	void push_back(Item_Type item);
	void pop_front();
	void pop_back();
	Node* front();
	Node* back();
	bool isEmpty();
	void insert(size_t index, const Item_Type& item);
	bool remove(size_t index);
	size_t find(const Item_Type& item);

	int getNumItems() { return numItems; }
private:
	Node* headPtr;
	Node* tailPtr;
	int numItems = 0;
};

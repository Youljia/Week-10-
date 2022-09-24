#include"Node.h"
#pragma once
class Linked_list
{
public:
	Linked_list(int e);
	Linked_list();
	int get_size();
	bool is_empty();
	void show();
	void add_first(int e);
	bool contains(int e);
	void remove(int e);
public:
	Node* head;
	int size;
};

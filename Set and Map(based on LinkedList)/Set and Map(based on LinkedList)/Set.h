#pragma once
#include"Linked_list.h"
class Set
{
public:
	Set();
	Set(int e);
	int get_size();
	bool is_empty();
	void add(int e);
	void remove(int e);
	bool contains(int e);
	void show();
private:
	Linked_list l;
};


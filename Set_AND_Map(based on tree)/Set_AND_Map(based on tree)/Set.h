#pragma once
#include"BST.h"

class Set
{
public:
	Set();
	Set(int e);
	int get_size();
	bool is_empty();
	bool contains(int e);
	void remove(int e);
	void add(int e);
	void show();
private:
	BST bst;
};


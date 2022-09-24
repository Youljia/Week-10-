#pragma once
#include"Node.h"
class BST
{
public:
	BST();
	BST(int e);
	int get_size();
	bool is_empty();
	void add(int e);
	bool contains(int e);
	void pre_order();
	void in_order();
	void post_order();
	void show();
	void level_order();
	int search_min();
	int search_max();
	int remove_min();
	int remove_max();
	void remove(int e);
private:
	void pre_traverse(Node* node);
	void in_traverse(Node* node);
	void post_traverse(Node* node);
	Node* add(Node* node, int e);
	bool contains(Node* node, int e);
	void show(Node* node, int depth);
	void show_depth(int depth);
	Node* search_min(Node* node);
	Node* search_max(Node* node);
	Node* remove_min(Node* node);
	Node* remove_max(Node* node);
	Node* remove(Node* node, int e);
private:
	Node* root;
	int size;
	int sum;
};


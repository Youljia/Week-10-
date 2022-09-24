#pragma once
class Node
{
public:
	Node();
	Node(int e);
	~Node();
public:
	int e;
	Node* left;
	Node* right;
};



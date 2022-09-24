#include "Node.h"
#include<iostream>
using namespace std;
Node::Node(int e)
{
	this->e = e;
	this->next = nullptr;
}
Node::Node() {
	this->e = NULL;
	this->next = nullptr;
}
Node::~Node() {
	cout << "This node is releasing... ..." << endl;
	if (this->next != nullptr)
	{
		delete this->next;
		this->next = nullptr;
		this->e = NULL;
	}
}

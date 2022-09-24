#include "Node.h"
#include<iostream>
using namespace std;
Node::Node()
{
	this->e = NULL;
	this->left = nullptr;
	this->right = nullptr;
}
Node::Node(int e)
{
	this->e = e;
	this->left = nullptr;
	this->right = nullptr;
}
Node::~Node()
{
	cout << "This node is releasing... ..." << endl;
	if (this->left != nullptr)
	{
		this->e = NULL;
		this->left = nullptr;
	}
	if (this->right != nullptr)
	{
		this->e = NULL;
		this->right = nullptr;
	}
}
#include<iostream>
#include"Linked_list.h"
using namespace std;

Linked_list::Linked_list(int e) {
	this->head = new Node(e);
	this->size = 1;
}
Linked_list::Linked_list() {
	this->head = nullptr;
	this->size = NULL;
}
int Linked_list::get_size() {
	return this->size;
}
bool Linked_list::is_empty() {
	if (this->size == 0)
		return true;
	else
		return false;
}
void Linked_list::show() {
	Node* n = this->head;
	while (n != nullptr)
	{
		cout << n->e << endl;
		n = n->next;
	}
}
void Linked_list::add_first(int e) {
	Node* first = new Node(e);
	first->next = this->head;
	this->head = first;
	size++;
}
bool Linked_list::contains(int e) {
	Node* cur = this->head;
	while (cur != nullptr)
	{
		if (cur->e == e)
			return true;
		cur = cur->next;
	}
	return false;
}
void Linked_list::remove(int e) {
	Node* cur = this->head;
	if (this->head == nullptr)
		return;
	else if (this->head->e == e)
	{
		this->head = cur->next;
		cur->next = nullptr;
		cur->e = NULL;
		size--;
		return;
	}
	else
	{
		while (cur->next != nullptr)
		{
			if (cur->next->e == e)
			{
				Node* target = cur->next;
				cur->next = target->next;
				target->next = nullptr;
				target->e = NULL;
				size--;
				return;
			}
			else
				cur = cur->next;
		}
	}
}

#include<iostream>
#include"Node.h"
using namespace std;

class Linked_list {
public:
	Linked_list(int e){
		this->head = new Node(e);
		this->size = 1;
	}
	Linked_list() {
		this->head = nullptr;
		this->size = 0;
	}
	int get_size()
	{
		return this->size;
	}
	void show()
	{
		Node* n = this->head;
		while (n != nullptr)
		{
			cout << n->e << endl;
			n = n->next;
		}
	}
	//�����������Ԫ�ص����ʵ�λ�ã����������������
	void add(int e)
	{
		this->head = add(this->head, e);
	}
	//�ݹ����
	//ѭ�������� --> Ԫ��eû�б������ȥ
	//�����������Ԫ�غ�������ͷ�ڵ�
	Node* add(Node* node, int e) {
		if (node == nullptr || node->e >= e)
		{
			Node* cur = new Node(e);
			cur->next = node;
			size++;
			return cur;
		}
		else
			node->next = add(node->next, e);
		return node;
	}
private:
	Node* head;
	int size;
};

int main()
{
	Linked_list l(3);
	cout << l.get_size() << endl;
	l.add(5);
	cout << l.get_size() << endl;
	l.add(7);
	cout << l.get_size() << endl;
	l.add(4);
	cout << l.get_size() << endl;
	l.add(1);
	cout << l.get_size() << endl;

	Linked_list k;
	k.add(3);
	cout << k.get_size() << endl;
	k.show();
	return 0;
}
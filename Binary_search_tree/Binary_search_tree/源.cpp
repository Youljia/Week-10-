#include<iostream>
#include<queue>
#include"BST.h"
#include"Node.h"
using namespace std;

int main()
{
	BST b(80);
	b.add(70);
	b.add(90);
	b.add(60);
	b.add(75);
	b.add(85);
	b.add(100);
	cout << b.get_size() << endl;
	if (b.contains(3))
		cout << "сп" << endl;
	if(b.contains(0))
		cout << "you"<<endl;
	else
		cout << "my"<<endl;
	b.pre_order();
	cout << endl;
	b.in_order();
	cout << endl;
	b.post_order();
	cout << endl;
	b.show();
	b.level_order();
	cout << endl;
	cout << b.search_min() << endl;
	cout << b.search_max() << endl;
	b.remove_max();
	b.remove_min();
	cout << b.search_min() << endl;
	cout << b.search_max() << endl;
	if (b.contains(75))
		cout << "you" << endl;
	else
		cout << "my" << endl;
	b.remove(75);
	if (b.contains(75))
		cout << "you" << endl;
	else
		cout << "my" << endl;
	return 0;
}
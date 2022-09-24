#include<iostream>
#include"Linked_list.h"
#include"Set.h"
using namespace std;

int main()
{
	Linked_list l(8);
	l.add_first(10);
	l.add_first(19);
	l.show();
	if (l.contains(1))
		cout << "yes" << endl;
	cout << l.get_size() << endl;
	l.remove(19);
	l.show();
	cout << l.get_size() << endl;

	Set s(10);
	s.add(3);
	s.add(11);
	s.add(10);
	cout << s.get_size() << endl;
	s.show();
	s.remove(10);
	s.show();
	cout << s.get_size() << endl;

	return 0;
}
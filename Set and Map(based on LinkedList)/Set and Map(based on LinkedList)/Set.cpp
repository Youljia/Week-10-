#include "Set.h"
Set::Set() :l() {
}
Set::Set(int e) :l(e) {
}
int Set::get_size() {
	return this->l.size;
}
bool Set::is_empty() {
	return this->l.is_empty();
}
void Set::show() {
	this->l.show();
}
//�򼯺������Ԫ��
//ע�Ᵽ֤����Ԫ�ص�Ψһ��
void Set::add(int e) {
	if (!contains(e))
		l.add_first(e);
}
void Set::remove(int e) {
	l.remove(e);
}
bool Set::contains(int e) {
	return l.contains(e);
}

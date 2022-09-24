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
//向集合中添加元素
//注意保证集合元素的唯一性
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

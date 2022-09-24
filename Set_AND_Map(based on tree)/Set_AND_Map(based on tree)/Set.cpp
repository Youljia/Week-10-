#include "Set.h"
Set::Set() :bst() {
}
Set::Set(int e) :bst(e) {
}
int Set::get_size() {
	return bst.get_size();
}
bool Set::is_empty() {
	return bst.is_empty();
}
bool Set::contains(int e) {
	return bst.contains(e);
}
void Set::remove(int e) {
	bst.remove(e);
}
void Set::add(int e) {
	bst.add(e);
}
void Set::show() {
	bst.show();
}

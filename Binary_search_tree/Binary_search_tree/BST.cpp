#include "BST.h"
#include<iostream>
#include<queue>
using namespace std;

BST::BST(){
	this->root = nullptr;
	this->size = 0;
}
BST::BST(int e){
	root = new Node(e);
	this->size = 1;
}
//获取树中一共有多少个元素
int BST::get_size(){
	return this->size;
}
//返回该树是否为空
bool BST::is_empty(){
	if (this->size == 0)
		return true;
	else
		return false;
}
//向树中添加元素
void BST::add(int e){
	this->root = add(root, e);
}
//在节点为node下添加元素e
//循环不变量 --> 元素e不是节点为node的孩子
//返回插入元素后树的根
Node* BST::add(Node* node, int e)
{
	if (node == nullptr)
	{
		this->size++;
		return new Node(e);
	}

	else if (node->e > e)
		node->left = add(node->left, e);

	else if (node->e < e)
		node->right = add(node->right, e);

	return node;
}
//用户接口-->查询某个元素是否在树中
bool BST::contains(int e) {
	return contains(this->root, e);
}
//私有成员，递归调用
//循环不变量-->node.e不是目标元素
bool BST::contains(Node* node, int e) {
	if (node == nullptr)
		return false;
	if (node->e == e)
		return true;
	else if (node->e > e)
		contains(node->left, e);
	else
		contains(node->right, e);
}
//前序遍历二叉树
void BST::pre_order() {
	pre_traverse(this->root);
}
//递归调用
//循环不变量-->返回节点为node的左右子树
void BST::pre_traverse(Node* node) {
	if (node == nullptr)
		return;
	cout << node->e << "  ";
	pre_traverse(node->left);
	pre_traverse(node->right);
}
//用户接口，打印输出二叉树
//利用前序遍历
void BST::show() {
	show(this->root, 0);
}
//递归调用，输出节点为node的左右子树
void BST::show(Node* node, int depth) {
	if (node == nullptr)
	{
		show_depth(depth);
		cout << "null" << endl;
		return;
	}
	show_depth(depth);
	cout << node->e << endl;
	depth++;
	show(node->left, depth);
	show(node->right, depth);
}
//打印该节点的深度
void BST::show_depth(int depth) {
	for (int i = 0; i < depth; ++i) {
		cout << "--";
	}
}
//用户接口-->中序遍历
//按照从小到大的顺序输出
void BST::in_order() {
	in_traverse(this->root);
}
//用户接口-->后序遍历
//先输出左子树，右子树，最后是节点
void BST::post_order(){
	post_traverse(this->root);
}
//递归调用-->左孩子 节点操作 右孩子
void BST::in_traverse(Node* node) {
	if (node == nullptr)
		return;
	in_traverse(node->left);
	cout << node->e << "  ";
	in_traverse(node->right);
}
//递归调用-->左孩子 右孩子 节点操作
void BST::post_traverse(Node* node) {
	if (node == nullptr)
		return;
	post_traverse(node->left);
	post_traverse(node->right);
	cout << node->e << "  ";
}
//用户接口-->层序遍历
//利用队列，非递归实现
//广度优先遍历
void BST::level_order() {
	queue<Node*> q;
	q.push(this->root);
	while (!q.empty())
	{
		Node* cur = q.front();
		q.pop();
		cout << cur->e << " ";
		if (cur->left != nullptr)
			q.push(cur->left);
		if (cur->right != nullptr)
			q.push(cur->right);
	}
}
//查找二分搜索树的最小元素
int BST::search_min() {
	return search_min(this->root)->e;
}
//查找二分搜索树的最大元素
int BST::search_max() {
	return search_max(this->root)->e;
}
//返回二分搜索树中最小元素的节点
Node* BST::search_min(Node* node) {
	if (node->left == nullptr)
		return node;
	search_min(node->left);
}
//返回二分搜索树中最大元素的节点
Node* BST::search_max(Node* node) {
	if (node->right == nullptr)
		return node;
	search_max(node->right);
}
//删除最小元素并返回
int BST::remove_min() {
	int e = search_min();
	this->root = remove_min(this->root);
	return e;
}
//删除最大元素并返回
int BST::remove_max() {
	int e = search_max();
	this->root = remove_max(this->root);
	return e;
}
//删除以node为头结点的最小元素
//返回更新过后的头节点
Node* BST::remove_min(Node* node) {
	if (node->left == nullptr)
	{
		Node* res_right = node->right;
		node->right = nullptr;
		size--;
		return res_right;
	}
	node->left = remove_min(node->left);
	return node;
}
//删除以node为头结点的最大元素
//返回更新过后的头节点
Node* BST::remove_max(Node* node) {
	if (node->right == nullptr)
	{
		Node* res_left = node->left;
		node->left = nullptr;
		size--;
		return res_left;
	}
	node->right = remove_max(node->right);
	return node;
}
//删除用户指定元素
void BST::remove(int e) {
	this->root = remove(this->root, e);
}
//删除以node为头节点的指定元素
//返回更新后的头节点
Node* BST::remove(Node* node, int e) {
	if (node == nullptr)
		return nullptr;
	else if (node->e > e)
	{
		node->left = remove(node->left, e);
		return node;
	}
	else if (node->e < e)
	{
		node->right = remove(node->right, e);
		return node;
	}
	else
	{
		//目标左子树为空
		if (node->left == nullptr)
		{
			Node* res_right = node->right;
			node->right = nullptr;
			size--;
			return res_right;
		}
		//目标右子树为空
		else if (node->right == nullptr)
		{
			Node* res_left = node->left;
			node->left = nullptr;
			size--;
			return res_left;
		}
		//目标有两个孩子
		else
		{
			Node* min_right = search_min(node->right);
			min_right->right = remove_min(node->right);
			min_right->left = node->left;
			node->left = node->right = nullptr;
			return min_right;
		}
	}
}
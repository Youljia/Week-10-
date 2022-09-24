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
//��ȡ����һ���ж��ٸ�Ԫ��
int BST::get_size(){
	return this->size;
}
//���ظ����Ƿ�Ϊ��
bool BST::is_empty(){
	if (this->size == 0)
		return true;
	else
		return false;
}
//���������Ԫ��
void BST::add(int e){
	this->root = add(root, e);
}
//�ڽڵ�Ϊnode�����Ԫ��e
//ѭ�������� --> Ԫ��e���ǽڵ�Ϊnode�ĺ���
//���ز���Ԫ�غ����ĸ�
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
//�û��ӿ�-->��ѯĳ��Ԫ���Ƿ�������
bool BST::contains(int e) {
	return contains(this->root, e);
}
//˽�г�Ա���ݹ����
//ѭ��������-->node.e����Ŀ��Ԫ��
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
//ǰ�����������
void BST::pre_order() {
	pre_traverse(this->root);
}
//�ݹ����
//ѭ��������-->���ؽڵ�Ϊnode����������
void BST::pre_traverse(Node* node) {
	if (node == nullptr)
		return;
	cout << node->e << "  ";
	pre_traverse(node->left);
	pre_traverse(node->right);
}
//�û��ӿڣ���ӡ���������
//����ǰ�����
void BST::show() {
	show(this->root, 0);
}
//�ݹ���ã�����ڵ�Ϊnode����������
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
//��ӡ�ýڵ�����
void BST::show_depth(int depth) {
	for (int i = 0; i < depth; ++i) {
		cout << "--";
	}
}
//�û��ӿ�-->�������
//���մ�С�����˳�����
void BST::in_order() {
	in_traverse(this->root);
}
//�û��ӿ�-->�������
//�������������������������ǽڵ�
void BST::post_order(){
	post_traverse(this->root);
}
//�ݹ����-->���� �ڵ���� �Һ���
void BST::in_traverse(Node* node) {
	if (node == nullptr)
		return;
	in_traverse(node->left);
	cout << node->e << "  ";
	in_traverse(node->right);
}
//�ݹ����-->���� �Һ��� �ڵ����
void BST::post_traverse(Node* node) {
	if (node == nullptr)
		return;
	post_traverse(node->left);
	post_traverse(node->right);
	cout << node->e << "  ";
}
//�û��ӿ�-->�������
//���ö��У��ǵݹ�ʵ��
//������ȱ���
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
//���Ҷ�������������СԪ��
int BST::search_min() {
	return search_min(this->root)->e;
}
//���Ҷ��������������Ԫ��
int BST::search_max() {
	return search_max(this->root)->e;
}
//���ض�������������СԪ�صĽڵ�
Node* BST::search_min(Node* node) {
	if (node->left == nullptr)
		return node;
	search_min(node->left);
}
//���ض��������������Ԫ�صĽڵ�
Node* BST::search_max(Node* node) {
	if (node->right == nullptr)
		return node;
	search_max(node->right);
}
//ɾ����СԪ�ز�����
int BST::remove_min() {
	int e = search_min();
	this->root = remove_min(this->root);
	return e;
}
//ɾ�����Ԫ�ز�����
int BST::remove_max() {
	int e = search_max();
	this->root = remove_max(this->root);
	return e;
}
//ɾ����nodeΪͷ������СԪ��
//���ظ��¹����ͷ�ڵ�
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
//ɾ����nodeΪͷ�������Ԫ��
//���ظ��¹����ͷ�ڵ�
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
//ɾ���û�ָ��Ԫ��
void BST::remove(int e) {
	this->root = remove(this->root, e);
}
//ɾ����nodeΪͷ�ڵ��ָ��Ԫ��
//���ظ��º��ͷ�ڵ�
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
		//Ŀ��������Ϊ��
		if (node->left == nullptr)
		{
			Node* res_right = node->right;
			node->right = nullptr;
			size--;
			return res_right;
		}
		//Ŀ��������Ϊ��
		else if (node->right == nullptr)
		{
			Node* res_left = node->left;
			node->left = nullptr;
			size--;
			return res_left;
		}
		//Ŀ������������
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
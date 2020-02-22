///////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<iostream>
using namespace std;
/////////////////////////////////////////////////////////////
struct TNode {
	char data;
	struct TNode* left;
	struct TNode* right;
};
/*=================================================
������TNode* LayersToTree(char *A, int n)
���ܣ��ɲ������㣨��^�����Ĳ������й��������
������A: ���������㣨��^�����Ĳ�������
		  n: ���еĳ���
���: ������Ķ������ĸ�ָ�룬NULL��ʾû�й����������
==================================================*/
TNode* LayersToTree(char *A, int n)
{
	TNode**  pnode;
	TNode* node;
	int i;
	if (n <= 0)
		return NULL;
	pnode = new TNode*[n];
	for (i = 0; i < n; i++) {
		if (A[i] != '^') {
			node = new TNode;
			node->data = A[i];
			node->left = NULL;
			node->right = NULL;
			pnode[i] = node;
		}
		else
			pnode[i] = NULL;
	}
	for (i = 0; i < n; i++) {
		if (pnode[i] == NULL) continue;
		if (2 * (i + 1) <= n && pnode[2 * (i + 1) - 1] != NULL)
			pnode[i]->left = pnode[2 * (i + 1) - 1];
		if (2 * (i + 1) + 1 <= n && pnode[2 * (i + 1)] != NULL)
			pnode[i]->right = pnode[2 * (i + 1)];
	}
	node = pnode[0];
	delete pnode;
	return node;
}

void PrintTreeRootLeft(TNode* r, int layer)
//r������һ�������ĸ�����ӡ�Խ��rΪ����������
//layer��r�����������Ĳ�,Լ�����ĸ����Ĳ��Ϊ1
{
	/*����BEGIN��END֮��ʵ����Ĵ���*/
	/*****BEGIN*****/
	if (r != nullptr) {
		PrintTreeRootLeft(r->right, layer + 1);
		for (int i = 0; i < layer-1; i++)
			cout << "-----";
		cout <<"----"<<r->data;
		PrintTreeRootLeft(r->left, layer + 1);
	}
	/******END******/
	/*�벻Ҫ�޸�[BEGIN,END]������Ĵ���*/
}

void DeleteTree(TNode* t)
{
	if (t == NULL) return;
	if (t->left) DeleteTree(t->left);
	if (t->right) DeleteTree(t->right);
	delete t;
}
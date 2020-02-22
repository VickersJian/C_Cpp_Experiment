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
函数：TNode* LayersToTree(char *A, int n)
功能：由补充虚结点（‘^’）的层序序列构造二叉树
参数：A: 补充了虚结点（‘^’）的层序序列
		  n: 序列的长度
输出: 所构造的二叉树的根指针，NULL表示没有构造出二叉树
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
//r是树中一棵子树的根，打印以结点r为根的子树，
//layer是r在树中所处的层,约定树的根结点的层号为1
{
	/*请在BEGIN和END之间实现你的代码*/
	/*****BEGIN*****/
	if (r != nullptr) {
		PrintTreeRootLeft(r->right, layer + 1);
		for (int i = 0; i < layer-1; i++)
			cout << "-----";
		cout <<"----"<<r->data;
		PrintTreeRootLeft(r->left, layer + 1);
	}
	/******END******/
	/*请不要修改[BEGIN,END]区域外的代码*/
}

void DeleteTree(TNode* t)
{
	if (t == NULL) return;
	if (t->left) DeleteTree(t->left);
	if (t->right) DeleteTree(t->right);
	delete t;
}
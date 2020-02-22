#include <iostream>
#include <stack>
#include <queue>
using namespace std;
struct node {//��������㶨��
	char data;
	node* lchild;
	node* rchild;
	int tag;
};
struct TNode {
	char data;
	struct TNode* left;
	struct TNode* right;
};
typedef struct  node  BinTree;
typedef struct  node  *ptree;
BinTree* createBiTree() {//����������
	char ch;
	ptree root;
	cin >> ch;
	if (ch == '#')
		root = NULL;
	else {
		root = new node;
		root->data = ch;
		root->lchild = createBiTree();
		root->rchild = createBiTree();
	}
	return root;
}
TNode* InPreToTree(char *pa, char *ia, int p1, int p2, int i1, int i2)
{
	/*����BEGIN��END֮��ʵ����Ĵ���*/
	/*****BEGIN*****/
	TNode* root;
	int i;
	if (p1 > p2)
		return NULL;
	root = new TNode;
	for (i = i1; i <= i2; ++i)
		if (ia[i] == pa[p1]) 
			break;
	root->data = ia[i];
	root->left = InPreToTree(pa, ia, p1 + 1, p1 + i - i1, i1, i - 1);
	root->right = InPreToTree(pa, ia, p1 + i - i1 + 1, p2, i + 1, i2);
	return root;
	/******END******/
	/*�벻Ҫ�޸�[BEGIN,END]������Ĵ���*/
}

TNode *CreateBT(char* pre, char* in, int l1, int r1, int l2, int r2) {
	TNode* s;     
	int i;     
	if (l1 > r1)
		return NULL;       //��������Ԫ�ط���NULL     
	s=new TNode;        
	for(i=l2; i<=r2; ++i)         
		if(in[i]==pre[l1])      //���ҵ��ڵ�ǰ�������Ľ����in[]�е�λ��             
			break;     
	s->data=in[i];     
	s->left = CreateBT(pre, in, l1 + 1, l1 + i - l2, l2, i - 1);
	s->right=CreateBT(pre,in,l1+i-l2+1,r1,i+1,r2);     
	return s;       //��ǰ����������� 
} 

void preOrder(BinTree *T) {//�ݹ��ȸ�����
	if (T == NULL)
		return;
	cout << T->data << " ";
	preOrder(T->lchild);
	preOrder(T->rchild);
}
void inOrder(BinTree *T) {//�ݹ��и�����
	if (T == NULL)
		return;
	inOrder(T->lchild);
	cout << T->data << " ";
	inOrder(T->rchild);
}
void postOrder(BinTree *T) {//�ݹ�������
	if (T == NULL)
		return;
	postOrder(T->lchild);
	postOrder(T->rchild);
	cout << T->data << " ";
}
void PreorderTraversal(BinTree* BT) {//�ǵݹ��ȸ�����
	ptree T;
	stack<ptree> BtStack;
	T = BT;
	while (T || !BtStack.empty()) {
		while (T) {
			BtStack.push(T);
			cout << T->data << " ";
			T = T->lchild;
		}
		T = BtStack.top();
		BtStack.pop();
		T = T->rchild;
	}
}

int BinaryTreeHeight(node* head){
	int treeHeight = 0;
	if (head != NULL)
	{
		int leftHeight = BinaryTreeHeight(head->lchild);
		int rightHeight = BinaryTreeHeight(head->rchild);
		treeHeight = leftHeight >= rightHeight ? leftHeight + 1 : rightHeight + 1;
	}
	return treeHeight;
}
int countLeaf(node* T) {
	if (T == NULL) return 0;
	if (T->lchild == NULL && T->rchild == NULL)
	return 1;
	else return countLeaf(T->lchild) + countLeaf(T->rchild);
}
void InorderTraversal(BinTree* BT) {//�ǵݹ��и�����
	stack<ptree> s;
	ptree c = BT;
	if (c == NULL) return;
	do {
		while (c != NULL) { 
			s.push(c); 
			c = c->lchild; 
		}
		c = s.top(); s.pop();
		cout << c->data << " ";
		c = c->rchild;
	} while (c != NULL || !s.empty());
}
void PostorderTraversal(BinTree* BT) {//�ǵݹ�������
	stack<ptree> s;
	ptree stnode;
	ptree p = BT;
	if (BT == NULL) return;
	do {
		while (p != NULL) {
			stnode = p; stnode->tag = 1;
			s.push(stnode); p = p->lchild;
		}
		while (!s.empty()) {
			stnode = s.top(); s.pop();
			p = stnode;
			if (stnode->tag == 1)
			{
				stnode->tag = 2; s.push(stnode);
				p = p->rchild; break;
			}
			else cout << p->data << " ";
		}
	} while (!s.empty());
}
void wideTraversal(BinTree* BT) {//����α���������
	if (BT == NULL)
		return;
	queue<ptree> queue;
	queue.push(BT);
	while (!queue.empty()) {
		BinTree* node = queue.front();
		queue.pop();
		if (node->lchild != NULL) {
			queue.push(node->lchild);
		}
		if (node->rchild != NULL) {
			queue.push(node->rchild);
		}
		cout << node->data << " ";
	}
}
void deleteBinTree(BinTree* p) {//ɾ��������(ʹ�ú������ɾ��)
	if (p == NULL)
		return;
	deleteBinTree(p->lchild);
	deleteBinTree(p->rchild);
	delete(p);//��ʾɾ���ڵ�
}
void cal(BinTree* BT) {//�ǵݹ��ȸ�����
	int num=0, charactor=0, sign=0;
	ptree T;
	stack<ptree> BtStack;
	T = BT;
	while (T || !BtStack.empty()) {
		while (T) {
			BtStack.push(T);
			if (T->data >= 'a'&&T->data<='z' || T->data>='A'&&T->data <= 'Z') {
				charactor++;
			}
			else if (T->data >= '0'&&T->data <= '9') {
				num++;
			}
			else {
				sign++;
			}
			T = T->lchild;
		}
		T = BtStack.top();
		BtStack.pop();
		T = T->rchild;
	}
	cout << "��ĸ�У�" << charactor << "��" << endl;
	cout << "�����У�" << num << "��" << endl;
	cout << "�����ַ��У�" << sign << endl;
}
int main() {
	BinTree* T;
	T = createBiTree(); //����������
	cout << "�ȸ�����: ";
	preOrder(T);//�ȸ��������
	cout << endl << "�и�����: ";
	inOrder(T);//�и��������
	cout << endl << "�������: ";
	postOrder(T);//����������
	cout << endl << "�ȸ��ǵݹ����: ";
	PreorderTraversal(T);//�ȸ��ǵݹ����
	cout << endl << "�и��ǵݹ����: ";
	InorderTraversal(T);
	cout << endl << "������ǵݹ����: ";
	PostorderTraversal(T);
	cout << endl << "����α���: ";
	wideTraversal(T);//����α���
	cout << endl;
	cal(T);
	deleteBinTree(T);//���ٶ�����
	system("pause");
	return 0;
}


/*
���룺ABD###CE#G##FH##I##
�����

A B D C E G F H I

D B A E G C H F J

D B G E H I F C A
*/

/*
A,D###7E#.##9H##i##
*/

/*
���룺AB##CE#G###
�����

A B C E G

B A E G C

B G E C A
*/

//#include<iostream>
//#include<stdlib.h>
//
//using namespace std;
//struct node {//��������㶨��
//	int key;
//	node* left;
//	node* right;
//};
//void PrintTreeRootLeft(node* r, int layer)
////r������һ�������ĸ�����ӡ�Խ��rΪ����������
////layer��r�����������Ĳ�,Լ�����ĸ����Ĳ��Ϊ1
//{
//	/*����BEGIN��END֮��ʵ����Ĵ���*/
//	/*****BEGIN*****/
//
//	/******END******/
//	/*�벻Ҫ�޸�[BEGIN,END]������Ĵ���*/
//}
//bool BST_Insert(node** Tree, int k) {//���룺���ؼ���k���뵽����������
//	if (*Tree == NULL) {
//		node* Tnode = new node;
//		Tnode->key = k;
//		Tnode->left = NULL;
//		Tnode->right = NULL;
//		*Tree = Tnode;
//		return true;  //����ɹ�
//	}
//	else if (k == (*Tree)->key)
//		return false;  // ���д�����ͬ�ؼ���,����ʧ��
//	else if (k < (*Tree)->key)
//		return BST_Insert(&(*Tree)->left, k);
//	else
//		return BST_Insert(&(*Tree)->right, k);
//}
//node* Create_BST(int arr[], int n)  {//��������������
//	node* T = NULL;  // ��ʼʱΪ����
//	for (int i = 0; i < n; ++i) {
//		BST_Insert(&T, arr[i]);
//	}
//	return T;
//}
//void preOrder(node *T) {//�ݹ��������
//	if (T == NULL)
//		return;
//	cout << T->key << " ";
//	preOrder(T->left);
//	preOrder(T->right);
//}
//void inOrder(node *T) {//�ݹ��������
//	if (T == NULL)
//		return;
//	inOrder(T->left);
//	cout << T->key << " ";
//	inOrder(T->right);
//}
//node* BST_Search(node* T, int k) {//�ݹ����
//	if (T == NULL || k == T->key)
//		return T;
//	if (k < T->key)
//		return BST_Search(T->left, k);
//	else
//		return BST_Search(T->right, k);
//}
//bool deleteNode(node* T,int key) {
//	node* parent = NULL;
//	node* pcur = T;
//	node* del = pcur;
//	while (pcur != NULL && pcur->key != key) {
//		if (pcur->key > key) {
//			parent = pcur;
//			pcur = pcur->left;
//		}
//		else if (pcur->key < key) {
//			parent = pcur;
//			pcur = pcur->right;
//		}
//	}
//	if (pcur == NULL)
//		return false;
//	if (pcur->left == NULL) {     //ֻ���Һ���
//		//���pcur���Ǹ��ڵ�Ļ����ø��ڵ�ָ�������
//		if (pcur == T)
//			T = pcur->right;
//		else if (pcur == parent->left) {
//			parent->left = pcur->right;
//		}
//		else {
//			parent->right = pcur->right;
//		}
//		del = pcur;
//	}
//	else if (pcur->right == NULL)     //ֻ������
//	{
//		//����Ǹ��ڵ㣬�ø��ڵ�ָ�������
//		if (pcur == T)
//			T = pcur->left;
//		else if (parent->left == pcur) {
//			parent->left = pcur->left;
//		}
//		else
//			parent->right = pcur->left;
//		del = pcur;
//	}
//	//pcur���Һ��Ӷ���Ϊ��
//	else {
//		//�ҵ��ڵ�������������ڵ�
//		node* left = pcur->right;
//		parent = pcur;
//		while (left->left){
//			parent = left;
//			left = left->left;
//		}
//		del = left;
//		pcur->key = left->key;   //�����ڵ��ֵ
//		if (parent->left == left) {
//			parent->left = left->right;
//		}
//		else {
//			parent->right = left->right;
//		}
//	}
//	delete del;
//	return true;
//}
//int getLeavesConut(node* T) {
//	int leftLeavesCount;
//	int rightLeavesCount;
//	if (T == NULL) {
//		return 0;
//	}
//	else if (T->left == NULL && T->right == NULL) {
//		return 1;
//	}
//	else {
//		leftLeavesCount = getLeavesConut(T->left);
//		rightLeavesCount = getLeavesConut(T->right);
//		return leftLeavesCount + rightLeavesCount;
//	}
//}
//int main() {
//	int n=0;
//	cout << "������ؼ��������";
//	cin >> n;
//	int* arr = (int*)malloc(sizeof(int)*n);
//	cout << "������ؼ�������(�м��ÿո����)��";
//	for (int i = 0; i < n; i++) {
//		cin >> arr[i];
//	}
//	node* Tree = Create_BST(arr, n);
//	cout << "��������Ϊ��";
//	inOrder(Tree);
//	cout<<endl << "��������Ҫ����Ĺؼ��룺";
//	int x;
//	cin >> x;
//	BST_Insert(&Tree, x);//����ؼ���
//	cout << "��������Ϊ��";
//	inOrder(Tree);
//	cout << endl << "��������Ҫ���ҵĹؼ��룺";
//	cin >> x;
//	cout << (BST_Search(Tree, x) != NULL?"���ҵ�":"δ�ҵ��ùؼ���Ľڵ�");
//	cout <<endl<< "������Ҫɾ���ڵ�Ĺؼ��룺";
//	cin >> x;
//	deleteNode(Tree, x);
//	cout << "��������Ϊ��";
//	inOrder(Tree);
//	cout << endl<<"Ҷ�ӽ�����Ϊ��";
//	cout << getLeavesConut(Tree);
//	//preOrder(Tree);
//	free(arr);
//	system("pause");
//	return 0;
//}
//
///*
//70 105 115 104 67 46 99 111 109
//*/
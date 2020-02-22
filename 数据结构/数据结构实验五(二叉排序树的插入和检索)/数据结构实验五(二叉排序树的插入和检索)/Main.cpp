//#include<iostream>
//#include<stdlib.h>
//
//using namespace std;
//struct node {//二叉树结点定义
//	int key;
//	node* left;
//	node* right;
//};
//void PrintTreeRootLeft(node* r, int layer)
////r是树中一棵子树的根，打印以结点r为根的子树，
////layer是r在树中所处的层,约定树的根结点的层号为1
//{
//	/*请在BEGIN和END之间实现你的代码*/
//	/*****BEGIN*****/
//
//	/******END******/
//	/*请不要修改[BEGIN,END]区域外的代码*/
//}
//bool BST_Insert(node** Tree, int k) {//插入：将关键字k插入到二叉排序树
//	if (*Tree == NULL) {
//		node* Tnode = new node;
//		Tnode->key = k;
//		Tnode->left = NULL;
//		Tnode->right = NULL;
//		*Tree = Tnode;
//		return true;  //插入成功
//	}
//	else if (k == (*Tree)->key)
//		return false;  // 树中存在相同关键字,插入失败
//	else if (k < (*Tree)->key)
//		return BST_Insert(&(*Tree)->left, k);
//	else
//		return BST_Insert(&(*Tree)->right, k);
//}
//node* Create_BST(int arr[], int n)  {//创建二叉排序树
//	node* T = NULL;  // 初始时为空树
//	for (int i = 0; i < n; ++i) {
//		BST_Insert(&T, arr[i]);
//	}
//	return T;
//}
//void preOrder(node *T) {//递归先序遍历
//	if (T == NULL)
//		return;
//	cout << T->key << " ";
//	preOrder(T->left);
//	preOrder(T->right);
//}
//void inOrder(node *T) {//递归中序遍历
//	if (T == NULL)
//		return;
//	inOrder(T->left);
//	cout << T->key << " ";
//	inOrder(T->right);
//}
//node* BST_Search(node* T, int k) {//递归检索
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
//	if (pcur->left == NULL) {     //只有右孩子
//		//如果pcur就是根节点的话，让根节点指向根的右
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
//	else if (pcur->right == NULL)     //只有左孩子
//	{
//		//如果是根节点，让根节点指向根的左
//		if (pcur == T)
//			T = pcur->left;
//		else if (parent->left == pcur) {
//			parent->left = pcur->left;
//		}
//		else
//			parent->right = pcur->left;
//		del = pcur;
//	}
//	//pcur左右孩子都不为空
//	else {
//		//找到节点右子树的最左节点
//		node* left = pcur->right;
//		parent = pcur;
//		while (left->left){
//			parent = left;
//			left = left->left;
//		}
//		del = left;
//		pcur->key = left->key;   //交换节点的值
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
//	cout << "请输入关键码个数：";
//	cin >> n;
//	int* arr = (int*)malloc(sizeof(int)*n);
//	cout << "请输入关键码序列(中间用空格隔开)：";
//	for (int i = 0; i < n; i++) {
//		cin >> arr[i];
//	}
//	node* Tree = Create_BST(arr, n);
//	cout << "中序序列为：";
//	inOrder(Tree);
//	cout<<endl << "请输入需要插入的关键码：";
//	int x;
//	cin >> x;
//	BST_Insert(&Tree, x);//插入关键码
//	cout << "中序序列为：";
//	inOrder(Tree);
//	cout << endl << "请输入需要查找的关键码：";
//	cin >> x;
//	cout << (BST_Search(Tree, x) != NULL?"已找到":"未找到该关键码的节点");
//	cout <<endl<< "请输入要删除节点的关键码：";
//	cin >> x;
//	deleteNode(Tree, x);
//	cout << "中序序列为：";
//	inOrder(Tree);
//	cout << endl<<"叶子结点个数为：";
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
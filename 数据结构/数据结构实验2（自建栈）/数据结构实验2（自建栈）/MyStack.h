#pragma once
template<class T> struct node {
	T value; //储存的值
	node<T>* next;
	node() :next(nullptr) {} //构造函数，初始化next指针
	node(T t) :value(t), next(nullptr) {}//初始化节点数据
};
template<class T> class MyStack {
	int cnts; //入栈数量
	node<T> *head; //栈的头部
public:
	MyStack();
	void push(T arg); //入栈
	T pop(); //出栈
	T top(); //获取栈顶元素
	int size(); //获取栈内元素个数
	bool empty(); //判断空
};


template<class T> MyStack<T>::MyStack() {
	cnts = 0;
	head = new node<T>;
}

template<class T> void MyStack<T>::push(T arg) {
	node<T> *pnode = new node<T>(arg); //申请入栈元素的空间
	pnode->next = head->next;
	head->next = pnode;
	cnts++;
}

template<class T> T MyStack<T>::pop() {
	if (head->next != nullptr) {
		node<T>* temp = head->next;
		head->next = head->next->next;
		T popVal = temp->value;
		delete temp;
		cnts--;
		return popVal;
	}
}

template<class T> T MyStack<T>::top() {
	if (head->next != nullptr) {
		return head->next->value;
	}
}

template<class T> int MyStack<T>::size() {
	return cnts;
}

template<class T> bool MyStack<T>::empty() {
	if (cnts)
		return false;
	else
		return true;
}


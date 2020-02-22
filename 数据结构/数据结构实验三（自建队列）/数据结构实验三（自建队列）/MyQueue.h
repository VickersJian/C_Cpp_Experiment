//#pragma once
//#ifndef MYQUEUE_H
//#define MYQUEUE_H
//template<class T> struct node {
//	T value; //储存的值
//	node<T>* next;
//	node() :next(nullptr) {} //构造函数，初始化next指针
//	node(T t) :value(t), next(nullptr) {}//初始化节点数据
//};
//
//template<class T> class MyQueue
//{
//private:
//	int cnts; //入队数量
//	node<T> *head; //队的头部
//	node<T> *tail; //队的尾部
//public:
//	MyQueue();
//	void push(T arg); //入队
//	T pop(); //出队
//	T front(); //获取队头元素
//	int size(); //获取队内元素个数
//	bool empty(); //判断空
//};
//
//template<class T> MyQueue<T>::MyQueue() {
//	cnts = 0;
//	head = tail = new node<T>;
//}
//
//template<class T> void MyQueue<T>::push(T arg) {
//	node<T> *pnode = new node<T>(arg); //申请入栈元素的空间
//	tail->next = pnode;
//	tail = pnode;
//	cnts++;
//}
//
//template<class T> T MyQueue<T>::pop() {
//	if (head->next != nullptr) {
//		node<T>* temp = head->next;
//		head->next = head->next->next;
//		T popVal = temp->value;
//		delete temp;
//		cnts--;
//		if (empty()) {
//			tail = head;
//		}
//		return popVal;
//	}
//}
//
//template<class T> T MyQueue<T>::front() {
//	if (head->next != nullptr) {
//		return head->next->value;
//	}
//}
//
//template<class T> int MyQueue<T>::size() {
//	return cnts;
//}
//
//template<class T> bool MyQueue<T>::empty() {
//	if (cnts)
//		return false;
//	else
//		return true;
//}
//
//
//#endif // MYQUEUE_H
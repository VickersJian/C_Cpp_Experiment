//#pragma once
//#ifndef MYQUEUE_H
//#define MYQUEUE_H
//template<class T> struct node {
//	T value; //�����ֵ
//	node<T>* next;
//	node() :next(nullptr) {} //���캯������ʼ��nextָ��
//	node(T t) :value(t), next(nullptr) {}//��ʼ���ڵ�����
//};
//
//template<class T> class MyQueue
//{
//private:
//	int cnts; //�������
//	node<T> *head; //�ӵ�ͷ��
//	node<T> *tail; //�ӵ�β��
//public:
//	MyQueue();
//	void push(T arg); //���
//	T pop(); //����
//	T front(); //��ȡ��ͷԪ��
//	int size(); //��ȡ����Ԫ�ظ���
//	bool empty(); //�жϿ�
//};
//
//template<class T> MyQueue<T>::MyQueue() {
//	cnts = 0;
//	head = tail = new node<T>;
//}
//
//template<class T> void MyQueue<T>::push(T arg) {
//	node<T> *pnode = new node<T>(arg); //������ջԪ�صĿռ�
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
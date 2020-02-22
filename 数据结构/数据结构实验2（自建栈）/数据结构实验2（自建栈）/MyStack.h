#pragma once
template<class T> struct node {
	T value; //�����ֵ
	node<T>* next;
	node() :next(nullptr) {} //���캯������ʼ��nextָ��
	node(T t) :value(t), next(nullptr) {}//��ʼ���ڵ�����
};
template<class T> class MyStack {
	int cnts; //��ջ����
	node<T> *head; //ջ��ͷ��
public:
	MyStack();
	void push(T arg); //��ջ
	T pop(); //��ջ
	T top(); //��ȡջ��Ԫ��
	int size(); //��ȡջ��Ԫ�ظ���
	bool empty(); //�жϿ�
};


template<class T> MyStack<T>::MyStack() {
	cnts = 0;
	head = new node<T>;
}

template<class T> void MyStack<T>::push(T arg) {
	node<T> *pnode = new node<T>(arg); //������ջԪ�صĿռ�
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


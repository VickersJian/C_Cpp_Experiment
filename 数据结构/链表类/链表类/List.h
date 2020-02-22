#pragma once
template<typename T> class List
{
private:
	T* listHead = nullptr;
public:
	T* creatList() {
		if (listHead == nullptr) {
			listHead = new T;
		}
		return listHead;
	}
	bool addElement(T element) {

	}
	bool deleteElement(T element);
	T* findElement(T element) {
		T* temp = listHead;
		while (temp!=nullptr) {
			temp
		}
	}
	List();
	~List();
};


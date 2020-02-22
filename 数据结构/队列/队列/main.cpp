#include<iostream>
using namespace std;
struct list {
	int info;
	list* link;
};
typedef list* pList;
void pur_LinkList(list* H) {
	pList p, q, r, s;
	p = H->link;
	if (p != nullptr) {
		while (p!=nullptr) {
			s = p;
			q = p->link;
			while (q) {
				if (q->info == p->info) {
					s->link = q->link; 
					free(q); 
					q = s->link;
				}
				else { 
					s = q; 
					q = q->link; }
			}
			p = p->link;
		}
	}
}

void print(list* head) {
	head = head->link;
	while (head) {
		cout << head->info << endl;
		head = head->link;
	}
}

int main() {
	pList head, p;
	p = head = new list;
	head->link = nullptr;
	p->link = new list;
	p = p->link;
	p->info = 10;
	p->link = nullptr;
	for (int i = 0; i < 2; i++) {
		p->link = new list;
		p = p->link;
		p->info = 20;
		p->link = nullptr;
	}
	for (int i = 0; i < 2; i++) {
		p->link = new list;
		p = p->link;
		p->info = 10;
		p->link = nullptr;
	}
	p = head;
	print(p);
	cout << "\n\n***************" << endl;
	p = head;
	pur_LinkList(p);
	p = head;
	print(p);
	system("pause");
	return 0;
}


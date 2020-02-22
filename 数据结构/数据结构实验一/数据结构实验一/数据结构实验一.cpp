#include <iostream>
#include <stdio.h> 
using namespace std;
//存放多项式某项的结点结构 
struct Poly {
	int exp;  // 表示指数
	int coef; //表示系数
	Poly* next = NULL;  //指向下一个结点的指针 
};
//函数功能：生成多项式
Poly* createPoly(int x) {
	//头指针不存放多项式的项。 
	int coef;
	int exp;
	Poly* head = new Poly;
	head->next = NULL;
	Poly* p = head;
	Poly* data;
	int i = 1;
	while (true) {
		cout << "请输入第" << i << "项的系数：";
		cin >> coef;
		cout << "请输入第" << i << "项的指数：";
		cin >> exp;
		data = new Poly;
		data->coef = coef;
		data->exp = exp;
		data->next = NULL;
		p->next = data;//链接
		p = data;
		if (i == x) {
			break;
		}
		i++;
	}
	return head;
}
//函数功能：进行多项式相加
Poly* addPoly(Poly* polyAddLeft, Poly* polyAddRight) {
	Poly* head = new Poly;
	head->next = NULL;
	Poly* pc = head;
	Poly* pa = polyAddLeft->next;
	Poly* pb = polyAddRight->next;
	Poly* temp;
	while (pa != NULL && pb != NULL) {//逐项对比相加 
		if (pa->exp < pb->exp) {// pa指数<pb指数,pa加入pc 
			pc->next = pa;
			pc = pc->next;
			pa = pa->next;
		}
		else
			if (pa->exp > pb->exp) {//pa指数>pb指数，pb加入pc 
				pc->next = pb;
				pc = pc->next;
				pb = pb->next;
			}
			else {
				//指数相等，同项相加 
				if ((pa->coef + pb->coef) != 0) {
					pa->coef = pa->coef + pb->coef;
					pc->next = pa;
					pc = pc->next;
					pa = pa->next;
					temp = pb;
					pb = pb->next;
					delete(temp);
				}
				else {//系数之和为0则删除 
					temp = pa;
					pa = pa->next;
					delete(temp);
					temp = pb;
					pb = pb->next;
					delete(temp);
				}
			}
	}
	if (pa != NULL)//剩余部分并入pc 
		pc->next = pa;
	if (pb != NULL)
		pc->next = pb;
	return head;
}
//多项式减法
Poly* subPoly(Poly* polySubLeft, Poly* polySubRight) {
	Poly* temp = polySubRight->next;
	while (temp != NULL) {
		temp->coef = -temp->coef;
		temp = temp->next;
	}
	return addPoly(polySubLeft, polySubRight);
}
//输出多项式
void printPoly(Poly* poly) {
	poly = poly->next;
	while (poly != NULL) {
		cout << poly->coef << "x^" << poly->exp;
		if (poly->next == NULL) break;
		cout << (poly->next->coef >= 0 ? "+" : "");
		poly = poly->next;
	}
}
int main() {
	int i = 0;
	//while (true) {
	//	cout << "输入1进行多项式加法，输入2进行多项式减法" << endl;
	//	cin >> i;
	//	if (i == 1 || i == 2)
	//		break;
	//	cout << "只能输入1或2" << endl;
	//}
	cout << "请输入第一个多项式的项数：";
	int x = 0;
	cin >> x;
	Poly* poly1 = createPoly(x);
	cout << "第一个多项式为：";
	printPoly(poly1);
	cout << endl;
	cout << endl << "请输入第二个多项式的项数：";
	x = 0;
	cin >> x;
	Poly* poly2 = createPoly(x);
	cout << "第二个多项式为：";
	printPoly(poly2);
	cout << endl<<endl;
	Poly* polyAddResult = nullptr;
	//if (i == 1) {
	//	//加法
	//	polyAddResult = addPoly(polyAddLeft, polyAddRight);
	//}
	//else {
	//	//减法
	//	polyAddResult = subPoly(polyAddLeft, polyAddRight);
	//}
	polyAddResult = addPoly(poly1, poly2);
	cout << "请输入第三个多项式的项数：";
	x = 0;
	cin >> x;
	Poly* poly3 = createPoly(x);
	cout << "第三个多项式为：";
	printPoly(poly3);
	Poly* polyAddResult2 = nullptr;
	polyAddResult2 = subPoly(polyAddResult, poly3);
	cout << endl;
	cout << endl << "运算结果为：";
	printPoly(polyAddResult2);
	cout << endl;
	return 0;
}

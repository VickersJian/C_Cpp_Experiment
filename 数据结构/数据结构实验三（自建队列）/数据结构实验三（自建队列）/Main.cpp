////#include"MyQueue.h"
//#include<queue>
//
//#include<stdlib.h>
//#include<iostream>
//#include<string>
//#include<stack>
//using namespace std;
//
//int farmer(int location) {//ũ���λ��
//	return (0 != (location & 0x08));
//}
//
//int wolf(int location) {//�ǵ�λ��
//	return (0 != (location & 0x04));
//}
//
//int cabbage(int location) {//�ײ˵�λ��
//	return (0 != (location & 0x02));
//}
//
//int goat(int location) {//���λ��
//	return (0 != (location & 0x01));
//}
//
//int safe(int location) {//�Ƿ�ȫ
//	if ((goat(location) == cabbage(location)) && (goat(location) != farmer(location)))//���ڰײ��Ա�ʱ��ũ���Ƿ��������
//	{
//		return 0;
//	}
//	if ((goat(location) == wolf(location)) && (goat(location) != farmer(location)))//���������ʱ�����Ƿ���ũ�����
//	{
//		return 0;
//	}
//	return 1;
//}
//
//string outputLocation(int location) {
//	string output;
//	output.append("�ϰ���");
//	if (farmer(location) == 0) {
//		output.append("ũ��");
//	}
//	if (wolf(location) == 0) {
//		output.append("�ǣ�");
//	}
//	if (cabbage(location) == 0) {
//		output.append("�ײˣ�");
//	}
//	if (goat(location) == 0) {
//		output.append("��");
//	}
//	output.replace(output.end() - 2, output.end(), "��");
//	output.append("    ������");
//	if (farmer(location) == 1) {
//		output.append("ũ��");
//	}
//	if (wolf(location) == 1) {
//		output.append("�ǣ�");
//	}
//	if (cabbage(location) == 1) {
//		output.append("�ײˣ�");
//	}
//	if (goat(location) == 1) {
//		output.append("��");
//	}
//	output.replace(output.end()-2,output.end(), "��");
//	return output;
//}
//
//void farmerProblem() {//��ʼ���ũ������
//	int i, movers, location, newlocation;
//	int route[16];//���ڼ�¼�ѿ��ǵ�״̬·��;
//	queue<int> moveTo; //����һ������
//	moveTo.push(0x00);
//	for (i = 0; i < 16; i++) {
//		route[i] = -1;//��״̬��Ϊ-1;
//	}
//	route[0] = 0;
//	while (!moveTo.empty() && (route[15] == -1)) { //�ж϶����Ƿ�Ϊ�գ��������һ��״̬Ϊ-1
//		location = moveTo.front(); //����ǰ��״̬ȡ����
//		moveTo.pop();//ɾ����ǰ��״̬
//		for (movers = 1; movers <= 8; movers <<= 1) { //�������������״̬��ũ���ǣ��ײˣ���
//			if (0 != (location & 0x08) == (0 != (location & movers))) { //�ж�ũ���λ���Ƿ��ÿ��������һ����
//				newlocation = location ^ (0x08 | movers);  //�õ�ũ��������λ�ƺ����״̬
//				if (safe(newlocation) && (route[newlocation] == -1)) {
//					route[newlocation] = location; //���жϹ���λ�÷����Ӧ������������鵱��
//					moveTo.push(newlocation);//��newLocation������е���
//				}
//			}
//		}
//	}
//	if (route[15] != -1) { //����״̬1111�Ѿ��ﵽ
//		stack<int> temp;
//		for (location = 15; location >= 0; location = route[location]) {
//			temp.push(location);
//			if (location == 0) break;	
//		}
//		int i = 0;
//		while (!temp.empty()) {
//			if (i == 0) {
//				cout << "��ʼ��" << outputLocation(temp.top()) << endl;
//			}
//			else {
//				cout << "��" << i << "��������" << outputLocation(temp.top()) << endl;
//			}
//			i++;
//			temp.pop();
//		}
//	}
//	else {
//		printf("No solution.\n");
//	}
//}
//
//int main() {
//	farmerProblem();
//	system("pause");
//	return 0;
//}

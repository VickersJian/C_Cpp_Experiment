#include<iostream>
#include<vector>
#include<string>
using namespace std;
struct Edge{//ͼ�ı�
	int number;//�ڵ���
	int weight;
	Edge(int number, int weight) {
		this->number = number;
		this->weight = weight;
	}
};
struct MapNode {//��ͼ�ϵĽڵ�
	int code;//����
	string name;//��������
	string introduction;//���ڴ�ż��
};
vector<Edge>* edge;//���ڴ�ű�
MapNode* map;//���ڴ�Žڵ���Ϣ
int totalPoint;//��������
void setEdge(int code1,int code2,int weight) {
	int number1=-1;
	int number2 = -1;
	for (int i = 0; i < totalPoint; i++) {
		if (map[i].code == code1) {
			number1 = i;
		}
		if (map[i].code == code2) {
			number2 = i;
		}
		if (number1 != -1 && number2 != -1)
			break;
	}
	edge[number1].push_back(Edge(number2, weight));
	edge[number2].push_back(Edge(number1, weight));
}
int main() {
	cout << "�����볡��������";
	cin >> totalPoint;
	edge = (vector<Edge>*)malloc(totalPoint * sizeof(vector<Edge>));
	map = (MapNode*)malloc(totalPoint * sizeof(MapNode));
	cout << "������ÿ����������Ϣ����ʽΪ������ �������� ��顱��" << endl;
	for (int i = 0; i < totalPoint; i++) {
		cin >> map[i].code >> map[i].name >> map[i].introduction;
	}
	cout << "������ÿ������֮���·������ʽΪ������1���� ����2���� ��������·��Ȩ�ء���" << endl;
	for (int i = 0; i < totalPoint; i++) {
		int code1, code2, weight;
		cin >> code1 >> code2 >> weight;
		setEdge(code1, code2, weight);
	}

	return 0;
}
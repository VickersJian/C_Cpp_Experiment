#include<iostream>
#include<vector>
#include<string>
using namespace std;
struct Edge{//图的边
	int number;//节点编号
	int weight;
	Edge(int number, int weight) {
		this->number = number;
		this->weight = weight;
	}
};
struct MapNode {//地图上的节点
	int code;//代号
	string name;//场景名字
	string introduction;//用于存放简介
};
vector<Edge>* edge;//用于存放边
MapNode* map;//用于存放节点信息
int totalPoint;//场景总数
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
	cout << "请输入场景总数：";
	cin >> totalPoint;
	edge = (vector<Edge>*)malloc(totalPoint * sizeof(vector<Edge>));
	map = (MapNode*)malloc(totalPoint * sizeof(MapNode));
	cout << "请输入每个场景的信息（格式为“代号 场景名字 简介”）" << endl;
	for (int i = 0; i < totalPoint; i++) {
		cin >> map[i].code >> map[i].name >> map[i].introduction;
	}
	cout << "请输入每个场景之间的路径（格式为“场景1代号 场景2代号 两场景间路径权重”）" << endl;
	for (int i = 0; i < totalPoint; i++) {
		int code1, code2, weight;
		cin >> code1 >> code2 >> weight;
		setEdge(code1, code2, weight);
	}

	return 0;
}
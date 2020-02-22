//#include<iostream>
//#include<queue>
//#include"MyStack.h"
//using namespace std;
//int maze[12][12] = {//�Թ�
//	1,1,1,1,1,1,1,1,1,1,1,1,
//	1,0,1,1,1,0,0,0,0,0,0,1,
//	1,0,0,0,1,0,0,1,1,0,0,1,
//	1,0,1,0,1,1,0,1,1,0,0,1,
//	1,0,1,0,0,1,0,1,1,0,0,1,
//	1,0,1,0,0,1,0,1,1,0,0,1,
//	1,1,1,1,0,1,0,1,0,0,0,1,
//	1,0,0,1,0,0,0,1,0,1,1,1,
//	1,0,0,1,0,0,0,1,0,1,1,1,
//	1,0,1,1,0,1,0,1,0,1,0,1,
//	1,0,0,0,0,1,0,1,1,0,0,1,
//	1,1,1,1,1,1,1,1,1,1,1,1,
//};
//int direction[8][2] = {{ 0, 1},{ 1, 1},{ 1, 0},{ 1,-1},{ 0,-1},{-1,-1},{-1, 0},{-1, 1}};//����
//class Dot {//���з���ĵ㣬������������㷨
//public:
//	int x;
//	int y;
//	int direction;
//	Dot() {}
//	Dot(int x, int y, int direction) {
//		this->x = x;
//		this->y = y;
//		this->direction = direction;
//	}
//};
//class wideDot {//������һ���ڵ�ĵ㣬���ڹ�������㷨
//public:
//	int x;
//	int y;
//	wideDot* parent;
//	wideDot() {}
//	wideDot(int x, int y, wideDot* parent) {
//		this->x = x;
//		this->y = y;
//		this->parent = parent;
//	}
//};
//bool DFS(int(*maze)[12], int(*direction)[2], int x1, int y1, int x2, int y2) {//��������㷨
//	MyStack<Dot> path;
//	int mark[12][12] = { 0 };
//	path.push(Dot(x1, y1, -1));//����ڽ���
//	while (!path.empty()) {
//		Dot now = path.top();
//		path.pop();
//		now.direction++;
//		while (now.direction < 8) {
//			Dot next(now.x + direction[now.direction][0], now.y + direction[now.direction][1], -1);
//			if (next.x == x2 && next.y == y2 && maze[next.x][next.y] == 0) {
//				path.push(now);
//				path.push(next);
//				cout << "��" << path.size() - 1 << "��" << endl << "����Ϊ��";
//				MyStack<Dot> output;
//				while (!path.empty()) {
//					output.push(path.top());
//					path.pop();
//				}
//				while (!output.empty()) {
//					Dot dot = output.top();
//					maze[dot.x][dot.y] = 2;
//					cout << "(" << dot.x << "," << dot.y << ")" << (output.size() == 1 ? "" : "->");
//					output.pop();
//				}
//				cout << endl;
//				return true;
//			}
//			if (maze[next.x][next.y] == 0 && mark[next.x][next.y] == 0) {
//				mark[next.x][next.y] = 1;
//				path.push(now);
//				now = next;
//			}
//			now.direction++;
//		}
//	}
//	cout << "δ�ҵ����е�·��" << endl;
//	return false;
//}
//bool BFS(int(*maze)[12], int x1, int y1, int x2, int y2) {//��������㷨
//	wideDot* wb = nullptr;//�����յ�
//	queue<wideDot*> q;
//	int mark[12][12] = { 0 };
//	q.push(new wideDot(x1, y1, nullptr));
//	while (!q.empty()) {
//		wideDot* b = q.front();
//		q.pop();
//		int x = b->x;
//		int y = b->y;
//		if (x == x2 && y == y2) { //�жϵ�ǰ�ڵ��Ƿ��Ѵ��յ�
//			wb = b;
//			MyStack<wideDot*> output;
//			while (wb != nullptr) {
//				output.push(wb);
//				maze[wb->x][wb->y] = 2;
//				wb = wb->parent;
//			}
//			cout << "��" << output.size() - 1 << "��" << endl << "����Ϊ��";
//			while (!output.empty()) {
//				cout << "(" << ((wideDot*)output.top())->x << "," << ((wideDot*)output.top())->y << ")" << (output.size() == 1 ? "" : "->");
//				output.pop();
//			}
//			cout << endl;
//			return true;
//		}
//		if (maze[x][y + 1] == 0 && mark[x][y + 1] == 0) { //�жϵ�ǰ�ڵ���ܷ�������һ��������ܣ�����һ���ڵ�������
//			q.push(new wideDot(x, y + 1, b));//�ӽڵ����
//			mark[x][y + 1] = 1;//����ѷ���
//		}
//		if (maze[x + 1][y + 1] == 0 && mark[x + 1][y + 1] == 0) {
//			q.push(new wideDot(x + 1, y + 1, b));
//			mark[x + 1][y + 1] = 1;
//		}
//		if (maze[x + 1][y] == 0 && mark[x + 1][y] == 0) {
//			q.push(new wideDot(x + 1, y, b));
//			mark[x + 1][y] = 1;
//		}
//		if (maze[x + 1][y - 1] == 0 && mark[x + 1][y - 1] == 0) {
//			q.push(new wideDot(x + 1, y - 1, b));
//			mark[x + 1][y - 1] = 1;
//		}
//		if (maze[x][y - 1] == 0 && mark[x][y - 1] == 0) {
//			q.push(new wideDot(x, y - 1, b));
//			mark[x][y - 1] = 1;
//		}
//		if (maze[x - 1][y - 1] == 0 && mark[x - 1][y - 1] == 0) {
//			q.push(new wideDot(x - 1, y - 1, b));
//			mark[x - 1][y - 1] = 1;
//		}
//		if (maze[x - 1][y] == 0 && mark[x - 1][y] == 0) {
//			q.push(new wideDot(x - 1, y, b));
//			mark[x - 1][y] = 1;
//		}
//		if (maze[x - 1][y + 1] == 0 && mark[x - 1][y + 1] == 0) {
//			q.push(new wideDot(x - 1, y + 1, b));
//			mark[x - 1][y + 1] = 1;
//		}
//	}
//	cout << "δ�ҵ����е�·��" << endl;
//	return false;
//}
//int main() {
//	bool isFound = false;
//	//isFound = DFS(maze, direction, 1, 1, 10, 10);
//	isFound = BFS(maze, 1, 1, 10, 10);
//	if (isFound == true) {
//		cout << "·��ͼΪ��������2Ϊ·�ߣ�" << endl;
//		for (int i = 1; i <= 10; i++) {
//			for (int j = 1; j <= 10; j++)
//				cout << maze[i][j] << "  ";
//			cout << endl;
//		}
//	}
//	system("pause");
//	return 0;
//}

#include<iostream>
#include "MyStack.h"
#include<queue>
using namespace std;
int maze[12][12] = {//�Թ�
	1,1,1,1,1,1,1,1,1,1,1,1,
	1,0,1,1,1,0,0,0,0,0,0,1,
	1,0,0,0,1,0,0,1,1,0,0,1,
	1,0,1,0,1,1,0,1,1,0,0,1,
	1,0,1,0,0,1,0,1,1,0,0,1,
	1,0,1,0,0,1,0,1,1,0,0,1,
	1,1,1,1,0,1,0,1,0,0,0,1,
	1,0,0,1,0,0,0,1,0,1,1,1,
	1,0,0,1,0,0,0,1,0,1,1,1,
	1,0,1,1,0,1,0,1,0,1,0,1,
	1,0,0,0,0,1,0,0,1,0,0,1,
	1,1,1,1,1,1,1,1,0,1,1,1,
};
int direction[8][2] = { { 0, 1},{ 1, 1},{ 1, 0},{ 1,-1},{ 0,-1},{-1,-1},{-1, 0},{-1, 1} };//����
class Dot {//���з���ĵ㣬������������㷨
public:
	int x;
	int y;
	int direction;
	Dot() {}
	Dot(int x, int y, int direction) {
		this->x = x;
		this->y = y;
		this->direction = direction;
	}
};
class wideDot {//������һ���ڵ�ĵ㣬���ڹ�������㷨
public:
	int x;
	int y;
	wideDot* parent;
	wideDot() {}
	wideDot(int x, int y, wideDot* parent) {
		this->x = x;
		this->y = y;
		this->parent = parent;
	}
};

bool DFS(int(*maze)[12], int(*direction)[2], int x1, int y1, int x2, int y2) {//��������㷨
	MyStack<Dot> path;
	int mark[12][12] = { 0 };
	path.push(Dot(x1, y1, -1));//����ڽ���
	while (!path.empty()) {
		Dot now = path.top();
		path.pop();
		now.direction++;
		while (now.direction < 8) {//�˸�����
			Dot next(now.x + direction[now.direction][0], now.y + direction[now.direction][1], -1);
			if (next.x == x2 && next.y == y2 && maze[next.x][next.y] == 0) {
				path.push(now);
				path.push(next);
				cout << "��" << path.size() - 1 << "��" << endl << "����Ϊ��";
				MyStack<Dot> output;
				while (!path.empty()) {
					output.push(path.top());
					path.pop();
				}
				while (!output.empty()) {
					Dot dot = output.top();
					maze[dot.x][dot.y] = 2;
					cout << "(" << dot.x << "," << dot.y << ")" << (output.size() == 1 ? "" : "->");//���·��
					output.pop();
				}
				cout << endl;
				return true;
			}
			if (maze[next.x][next.y] == 0 && mark[next.x][next.y] == 0) {
				mark[next.x][next.y] = 1;
				path.push(now);
				now = next;
			}
			now.direction++;
		}
	}
	cout << "δ�ҵ����е�·��" << endl;//���pathΪ�գ������
	return false;
}

bool BFS(int(*maze)[12], int x1, int y1, int x2, int y2) {//��������㷨
	wideDot* wb = nullptr;//�����յ�
	queue<wideDot*> q;
	int mark[12][12] = { 0 };
	q.push(new wideDot(x1, y1, nullptr));
	while (!q.empty()) {
		wideDot* b = q.front();
		q.pop();
		int x = b->x;
		int y = b->y;
		if (x == x2 && y == y2) { //�жϵ�ǰ�ڵ��Ƿ��Ѵ��յ�
			wb = b;
			MyStack<wideDot*> output;
			while (wb != nullptr) {
				output.push(wb);
				maze[wb->x][wb->y] = '��';
				wb = wb->parent;
			}
			cout << "��" << output.size() - 1 << "��" << endl << "����Ϊ��";
			while (!output.empty()) {
				cout << "(" << ((wideDot*)output.top())->x << "," << ((wideDot*)output.top())->y << ")" << (output.size() == 1 ? "" : "->");
				output.pop();
			}
			cout << endl;
			for (int i = 1; i <= 10; i++) {
				for (int j = 1; j <= 10; j++)
					cout << mark[i][j] << "  ";
				cout << endl;
			}
			return true;
		}
		if (maze[x][y + 1] == 0 && mark[x][y + 1] == 0) { //�жϵ�ǰ�ڵ���ܷ�������һ��������ܣ�����һ���ڵ�������
			q.push(new wideDot(x, y + 1, b));//�ӽڵ����
			mark[x][y + 1] = 1;//����ѷ���
		}
		if (maze[x + 1][y + 1] == 0 && mark[x + 1][y + 1] == 0) {
			q.push(new wideDot(x + 1, y + 1, b));
			mark[x + 1][y + 1] = 1;
		}
		if (maze[x + 1][y] == 0 && mark[x + 1][y] == 0) {
			q.push(new wideDot(x + 1, y, b));
			mark[x + 1][y] = 1;
		}
		if (maze[x + 1][y - 1] == 0 && mark[x + 1][y - 1] == 0) {
			q.push(new wideDot(x + 1, y - 1, b));
			mark[x + 1][y - 1] = 1;
		}
		if (maze[x][y - 1] == 0 && mark[x][y - 1] == 0) {
			q.push(new wideDot(x, y - 1, b));
			mark[x][y - 1] = 1;
		}
		if (maze[x - 1][y - 1] == 0 && mark[x - 1][y - 1] == 0) {
			q.push(new wideDot(x - 1, y - 1, b));
			mark[x - 1][y - 1] = 1;
		}
		if (maze[x - 1][y] == 0 && mark[x - 1][y] == 0) {
			q.push(new wideDot(x - 1, y, b));
			mark[x - 1][y] = 1;
		}
		if (maze[x - 1][y + 1] == 0 && mark[x - 1][y + 1] == 0) {
			q.push(new wideDot(x - 1, y + 1, b));
			mark[x - 1][y + 1] = 1;
		}
	}
	cout << "δ�ҵ����е�·��" << endl;
	return false;
}
int main() {
	bool isFound = false;
	//isFound = DFS(maze, direction, 1, 1, 10, 10);
	isFound = BFS(maze, 1, 1, 10, 10);
	if (isFound == true) {
		cout << "·��ͼΪ��������2Ϊ·�ߣ�" << endl;
		for (int i = 1; i <= 10; i++) {
			for (int j = 1; j <= 10; j++)
				cout << maze[i][j] << "  ";
			cout << endl;
		}
	}
	system("pause");
	return 0;
}
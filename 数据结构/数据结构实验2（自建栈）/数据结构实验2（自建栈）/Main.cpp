//#include<iostream>
//#include<queue>
//#include"MyStack.h"
//using namespace std;
//int maze[12][12] = {//迷宫
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
//int direction[8][2] = {{ 0, 1},{ 1, 1},{ 1, 0},{ 1,-1},{ 0,-1},{-1,-1},{-1, 0},{-1, 1}};//方向
//class Dot {//带有方向的点，用于深度优先算法
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
//class wideDot {//带有上一个节点的点，用于广度优先算法
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
//bool DFS(int(*maze)[12], int(*direction)[2], int x1, int y1, int x2, int y2) {//深度优先算法
//	MyStack<Dot> path;
//	int mark[12][12] = { 0 };
//	path.push(Dot(x1, y1, -1));//从入口进入
//	while (!path.empty()) {
//		Dot now = path.top();
//		path.pop();
//		now.direction++;
//		while (now.direction < 8) {
//			Dot next(now.x + direction[now.direction][0], now.y + direction[now.direction][1], -1);
//			if (next.x == x2 && next.y == y2 && maze[next.x][next.y] == 0) {
//				path.push(now);
//				path.push(next);
//				cout << "共" << path.size() - 1 << "步" << endl << "步骤为：";
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
//	cout << "未找到可行的路径" << endl;
//	return false;
//}
//bool BFS(int(*maze)[12], int x1, int y1, int x2, int y2) {//广度优先算法
//	wideDot* wb = nullptr;//遍历终点
//	queue<wideDot*> q;
//	int mark[12][12] = { 0 };
//	q.push(new wideDot(x1, y1, nullptr));
//	while (!q.empty()) {
//		wideDot* b = q.front();
//		q.pop();
//		int x = b->x;
//		int y = b->y;
//		if (x == x2 && y == y2) { //判断当前节点是否已达终点
//			wb = b;
//			MyStack<wideDot*> output;
//			while (wb != nullptr) {
//				output.push(wb);
//				maze[wb->x][wb->y] = 2;
//				wb = wb->parent;
//			}
//			cout << "共" << output.size() - 1 << "步" << endl << "步骤为：";
//			while (!output.empty()) {
//				cout << "(" << ((wideDot*)output.top())->x << "," << ((wideDot*)output.top())->y << ")" << (output.size() == 1 ? "" : "->");
//				output.pop();
//			}
//			cout << endl;
//			return true;
//		}
//		if (maze[x][y + 1] == 0 && mark[x][y + 1] == 0) { //判断当前节点的能否向下走一步，如果能，则将下一步节点加入队列
//			q.push(new wideDot(x, y + 1, b));//子节点入队
//			mark[x][y + 1] = 1;//标记已访问
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
//	cout << "未找到可行的路径" << endl;
//	return false;
//}
//int main() {
//	bool isFound = false;
//	//isFound = DFS(maze, direction, 1, 1, 10, 10);
//	isFound = BFS(maze, 1, 1, 10, 10);
//	if (isFound == true) {
//		cout << "路径图为：（数字2为路线）" << endl;
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
int maze[12][12] = {//迷宫
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
int direction[8][2] = { { 0, 1},{ 1, 1},{ 1, 0},{ 1,-1},{ 0,-1},{-1,-1},{-1, 0},{-1, 1} };//方向
class Dot {//带有方向的点，用于深度优先算法
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
class wideDot {//带有上一个节点的点，用于广度优先算法
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

bool DFS(int(*maze)[12], int(*direction)[2], int x1, int y1, int x2, int y2) {//深度优先算法
	MyStack<Dot> path;
	int mark[12][12] = { 0 };
	path.push(Dot(x1, y1, -1));//从入口进入
	while (!path.empty()) {
		Dot now = path.top();
		path.pop();
		now.direction++;
		while (now.direction < 8) {//八个方向
			Dot next(now.x + direction[now.direction][0], now.y + direction[now.direction][1], -1);
			if (next.x == x2 && next.y == y2 && maze[next.x][next.y] == 0) {
				path.push(now);
				path.push(next);
				cout << "共" << path.size() - 1 << "步" << endl << "步骤为：";
				MyStack<Dot> output;
				while (!path.empty()) {
					output.push(path.top());
					path.pop();
				}
				while (!output.empty()) {
					Dot dot = output.top();
					maze[dot.x][dot.y] = 2;
					cout << "(" << dot.x << "," << dot.y << ")" << (output.size() == 1 ? "" : "->");//输出路径
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
	cout << "未找到可行的路径" << endl;//如果path为空，则输出
	return false;
}

bool BFS(int(*maze)[12], int x1, int y1, int x2, int y2) {//广度优先算法
	wideDot* wb = nullptr;//遍历终点
	queue<wideDot*> q;
	int mark[12][12] = { 0 };
	q.push(new wideDot(x1, y1, nullptr));
	while (!q.empty()) {
		wideDot* b = q.front();
		q.pop();
		int x = b->x;
		int y = b->y;
		if (x == x2 && y == y2) { //判断当前节点是否已达终点
			wb = b;
			MyStack<wideDot*> output;
			while (wb != nullptr) {
				output.push(wb);
				maze[wb->x][wb->y] = '♂';
				wb = wb->parent;
			}
			cout << "共" << output.size() - 1 << "步" << endl << "步骤为：";
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
		if (maze[x][y + 1] == 0 && mark[x][y + 1] == 0) { //判断当前节点的能否向下走一步，如果能，则将下一步节点加入队列
			q.push(new wideDot(x, y + 1, b));//子节点入队
			mark[x][y + 1] = 1;//标记已访问
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
	cout << "未找到可行的路径" << endl;
	return false;
}
int main() {
	bool isFound = false;
	//isFound = DFS(maze, direction, 1, 1, 10, 10);
	isFound = BFS(maze, 1, 1, 10, 10);
	if (isFound == true) {
		cout << "路径图为：（数字2为路线）" << endl;
		for (int i = 1; i <= 10; i++) {
			for (int j = 1; j <= 10; j++)
				cout << maze[i][j] << "  ";
			cout << endl;
		}
	}
	system("pause");
	return 0;
}
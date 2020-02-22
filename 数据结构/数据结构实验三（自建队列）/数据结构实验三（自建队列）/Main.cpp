////#include"MyQueue.h"
//#include<queue>
//
//#include<stdlib.h>
//#include<iostream>
//#include<string>
//#include<stack>
//using namespace std;
//
//int farmer(int location) {//农夫的位置
//	return (0 != (location & 0x08));
//}
//
//int wolf(int location) {//狼的位置
//	return (0 != (location & 0x04));
//}
//
//int cabbage(int location) {//白菜的位置
//	return (0 != (location & 0x02));
//}
//
//int goat(int location) {//羊的位置
//	return (0 != (location & 0x01));
//}
//
//int safe(int location) {//是否安全
//	if ((goat(location) == cabbage(location)) && (goat(location) != farmer(location)))//羊在白菜旁边时，农夫是否在羊身边
//	{
//		return 0;
//	}
//	if ((goat(location) == wolf(location)) && (goat(location) != farmer(location)))//狼在羊身边时，羊是否在农夫身边
//	{
//		return 0;
//	}
//	return 1;
//}
//
//string outputLocation(int location) {
//	string output;
//	output.append("南岸：");
//	if (farmer(location) == 0) {
//		output.append("农夫，");
//	}
//	if (wolf(location) == 0) {
//		output.append("狼，");
//	}
//	if (cabbage(location) == 0) {
//		output.append("白菜，");
//	}
//	if (goat(location) == 0) {
//		output.append("羊，");
//	}
//	output.replace(output.end() - 2, output.end(), "。");
//	output.append("    北岸：");
//	if (farmer(location) == 1) {
//		output.append("农夫，");
//	}
//	if (wolf(location) == 1) {
//		output.append("狼，");
//	}
//	if (cabbage(location) == 1) {
//		output.append("白菜，");
//	}
//	if (goat(location) == 1) {
//		output.append("羊，");
//	}
//	output.replace(output.end()-2,output.end(), "。");
//	return output;
//}
//
//void farmerProblem() {//开始解决农夫问题
//	int i, movers, location, newlocation;
//	int route[16];//用于记录已考虑的状态路径;
//	queue<int> moveTo; //定义一个队列
//	moveTo.push(0x00);
//	for (i = 0; i < 16; i++) {
//		route[i] = -1;//将状态设为-1;
//	}
//	route[0] = 0;
//	while (!moveTo.empty() && (route[15] == -1)) { //判断队列是否为空，而且最后一个状态为-1
//		location = moveTo.front(); //将当前的状态取出来
//		moveTo.pop();//删除当前的状态
//		for (movers = 1; movers <= 8; movers <<= 1) { //这个是讨论四种状态，农夫，狼，白菜，羊
//			if (0 != (location & 0x08) == (0 != (location & movers))) { //判断农夫的位置是否和每个物体是一样的
//				newlocation = location ^ (0x08 | movers);  //得到农夫与物体位移后的新状态
//				if (safe(newlocation) && (route[newlocation] == -1)) {
//					route[newlocation] = location; //将判断过的位置放入对应二进制码的数组当中
//					moveTo.push(newlocation);//将newLocation放入队列当中
//				}
//			}
//		}
//	}
//	if (route[15] != -1) { //最后的状态1111已经达到
//		stack<int> temp;
//		for (location = 15; location >= 0; location = route[location]) {
//			temp.push(location);
//			if (location == 0) break;	
//		}
//		int i = 0;
//		while (!temp.empty()) {
//			if (i == 0) {
//				cout << "开始，" << outputLocation(temp.top()) << endl;
//			}
//			else {
//				cout << "第" << i << "步结束后，" << outputLocation(temp.top()) << endl;
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

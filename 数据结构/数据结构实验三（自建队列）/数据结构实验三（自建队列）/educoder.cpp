///*************************************************************
//	date: April 2017
//	copyright: Zhu En
//	DO NOT distribute this code without my permission.
//**************************************************************/
//// 循环顺序的队列实现文件
///////////////////////////////////////////////////////////
//#include <stdio.h>
//#include <stdlib.h>
//
//typedef int T; // 队列元素的数据类型
//struct SeqQueue {
//	T* data; // 指向数据元素数组的指针
//	int front; // 下一个出队元素的数组下标
//	int rear; // 下一个入队元素应该存放的单元的数组下标
//	int max;  // 队列中最多可放max-1个数据元素，留一个空数据单元以区分空和满
//};
//SeqQueue* SQ_Create(int maxlen)
//// 创建顺序队列, 队列最多存储maxlen个队列元素。
//{
//	SeqQueue* sq = (SeqQueue*)malloc(sizeof(SeqQueue));
//	sq->data = (T*)malloc(sizeof(T)*(maxlen + 1));
//	sq->front = sq->rear = 0;
//	sq->max = maxlen + 1;
//	return sq;
//}
//
//void SQ_Free(SeqQueue* sq)
//// 释放队列空间，以删除队列。
//{
//	free(sq->data);
//	free(sq);
//}
//
//void SQ_MakeEmpty(SeqQueue* sq)
//// 将队列置空。
//{
//	sq->front = 0;
//	sq->rear = 0;
//}
//
//bool SQ_IsEmpty(SeqQueue* sq)
//// 判断队列是否为空，为空返回true，否则返回false。
//{
//	// 请在Begin-End之间补充代码，完成队列是否为空的判断。
//	/********** Begin *********/
//	if (sq->front == sq->rear)
//		return true;
//	else
//		return false;
//	/********** End **********/
//}
//
//bool SQ_IsFull(SeqQueue* sq)
//// 判断队列是否为满。为满返回true,否则返回false。
//{
//	// 请在Begin-End之间补充代码，完成队列是否为满的判断。
//	/********** Begin *********/
//	if (sq->front == (sq->rear+1)%(sq->max))
//		return true;
//	else
//		return false;
//	/********** End **********/
//}
//
//int SQ_Length(SeqQueue* sq)
//// 队列长度。
//{
//	// 请在Begin-End之间补充代码，获取队列长度。
//	/********** Begin *********/
//	return (sq->rear - sq->front + (sq->max )) % (sq->max );
//	/********** End **********/
//}
//
//bool SQ_In(SeqQueue* sq, T x)
//// 将x入队。若入队失败(队列满)，则返回false，否则返回true。
//{
//	// 请在Begin-End之间补充代码，将 x 入队。
//	/********** Begin *********/
//	if (SQ_IsFull(sq)) {
//		return false;
//	}
//	else {
//		sq->data[sq->rear] = x;
//		sq->rear = (sq->rear + 1) % (sq->max);
//		return true;
//	}
//
//	/********** End **********/
//}
//
//bool SQ_Out(SeqQueue* sq, T& item)
//// 从队列sq出队一个元素，返回时item为出队的元素的值。若出队成功(队列不为空)，则返回true，否则(队列空)，返回false，此时item不会返回有效值。
//{
//	// 请在Begin-End之间补充代码，完成元素出队操作。
//	/********** Begin *********/
//	if (SQ_IsEmpty(sq))
//		return false;
//	else { 
//		item=sq->data[sq->front];
//		sq->front = (sq->front + 1) % (sq->max);
//		return true;
//	}
//
//	/********** End **********/
//}
//
//bool SQ_Head(SeqQueue* sq, T& head)
//// 获取队列头结点元素，返回时head保存头结点元素。
//// 若获取失败(队列空)，则返回值为false，否则返回值为true。
//{
//	if (SQ_IsEmpty(sq)) {
//		return false;
//	}
//	else {
//		head = sq->data[sq->front];
//		return true;
//	}
//}
//
//void SQ_Print(SeqQueue* sq)
//// 依次打印出队列中的每个元素。
//{
//	int i = sq->front;
//	if (SQ_IsEmpty(sq)) {
//		printf("queue is emtpy");
//		return;
//	}
//	for (i = sq->front; i != sq->rear; i = (i + 1) % sq->max) {
//		printf("%d  ", sq->data[i]);
//	}
//	printf("\n");
//}
//
//
//#include <stdio.h>
//#include <stdlib.h>
//
//#include <string.h>
//#pragma warning(disable:4996)
//void main()
//{
//	int maxlen;
//	scanf("%d", &maxlen);
//	SeqQueue* sq = SQ_Create(maxlen);
//	char dowhat[100];
//	while (true) {
//		scanf("%s", dowhat);
//		if (!strcmp(dowhat, "in")) {
//			T x;
//			scanf("%d", &x);
//			SQ_In(sq, x);
//		}
//		else if (!strcmp(dowhat, "out")) {
//			T item;
//			SQ_Out(sq, item);
//		}
//		else {
//			break;
//		}
//	}
//	int length = SQ_Length(sq);
//	printf("Queue length: %d\n", length);
//	printf("Queue data: ");
//	SQ_Print(sq);
//	system("PAUSE");
//	SQ_Free(sq);
//}
//
///*
//5
//
//in 1
//
//in 3
//
//in 5
//
//in 9
//
//in 12
//
//out
//
//end
//
//Queue length: 4
//
//Queue data: 3  5  9  12
//
//5
//in 89
//in 34
//out
//out
//out
//in 1
//in 2
//in 3
//in 4
//in 5
//in 6
//end
//
//
//*/
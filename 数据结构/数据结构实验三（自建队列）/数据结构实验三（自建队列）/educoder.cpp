///*************************************************************
//	date: April 2017
//	copyright: Zhu En
//	DO NOT distribute this code without my permission.
//**************************************************************/
//// ѭ��˳��Ķ���ʵ���ļ�
///////////////////////////////////////////////////////////
//#include <stdio.h>
//#include <stdlib.h>
//
//typedef int T; // ����Ԫ�ص���������
//struct SeqQueue {
//	T* data; // ָ������Ԫ�������ָ��
//	int front; // ��һ������Ԫ�ص������±�
//	int rear; // ��һ�����Ԫ��Ӧ�ô�ŵĵ�Ԫ�������±�
//	int max;  // ���������ɷ�max-1������Ԫ�أ���һ�������ݵ�Ԫ�����ֿպ���
//};
//SeqQueue* SQ_Create(int maxlen)
//// ����˳�����, �������洢maxlen������Ԫ�ء�
//{
//	SeqQueue* sq = (SeqQueue*)malloc(sizeof(SeqQueue));
//	sq->data = (T*)malloc(sizeof(T)*(maxlen + 1));
//	sq->front = sq->rear = 0;
//	sq->max = maxlen + 1;
//	return sq;
//}
//
//void SQ_Free(SeqQueue* sq)
//// �ͷŶ��пռ䣬��ɾ�����С�
//{
//	free(sq->data);
//	free(sq);
//}
//
//void SQ_MakeEmpty(SeqQueue* sq)
//// �������ÿա�
//{
//	sq->front = 0;
//	sq->rear = 0;
//}
//
//bool SQ_IsEmpty(SeqQueue* sq)
//// �ж϶����Ƿ�Ϊ�գ�Ϊ�շ���true�����򷵻�false��
//{
//	// ����Begin-End֮�䲹����룬��ɶ����Ƿ�Ϊ�յ��жϡ�
//	/********** Begin *********/
//	if (sq->front == sq->rear)
//		return true;
//	else
//		return false;
//	/********** End **********/
//}
//
//bool SQ_IsFull(SeqQueue* sq)
//// �ж϶����Ƿ�Ϊ����Ϊ������true,���򷵻�false��
//{
//	// ����Begin-End֮�䲹����룬��ɶ����Ƿ�Ϊ�����жϡ�
//	/********** Begin *********/
//	if (sq->front == (sq->rear+1)%(sq->max))
//		return true;
//	else
//		return false;
//	/********** End **********/
//}
//
//int SQ_Length(SeqQueue* sq)
//// ���г��ȡ�
//{
//	// ����Begin-End֮�䲹����룬��ȡ���г��ȡ�
//	/********** Begin *********/
//	return (sq->rear - sq->front + (sq->max )) % (sq->max );
//	/********** End **********/
//}
//
//bool SQ_In(SeqQueue* sq, T x)
//// ��x��ӡ������ʧ��(������)���򷵻�false�����򷵻�true��
//{
//	// ����Begin-End֮�䲹����룬�� x ��ӡ�
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
//// �Ӷ���sq����һ��Ԫ�أ�����ʱitemΪ���ӵ�Ԫ�ص�ֵ�������ӳɹ�(���в�Ϊ��)���򷵻�true������(���п�)������false����ʱitem���᷵����Чֵ��
//{
//	// ����Begin-End֮�䲹����룬���Ԫ�س��Ӳ�����
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
//// ��ȡ����ͷ���Ԫ�أ�����ʱhead����ͷ���Ԫ�ء�
//// ����ȡʧ��(���п�)���򷵻�ֵΪfalse�����򷵻�ֵΪtrue��
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
//// ���δ�ӡ�������е�ÿ��Ԫ�ء�
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
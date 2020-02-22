#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef int T; // ����Ԫ�ص���������
struct LNode {
	T data;
	LNode* next;
};

/*************************************************************
	date: April 2017
	copyright: Zhu En
	DO NOT distribute this code without my permission.
**************************************************************/
// ���е����Ӵ洢ʵ���ļ���
// ����ѭ���������и���ͷ�ڵ㣬ʹ��β���ָ�롣
// CLQ_   Circularly Linked Queue
////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>

void CLQ_MakeEmpty(LNode* & rear);
bool CLQ_IsEmpty(LNode* rear);
bool CLQ_Out(LNode* & rear, T& item);

LNode* CLQ_Create()
// ����һ�����С�
{
	LNode* rear = (LNode*)malloc(sizeof(LNode));
	rear->data = 0;
	rear->next = rear;
	return rear;
}
void CLQ_Free(LNode* rear)
// rearָ��β��㡣
{
	CLQ_MakeEmpty(rear);
	free(rear);
}

void CLQ_MakeEmpty(LNode* & rear)
// rearָ��β��㡣
// �����б�Ϊ�ն��С�
{
	T item;
	while (!CLQ_IsEmpty(rear))
		CLQ_Out(rear, item);
}

bool CLQ_IsEmpty(LNode* rear)
// �ж϶����Ƿ�Ϊ�ա�
{
	// ����Begin-End֮�䲹����룬��ɶ����Ƿ�Ϊ�յ��жϡ�
	/********** Begin *********/
	if (rear->next == rear)
		return true;
	else
		return false;

	/********** End **********/
}

int CLQ_Length(LNode* rear)
// ���ض��г��ȣ�rearָ��β��㡣
{
	// ����Begin-End֮�䲹����룬��ȡ���г��ȡ�
	/********** Begin *********/
	return rear->next->data;

	/********** End **********/
}

void CLQ_In(LNode* & rear, T x)
// �����, �½���������β����rearָ��β��㡣
{
	// ����Begin-End֮�䲹����룬����½����Ӳ�����
	/********** Begin *********/
		LNode* head = rear->next;
		LNode* newNode = new LNode;
		newNode->data = x;
		newNode->next = head;
		head->data++;
		rear->next = newNode;
		rear = newNode;
	/********** End **********/
}

bool CLQ_Out(LNode* & rear, T& item)
// �����С��ն���ʱ������ֵΪfalse��rearָ��β��㡣
{
	// ����Begin-End֮�䲹����룬��ɽ����Ӳ�����
	/********** Begin *********/
	if (CLQ_IsEmpty(rear)) {
		return false;
	}
	else
	{	
		LNode* head = rear->next;
		LNode* temp = head->next;
		if (temp == rear)
			rear = head;
		head->next = temp->next;
		head->data--;
		free(temp);
		return true;
	}
	/********** End **********/
}

bool CLQ_Head(LNode* rear, T& item)
// rearָ��β��㡣
// ��ȡ����ͷ���ն���ʱ����ֵΪfalse��
{
	if (CLQ_IsEmpty(rear))
		return false;
	item = rear->next->next->data;
	return true;
}
void CLQ_Print(LNode* rear)
// ��ӡ���С�
{
	if (CLQ_IsEmpty(rear)) {
		printf("The queue is: empty. \n");
		return;
	}
	LNode* node = rear->next->next;
	do {
		printf("%d  ", node->data);
		node = node->next;
	} while (node != rear->next);
	//printf("\n");
}


int main()
{
	LNode* rear = CLQ_Create();
	char dowhat[100];
	while (true) {
		scanf("%s", dowhat);
		if (!strcmp(dowhat, "in")) {
			T x;
			scanf("%d", &x);
			CLQ_In(rear, x);
		}
		else if (!strcmp(dowhat, "out")) {
			T item;
			CLQ_Out(rear, item);
		}
		else {
			break;
		}
	}
	int length = CLQ_Length(rear);
	printf("Queue length: %d\n", length);
	printf("Queue data: ");
	CLQ_Print(rear);
	CLQ_Free(rear);
}
/*
in 1

in 3

in 5

in 9

in 12

out

end

Queue length: 4

Queue data: 3  5  9  12
*/
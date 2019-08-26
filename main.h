#pragma once


#include<stdio.h>
#include <stdlib.h>

typedef struct DNode {
	int value;
	struct DNode* prev;
	struct DNode* next;
	DNode;
};

void DListInit(DNode** node)
{
	// ����ͷ�ڵ�
	DNode* head = (DNode*)malloc(sizeof(DNode));
	head->next = head;
	head->prev = head;

	*node head;
}

// ͷ��
void DListPushFront(DNode* head, int v)
{
	DNode* node = (DNode*)malloc(sizeof(DNode));
	node->value = v;
	node->next = head->next;
	node->prev = head;
	head->next->prev = node;
	head->next = node;
}

// β��
void DListPushBack(DNode* head, int v)
{
	DNode* node = (DNode*)malloc(sizeof(DNode));
	node->value = v;
	node->prev = head->prev;
	node->next = head;
	node->prev->next = node;
	head->prev = node;
}

// �� pos ǰ�����
void DListInsertAfter(DNode* head, DNode *pos, int v)
{
	DNode* node = (DNode*)malloc(sizeof(DNode));
	node->value = v;
	node->prev = pos;
	node->next = pos->next;
	pos->next->prev = node;
	pos->next = node;
}

// �� pos �������
void DListInsertBefore(DNode* head, DNode *pos, int v)
{
	DNode* node = (DNode*)malloc(sizeof(DNode));
	node->value = v;
	node->prev = pos->prev;
	node->next = pos;
	pos->next->prev = node;
	pos->next = node;
}
void Test()
{
	DNode* node;
	DListInit(&node);
}
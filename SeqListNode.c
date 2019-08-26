#include <stdio.h>
#include <stdlib.h>
#include "slist.h"
#include <assert.h>


// ����ĳ�ʼ�� 
void SListInit(SList* pl)
{
	assert(pl != NULL);

	pl->_pHead = NULL;
}


// ��������β��ֵΪdata�Ľڵ� 
void SListPushBack(SList* pl, SDataType data)
{	
	assert(pl != NULL);

	Node *node = (Node *)malloc(sizeof(Node));
	node->_data = data;
	node->_pNext = NULL;

	//���û�нڵ�
	if (pl->_pHead == NULL)
	{
		pl->_pHead = node;
		return;
	}

	//������������һ���ڵ�,�ҵ����һ���ڵ�
	Node *cur = pl->_pHead;
	while (cur->_pNext != NULL)
	{
		cur = cur->_pNext;
	}
	cur->_pNext = node;
}

// ɾ���������һ���ڵ� 
void SListPopBack(SList* pl)
{
	assert(pl != NULL);
	assert(pl->_pHead != NULL);		//�ж�������������һ���ڵ�
	
	//���ֻ��һ���ڵ�
	if (pl->_pHead->_pNext == NULL)
	{
		free(pl->_pHead);
		pl->_pHead = NULL;
		return;
	}

	//��ֹһ���ڵ�
	Node *cur = pl->_pHead;
	while (cur->_pNext->_pNext != NULL)
	{
		cur = cur->_pNext;
	}
	free(cur->_pNext);
	cur->_pNext = NULL;
}

// �������һ��Ԫ��ǰ����ֵΪdata�Ľڵ� 
void SListPushFront(SList* pl, SDataType data)
{
	Node *node = (Node *)malloc(sizeof(Node));
	node->_data = data;
	node->_pNext = pl->_pHead;
	pl->_pHead = node;
}

// ɾ�������е�һ���ڵ� 
void SListPopFront(SList* pl)
{
	assert(pl != NULL);
	assert(pl->_pHead != NULL);

	//��Ҫ�ȼ�¼ͷ�ڵ����һ���ڵ㣬Ȼ���ͷ�ͷ�ڵ�
	//�ٰ�ͷ�ڵ��Ϊ�ղż�¼��ͷ�ڵ����һ���ڵ�
	Node *cur = pl->_pHead->_pNext;
	free(pl->_pHead);
	pl->_pHead = cur;
}

// ������posλ�ú����ֵΪdata�Ľڵ� 
void SListInsertAfter(SList *pl, Node* pos, SDataType data)
{
	assert(pl != NULL);

	Node *node = (Node*)malloc(sizeof(Node));
	node->_data = data;
	node->_pNext = pos->_pNext;
	pos->_pNext = node;
}

// ɾ�������е�pos����Ľڵ�  
void SListEraseAfter(SList* pl, Node* pos)
{
	assert(pl != NULL);
	
	Node *cur = pos->_pNext;
	pos->_pNext = pos->_pNext->_pNext;
	free(cur);
}

// �������в���ֵΪdata�Ľڵ㣬�ҵ����ظýڵ�ĵ�ַ�����򷵻ؿ� 
Node* SListFind(SList* pl, SDataType data)
{
	assert(pl != NULL);

	Node *cur = pl->_pHead;
	while (cur != NULL)
	{
		if (cur->_data == data)
		{
			return cur;
		}
		cur = cur->_pNext;
	}
	return NULL;
}

// �������� 
void SListDestroy(SList* pl)
{
	Node *cur = pl->_pHead;
	Node *next;
	for (cur; cur->_pNext != NULL; cur = next)
	{
		next = cur->_pNext;
		free(cur);
	}

	pl->_pHead = NULL;
}

// ��ȡ��������Ч�ڵ�ĸ��� 
int SListSize(SList* pl)
{
	Node *cur = pl->_pHead;
	int size = 0;
	while (cur != NULL)
	{
		size += 1;
		cur = cur->_pNext;
	}
	return size;
}

// ��������Ƿ�Ϊ�� 
int SListEmpty(SList* pl)
{
	assert(pl != NULL);
	if (pl->_pHead == NULL)
	{
		return 1;
	}
	return 0;
}

// ��ȡ����ĵ�һ���ڵ� 
Node* SListFront(SList* pl)
{
	assert(pl != NULL);
	return pl->_pHead;
}

// ��ȡ����ĵڶ����ڵ� 
Node* SListBack(SList* pl)
{
	assert(pl != NULL);
	return pl->_pHead->_pNext;
}

// ɾ�������е�һ��ֵΪdata�Ľڵ� 
void SListRemove(SList* pl, SDataType data)
{
	assert(pl != NULL);

	//Ϊ��
	if (pl->_pHead == NULL)
	{
		return;
	}

	//Ϊͷ�ڵ�
	if (pl->_pHead->_data == data)
	{
		Node *cur = pl->_pHead->_pNext;
		free(pl->_pHead);
		pl->_pHead = cur;
		return;
	}

	//����ͷ�ڵ�
	Node *cur = pl->_pHead;
	while (cur != NULL)
	{
		if (cur->_pNext->_data==data)
		{
			Node *next = cur->_pNext->_pNext;
			free(cur->_pNext);
			cur->_pNext = next;
			return;
		}
		cur = cur->_pNext;
	}
}

// ɾ������������ֵΪdata�Ľڵ� 
void SListRemoveAll(SList* pl, SDataType data)
{
	assert(pl != NULL);

	//Ϊ��
	if (pl->_pHead == NULL)
	{
		return;
	}

	//Ϊ��һ���ڵ�
	if (pl->_pHead->_data == data)
	{
		Node *cur = pl->_pHead->_pNext;
		free(pl->_pHead);
		pl->_pHead = cur;
	}

	//
	Node *cur = pl->_pHead;
	while (cur->_pNext != NULL)
	{
		if (cur->_pNext->_data == data)
		{
			Node *next = cur->_pNext->_pNext;
			free(cur->_pNext);
			cur->_pNext = next;
		}
		cur = cur->_pNext;
	}
}


//��ӡ����
void Pri(SList* pl)
{
	assert(pl != NULL);

	Node *cur = pl->_pHead;
	while (cur != NULL)
	{
		printf("%d %p\n", cur->_data, cur);
		cur = cur->_pNext;
	}
	printf("\n");
	return;
}


int main()
{
	SList list;
	SListInit(&list);

	//β��
	SListPushBack(&list, 1);
	SListPushBack(&list, 2);
	SListPushBack(&list, 3);
	// 1 2 3
	printf("β���\n");
	Pri(&list);

	//ͷ��
	SListPushFront(&list, 30);
	SListPushFront(&list, 20);
	SListPushFront(&list, 10);
	// 10 20 30 1 2 3
	printf("ͷ���\n");
	Pri(&list);

	//Ѱ��ֵΪ30�Ľڵ�
	Node *pos = SListFind(&list, 30);
	printf("%d %p\n",pos->_data, pos);
	printf("Ѱ��ֵΪ30�Ľڵ㣺\n");
	printf("\n");

	//��pos������ֵΪ100�Ľڵ�
	SListInsertAfter(&list, pos, 100);
	// 10 20 30 100 1 2 3
	printf("��pos������ֵΪ100�Ľڵ��\n");
	Pri(&list);

	//ɾ��pos���Ľڵ�
	SListEraseAfter(&list, pos);
	// 10 20 30 1 2 3
	printf("ɾ��pos���Ľڵ��\n");
	Pri(&list);

	//ͷɾ
	SListPopFront(&list);
	// 20 30 1 2 3
	printf("ͷɾ��\n");
	Pri(&list);

	//βɾ
	SListPopBack(&list);
	// 20 30 1 2
	printf("βɾ��\n");
	Pri(&list);

	//ɾ����һ��ֵΪ2�Ľڵ�
	SListRemove(&list, 2);
	// 20 30 1
	printf("ɾ�������е�һ��ֵΪ2�Ľڵ��\n");
	Pri(&list);

	//��ȡ�����е���ЧԪ�ظ���
	printf("��������ЧԪ�ظ���Ϊ��%d\n",SListSize(&list));
	printf("\n");

	//�ж������Ƿ�Ϊ�գ�Ϊ�շ��� 1����Ϊ�շ��� 0
	if (SListEmpty(&list) == 1)
	{
		printf("����Ϊ��\n");
		printf("\n");
	}
	else
	{
		printf("����Ϊ��\n");
		printf("\n");
	}

	//��ȡ����ͷ�ڵ�
	printf("�����ͷ�ڵ�Ϊ��%d %p\n", SListFront(&list)->_data, SListFront(&list));
	printf("\n");

	//��ȡ����ڶ����ڵ�
	printf("����ĵڶ����ڵ�Ϊ��%d %p\n", SListBack(&list)->_data, SListBack(&list));
	printf("\n");

	//ͷ��
	SListPushFront(&list, 30);
	SListPushFront(&list, 20);
	SListPushFront(&list, 30);
	SListPushFront(&list, 10);
	//ɾ�������е�һ��ֵΪ30�Ľڵ�
	SListRemove(&list, 30);
	// 10 20 30 20 30 1
	printf("ɾ�������е�һ��ֵΪ30�Ľڵ��\n");
	Pri(&list);


	//ɾ������������ֵΪ30�Ľڵ�
	SListRemoveAll(&list, 30);
	// 10 20 20 1
	printf("ɾ������������ֵΪ30�Ľڵ��\n");
	Pri(&list);

	//��������
	SListDestroy(&list);

	//���ٺ��ж������Ƿ�Ϊ�գ�Ϊ�շ��� 1����Ϊ�շ��� 0
	if (SListEmpty(&list) == 1)
	{
		printf("����Ϊ��\n");
	}
	else
		printf("����Ϊ��\n");


	system("pause");
	return 0;
}
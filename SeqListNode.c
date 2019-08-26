#include <stdio.h>
#include <stdlib.h>
#include "slist.h"
#include <assert.h>


// 链表的初始化 
void SListInit(SList* pl)
{
	assert(pl != NULL);

	pl->_pHead = NULL;
}


// 在链表中尾插值为data的节点 
void SListPushBack(SList* pl, SDataType data)
{	
	assert(pl != NULL);

	Node *node = (Node *)malloc(sizeof(Node));
	node->_data = data;
	node->_pNext = NULL;

	//如果没有节点
	if (pl->_pHead == NULL)
	{
		pl->_pHead = node;
		return;
	}

	//链表中至少有一个节点,找到最后一个节点
	Node *cur = pl->_pHead;
	while (cur->_pNext != NULL)
	{
		cur = cur->_pNext;
	}
	cur->_pNext = node;
}

// 删除链表最后一个节点 
void SListPopBack(SList* pl)
{
	assert(pl != NULL);
	assert(pl->_pHead != NULL);		//判断链表中至少有一个节点
	
	//如果只有一个节点
	if (pl->_pHead->_pNext == NULL)
	{
		free(pl->_pHead);
		pl->_pHead = NULL;
		return;
	}

	//不止一个节点
	Node *cur = pl->_pHead;
	while (cur->_pNext->_pNext != NULL)
	{
		cur = cur->_pNext;
	}
	free(cur->_pNext);
	cur->_pNext = NULL;
}

// 在链表第一个元素前插入值为data的节点 
void SListPushFront(SList* pl, SDataType data)
{
	Node *node = (Node *)malloc(sizeof(Node));
	node->_data = data;
	node->_pNext = pl->_pHead;
	pl->_pHead = node;
}

// 删除链表中第一个节点 
void SListPopFront(SList* pl)
{
	assert(pl != NULL);
	assert(pl->_pHead != NULL);

	//需要先记录头节点的下一个节点，然后释放头节点
	//再把头节点绑定为刚才记录的头节点的下一个节点
	Node *cur = pl->_pHead->_pNext;
	free(pl->_pHead);
	pl->_pHead = cur;
}

// 在链表pos位置后插入值为data的节点 
void SListInsertAfter(SList *pl, Node* pos, SDataType data)
{
	assert(pl != NULL);

	Node *node = (Node*)malloc(sizeof(Node));
	node->_data = data;
	node->_pNext = pos->_pNext;
	pos->_pNext = node;
}

// 删除链表中的pos后面的节点  
void SListEraseAfter(SList* pl, Node* pos)
{
	assert(pl != NULL);
	
	Node *cur = pos->_pNext;
	pos->_pNext = pos->_pNext->_pNext;
	free(cur);
}

// 在链表中查找值为data的节点，找到返回该节点的地址，否则返回空 
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

// 销毁链表 
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

// 获取链表中有效节点的个数 
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

// 检测链表是否为空 
int SListEmpty(SList* pl)
{
	assert(pl != NULL);
	if (pl->_pHead == NULL)
	{
		return 1;
	}
	return 0;
}

// 获取链表的第一个节点 
Node* SListFront(SList* pl)
{
	assert(pl != NULL);
	return pl->_pHead;
}

// 获取链表的第二个节点 
Node* SListBack(SList* pl)
{
	assert(pl != NULL);
	return pl->_pHead->_pNext;
}

// 删除链表中第一个值为data的节点 
void SListRemove(SList* pl, SDataType data)
{
	assert(pl != NULL);

	//为空
	if (pl->_pHead == NULL)
	{
		return;
	}

	//为头节点
	if (pl->_pHead->_data == data)
	{
		Node *cur = pl->_pHead->_pNext;
		free(pl->_pHead);
		pl->_pHead = cur;
		return;
	}

	//不是头节点
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

// 删除链表中所有值为data的节点 
void SListRemoveAll(SList* pl, SDataType data)
{
	assert(pl != NULL);

	//为空
	if (pl->_pHead == NULL)
	{
		return;
	}

	//为第一个节点
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


//打印函数
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

	//尾插
	SListPushBack(&list, 1);
	SListPushBack(&list, 2);
	SListPushBack(&list, 3);
	// 1 2 3
	printf("尾插后：\n");
	Pri(&list);

	//头插
	SListPushFront(&list, 30);
	SListPushFront(&list, 20);
	SListPushFront(&list, 10);
	// 10 20 30 1 2 3
	printf("头插后：\n");
	Pri(&list);

	//寻找值为30的节点
	Node *pos = SListFind(&list, 30);
	printf("%d %p\n",pos->_data, pos);
	printf("寻找值为30的节点：\n");
	printf("\n");

	//在pos处插入值为100的节点
	SListInsertAfter(&list, pos, 100);
	// 10 20 30 100 1 2 3
	printf("在pos处插入值为100的节点后：\n");
	Pri(&list);

	//删除pos处的节点
	SListEraseAfter(&list, pos);
	// 10 20 30 1 2 3
	printf("删除pos处的节点后：\n");
	Pri(&list);

	//头删
	SListPopFront(&list);
	// 20 30 1 2 3
	printf("头删后：\n");
	Pri(&list);

	//尾删
	SListPopBack(&list);
	// 20 30 1 2
	printf("尾删后：\n");
	Pri(&list);

	//删除第一个值为2的节点
	SListRemove(&list, 2);
	// 20 30 1
	printf("删除链表中第一个值为2的节点后：\n");
	Pri(&list);

	//获取链表中的有效元素个数
	printf("链表中有效元素个数为：%d\n",SListSize(&list));
	printf("\n");

	//判断链表是否为空，为空返回 1，不为空返回 0
	if (SListEmpty(&list) == 1)
	{
		printf("链表为空\n");
		printf("\n");
	}
	else
	{
		printf("链表不为空\n");
		printf("\n");
	}

	//获取链表头节点
	printf("链表的头节点为：%d %p\n", SListFront(&list)->_data, SListFront(&list));
	printf("\n");

	//获取链表第二个节点
	printf("链表的第二个节点为：%d %p\n", SListBack(&list)->_data, SListBack(&list));
	printf("\n");

	//头插
	SListPushFront(&list, 30);
	SListPushFront(&list, 20);
	SListPushFront(&list, 30);
	SListPushFront(&list, 10);
	//删除链表中第一个值为30的节点
	SListRemove(&list, 30);
	// 10 20 30 20 30 1
	printf("删除链表中第一个值为30的节点后：\n");
	Pri(&list);


	//删除链表中所有值为30的节点
	SListRemoveAll(&list, 30);
	// 10 20 20 1
	printf("删除链表中所有值为30的节点后：\n");
	Pri(&list);

	//销毁链表
	SListDestroy(&list);

	//销毁后判断链表是否为空，为空返回 1，不为空返回 0
	if (SListEmpty(&list) == 1)
	{
		printf("链表为空\n");
	}
	else
		printf("链表不为空\n");


	system("pause");
	return 0;
}
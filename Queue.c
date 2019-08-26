#include <stdio.h>
#include <assert.h>
#include "Queue.h"

// 初始化队列 
void QueueInit(Queue* q)
{
	assert(q);

	q->_front = NULL;
	q->_rear = q->_front;
	/*q->_front = (QNode *)malloc(sizeof(QNode));
	if (q->_front == NULL || q->_rear == NULL)
	{
		return;
	}
		
	q->_front->_pNext = NULL;
	q->_front->_data = 0;
	q->_rear = q->_front;*/	//头节点与尾节点相等时队列为空
}

// 队尾入队列 
void QueuePush(Queue* q, QDataType data)
{
	assert(q);

	QNode *qnode = (QNode *)malloc(sizeof(QNode));
	qnode->_pNext = NULL;
	qnode->_data = data;

	if (q->_front == NULL)
	{
		q->_front = q->_rear = qnode;
		return;
	}
	q->_rear->_pNext = qnode;
	q->_rear = qnode;
}

// 队头出队列 
void QueuePop(Queue* q)
{
	assert(q);

	if (q->_front == q->_rear)
	{
		printf("队列为空，出队列失败！\n");
		return;
	}

	QNode *cur = q->_front;
	if (cur)
	{
		q->_front = cur->_pNext;
		free(cur);
	}
}

// 获取队列头部元素 
QDataType QueueFront(Queue* q)
{
	assert(q);

	if (q->_front == q->_rear)
	{
		printf("队列为空，获取队列头部元素失败！\n");
		return;
	}
	return q->_front->_data;
}

// 获取队列队尾元素 
QDataType QueueBack(Queue* q)
{
	assert(q);

	if (q->_front == q->_rear)
	{
		printf("队列为空，获取队尾元素失败！\n");
		return;
	}
	return q->_rear->_data;
}

// 获取队列中有效元素个数 
int QueueSize(Queue* q)
{
	assert(q);

	int count = 0;
	QNode *cur = q->_front;

	while (cur != NULL)
	{
		++count;
		cur = cur->_pNext;
	}
	return count;
}

// 检测队列是否为空，如果为空返回非零结果，如果非空返回0 
int QueueEmpty(Queue* q)
{
	assert(q);
	if (q->_front == q->_rear)
	{
		return 1;
	}
	return 0;
}

// 销毁队列 
void QueueDestroy(Queue* q)
{
	assert(q);
	QNode *cur = q->_front->_pNext;
	while (cur->_pNext != q->_rear)
	{
		QNode *next = cur->_pNext;
		free(cur);
		cur = next;
	}
	q->_front = q->_rear;
}

//打印
void Pri(Queue* q)
{
	assert(q);

	//队列为空
	if (q->_front == q->_rear)
	{
		return;
	}

	QNode *cur = q->_front;
	while (cur != NULL)
	{
		printf("%d ", cur->_data);
		cur = cur->_pNext;
	}
	printf("\n");
}

int main()
{
	QNode q;

	//初始化队列
	QueueInit(&q);

	//队尾入队列
	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	QueuePush(&q, 4);
	QueuePush(&q, 5);
	// 1 2 3 4 5
	printf("入队列后：\n");
	Pri(&q);

	//队头出队列
	QueuePop(&q);
	// 1 2 3 4
	printf("出队列后：\n");
	Pri(&q);

	// 获取队列头部元素 
	printf("队列头部元素为：%d\n", QueueFront(&q));
	printf("\n");

	// 获取队列队尾元素 
	printf("队列队尾元素为：%d\n", QueueBack(&q));
	printf("\n");

	// 获取队列中有效元素个数 
	printf("队列中有效元素个数为：%d\n", QueueSize(&q));
	printf("\n");

	// 检测队列是否为空，如果为空返回非零结果，如果不为空返回0 
	int ret = QueueEmpty(&q);
	if (ret == 0)
	{
		printf("此队列不为空\n");
	}
	else
		printf("此队列为空\n");
	printf("\n");

	// 销毁队列 
	QueueDestroy(&q);

	ret = QueueEmpty(&q);
	if (ret == 0)
	{
		printf("此队列不为空\n");
	}
	else
		printf("此队列为空\n");
	printf("\n");


	return 0;
}
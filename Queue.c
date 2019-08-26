#include <stdio.h>
#include <assert.h>
#include "Queue.h"

// ��ʼ������ 
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
	q->_rear = q->_front;*/	//ͷ�ڵ���β�ڵ����ʱ����Ϊ��
}

// ��β����� 
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

// ��ͷ������ 
void QueuePop(Queue* q)
{
	assert(q);

	if (q->_front == q->_rear)
	{
		printf("����Ϊ�գ�������ʧ�ܣ�\n");
		return;
	}

	QNode *cur = q->_front;
	if (cur)
	{
		q->_front = cur->_pNext;
		free(cur);
	}
}

// ��ȡ����ͷ��Ԫ�� 
QDataType QueueFront(Queue* q)
{
	assert(q);

	if (q->_front == q->_rear)
	{
		printf("����Ϊ�գ���ȡ����ͷ��Ԫ��ʧ�ܣ�\n");
		return;
	}
	return q->_front->_data;
}

// ��ȡ���ж�βԪ�� 
QDataType QueueBack(Queue* q)
{
	assert(q);

	if (q->_front == q->_rear)
	{
		printf("����Ϊ�գ���ȡ��βԪ��ʧ�ܣ�\n");
		return;
	}
	return q->_rear->_data;
}

// ��ȡ��������ЧԪ�ظ��� 
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

// �������Ƿ�Ϊ�գ����Ϊ�շ��ط�����������ǿշ���0 
int QueueEmpty(Queue* q)
{
	assert(q);
	if (q->_front == q->_rear)
	{
		return 1;
	}
	return 0;
}

// ���ٶ��� 
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

//��ӡ
void Pri(Queue* q)
{
	assert(q);

	//����Ϊ��
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

	//��ʼ������
	QueueInit(&q);

	//��β�����
	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	QueuePush(&q, 4);
	QueuePush(&q, 5);
	// 1 2 3 4 5
	printf("����к�\n");
	Pri(&q);

	//��ͷ������
	QueuePop(&q);
	// 1 2 3 4
	printf("�����к�\n");
	Pri(&q);

	// ��ȡ����ͷ��Ԫ�� 
	printf("����ͷ��Ԫ��Ϊ��%d\n", QueueFront(&q));
	printf("\n");

	// ��ȡ���ж�βԪ�� 
	printf("���ж�βԪ��Ϊ��%d\n", QueueBack(&q));
	printf("\n");

	// ��ȡ��������ЧԪ�ظ��� 
	printf("��������ЧԪ�ظ���Ϊ��%d\n", QueueSize(&q));
	printf("\n");

	// �������Ƿ�Ϊ�գ����Ϊ�շ��ط������������Ϊ�շ���0 
	int ret = QueueEmpty(&q);
	if (ret == 0)
	{
		printf("�˶��в�Ϊ��\n");
	}
	else
		printf("�˶���Ϊ��\n");
	printf("\n");

	// ���ٶ��� 
	QueueDestroy(&q);

	ret = QueueEmpty(&q);
	if (ret == 0)
	{
		printf("�˶��в�Ϊ��\n");
	}
	else
		printf("�˶���Ϊ��\n");
	printf("\n");


	return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include <assert.h>



// ��ʼ��ջ 
void StackInit(Stack* ps)
{
	assert(ps);

	ps->_capacity = 10;
	ps->_top = 0;
	ps->_array = (STDataType)malloc(sizeof(STDataType)*ps->_capacity);
}

// ��ջ 
void StackPush(Stack* ps, STDataType data)
{
	assert(ps);

	ps->_array[ps->_top] = data;
	++ps->_top;
}

// ��ջ 
void StackPop(Stack* ps)
{
	assert(ps);

	ps->_array[ps->_top];
	--ps->_top;
}

// ��ȡջ��Ԫ�� 
STDataType StackTop(Stack* ps)
{
	assert(ps);

	if (ps->_top == 0)
	{
		return;
	}
	STDataType a = ps->_array[ps->_top-1];
	return a;
}

// ��ȡջ����ЧԪ�ظ��� 
int StackSize(Stack* ps)
{
	assert(ps);

	int count = 0;
	for (int i = 0; i < ps->_top; ++i)
	{
		++count;
	}
	return count;
}

// ���ջ�Ƿ�Ϊ�գ����Ϊ�շ��ط������������Ϊ�շ���0 
int StackEmpty(Stack* ps)
{
	assert(ps);

	if (ps->_top == 0)
	{
		return 1;
	}
	return 0;
}

// ����ջ 
void StackDestroy(Stack* ps)
{
	assert(ps);

	if(ps->_array == NULL)
	{
		return;
	}
	ps->_capacity = 0;
	ps->_top = 0;
	free(ps->_array);
	ps->_array = NULL;
	ps = NULL;
}

//��ӡ
void Pri(Stack* ps)
{
	assert(ps);

	//ջΪ��
	if (ps->_top == 0)
	{
		return;
	}

	for (int i = 0; i < ps->_top; ++i)
	{
		printf("%d ", ps->_array[i]);
	}
	printf("\n");
}

int main()
{
	Stack s;

	//��ʼ��ջ
	StackInit(&s);

	//��ջ
	StackPush(&s, 1);
	StackPush(&s, 2);
	StackPush(&s, 3);
	StackPush(&s, 4);
	StackPush(&s, 5);
	// 1 2 3 4 5
	printf("��ջ��\n");
	Pri(&s);

	//��ջ
	StackPop(&s);
	// 1 2 3 4
	printf("��ջ��\n");
	Pri(&s);

	// ��ȡջ��Ԫ�� 
	printf("ջ��Ԫ��Ϊ��%d\n", StackTop(&s));
	printf("\n");

	// ��ȡջ����ЧԪ�ظ��� 
	printf("ջ����ЧԪ�ظ���Ϊ��%d\n", StackSize(&s));
	printf("\n");

	// ���ջ�Ƿ�Ϊ�գ����Ϊ�շ��ط������������Ϊ�շ���0 
	int ret = StackEmpty(&s);
	if (ret == 0)
	{
		printf("��ջ��Ϊ��\n");
	}
	else
		printf("��ջΪ��\n");
	printf("\n");

	// ����ջ 
	StackDestroy(&s);

	ret = StackEmpty(&s);
	if (ret == 0)
	{
		printf("��ջ��Ϊ��\n");
	}
	else
		printf("��ջΪ��\n");
	printf("\n");

	system("pause");
	return 0;
}
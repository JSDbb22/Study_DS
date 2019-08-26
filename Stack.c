#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include <assert.h>



// 初始化栈 
void StackInit(Stack* ps)
{
	assert(ps);

	ps->_capacity = 10;
	ps->_top = 0;
	ps->_array = (STDataType)malloc(sizeof(STDataType)*ps->_capacity);
}

// 入栈 
void StackPush(Stack* ps, STDataType data)
{
	assert(ps);

	ps->_array[ps->_top] = data;
	++ps->_top;
}

// 出栈 
void StackPop(Stack* ps)
{
	assert(ps);

	ps->_array[ps->_top];
	--ps->_top;
}

// 获取栈顶元素 
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

// 获取栈中有效元素个数 
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

// 检测栈是否为空，如果为空返回非零结果，如果不为空返回0 
int StackEmpty(Stack* ps)
{
	assert(ps);

	if (ps->_top == 0)
	{
		return 1;
	}
	return 0;
}

// 销毁栈 
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

//打印
void Pri(Stack* ps)
{
	assert(ps);

	//栈为空
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

	//初始化栈
	StackInit(&s);

	//入栈
	StackPush(&s, 1);
	StackPush(&s, 2);
	StackPush(&s, 3);
	StackPush(&s, 4);
	StackPush(&s, 5);
	// 1 2 3 4 5
	printf("入栈后：\n");
	Pri(&s);

	//出栈
	StackPop(&s);
	// 1 2 3 4
	printf("出栈后：\n");
	Pri(&s);

	// 获取栈顶元素 
	printf("栈顶元素为：%d\n", StackTop(&s));
	printf("\n");

	// 获取栈中有效元素个数 
	printf("栈中有效元素个数为：%d\n", StackSize(&s));
	printf("\n");

	// 检测栈是否为空，如果为空返回非零结果，如果不为空返回0 
	int ret = StackEmpty(&s);
	if (ret == 0)
	{
		printf("此栈不为空\n");
	}
	else
		printf("此栈为空\n");
	printf("\n");

	// 销毁栈 
	StackDestroy(&s);

	ret = StackEmpty(&s);
	if (ret == 0)
	{
		printf("此栈不为空\n");
	}
	else
		printf("此栈为空\n");
	printf("\n");

	system("pause");
	return 0;
}
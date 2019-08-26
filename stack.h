#pragma once


typedef int STDataType;

//静态栈
//#define N 10
//typedef struct Stack {
//	STDataType _a[N];    
//	int _top; 	// 栈顶 
//}Stack;


//动态栈
typedef struct Stack
{
	STDataType* _array;
	int _capacity;
	int _top; // 标记栈顶位置 
}Stack;

// 初始化栈 
void StackInit(Stack* ps);

// 入栈 
void StackPush(Stack* ps, STDataType data);

// 出栈 
void StackPop(Stack* ps);

// 获取栈顶元素 
STDataType StackTop(Stack* ps);

// 获取栈中有效元素个数 
int StackSize(Stack* ps);

// 检测栈是否为空，如果为空返回非零结果，如果不为空返回0 
int StackEmpty(Stack* ps);

// 销毁栈 
void StackDestroy(Stack* ps);

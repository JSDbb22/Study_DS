#pragma once


typedef int STDataType;

//��̬ջ
//#define N 10
//typedef struct Stack {
//	STDataType _a[N];    
//	int _top; 	// ջ�� 
//}Stack;


//��̬ջ
typedef struct Stack
{
	STDataType* _array;
	int _capacity;
	int _top; // ���ջ��λ�� 
}Stack;

// ��ʼ��ջ 
void StackInit(Stack* ps);

// ��ջ 
void StackPush(Stack* ps, STDataType data);

// ��ջ 
void StackPop(Stack* ps);

// ��ȡջ��Ԫ�� 
STDataType StackTop(Stack* ps);

// ��ȡջ����ЧԪ�ظ��� 
int StackSize(Stack* ps);

// ���ջ�Ƿ�Ϊ�գ����Ϊ�շ��ط������������Ϊ�շ���0 
int StackEmpty(Stack* ps);

// ����ջ 
void StackDestroy(Stack* ps);

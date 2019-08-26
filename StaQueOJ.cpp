#include <iostream>
using namespace std;
#include <string>
#include <stack>


bool isValid(string s) {
	stack<char> stack_ch;
	int size = s.size();
	for (int i = 0; i < size; ++i)
	{
		char ch = s[i];
		switch (ch)
		{
		case'(':
		case'[':
		case'{':
			stack_ch.push(ch);
			break;
		case')':
		case']':
		case'}':
		{
			if (stack_ch.empty())
				return false;

			char left = stack_ch.top();
			if (!(((left == '(') && (ch == ')'))
				|| ((left == '[') && (ch == ']'))
				|| ((left == '{') && (ch == '}'))))
				return false;

			stack_ch.pop();
			break;
		}
		default:
			break;
		}
	}

	if (!stack_ch.empty())
		return false;
	else
		return true;
}

// 用队列实现栈
class MyStack {
public:
	queue<int> q;

	/** Initialize your data structure here. */
	MyStack() {

	}

	/** Push element x onto stack. */
	void push(int x) {
		q.push(x);
	}

	/** Removes the element on top of the stack and returns that element. */
	int pop() {
		int size = q.size() - 1;
		for (int i = 0; i < size; ++i)
		{
			int data = q.front();
			q.pop();
			q.push(data);
		}

		int d = q.front();
		q.pop();

		return d;
	}

	/** Get the top element. */
	int top() {
		int size = q.size() - 1;
		for (int i = 0; i < size; ++i)
		{
			int data = q.front();
			q.pop();
			q.push(data);
		}

		int d = q.front();
		q.pop();
		q.push(d);

		return d;
	}

	/** Returns whether the stack is empty. */
	bool empty() {
		return q.empty();
	}
};

// 队列实现栈
class MyQueue
{
pubic:
	stack<int> left;
	stack<int> right;

	MyQueue()
	{}

	void push(int x)
	{
		right.push(x);
	}

	int pop()
	{
		if (left.empty())
		{
			int size = right.size();
			for (int i = 0; i < size; ++i)
			{
				int d = right.top();
				right.pop();
				left.push(d);
			}
		}

		int v = left.top();
		left.pop();
		return v;
	}


	int peek()
	{
		if (left.empty())
		{
			int size = right.size();
			for (int i = 0; i < size; ++i)
			{
				int d = right.top();
				right.pop();
				left.push(d);
			}
		}

		int v = left.top();
		return v;
	}
	bool empty()
	{
		return left.empty() && right.empty();
	}
};

class MinStack()
{
public:
	stack<int> normal;
	stack<int> min;

	MinStack()
	{}

	void push(int x)
	{
		normal.push(x);
		if (min.empty() || x <= min.top())
		{
			min.push(x);
		}
		else
			min.push(min.top());
	}

	void pop()
	{
		normal.pop();
		min.pop();
	}
	int top()
	{
		return normal.top();
	}
	int getMin()
	{
		return min.top();
	}
};

// 循环队列
class MyCircularQueue
{
public:
	int* array;
	int capacity;
	int size;
	int front;
	int rear;

	MyCircularQueue(int k)
	{
		array = new int[k];
		capacity = k;
		size = 0;
		front = 0;
		rear = 0;
	}

	bool enQueue(int value)
	{
		if (isFull())
			return false;

		array[rear] = value;
		++size;
		rear = (rear + 1) % capacity;
		return true;
	}

	bool deQueue()
	{
		if (isEmpty())
			return false;

		front = (front + 1) % capacity;
		--size;
		return true;
	}

	int front()
	{
		if (isEmpty())
			return -1;
		else
			return array[front];
	}

	int Rear()
	{
		if (isEmpty())
			return -1;
		else
		{
			int index = (rear + capacity - 1) % capacity;
			return array[index];
		}
	}

	bool isEmpty() {
		return size == 0;
	}

	bool isFull() {
		return size == capacity;
	}
};
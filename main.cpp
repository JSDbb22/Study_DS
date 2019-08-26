#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "a.h"


// ���������� 
Result CreateBinTree(BTDataType array[], int size)
{
	Result result;
	if (size == 0)
	{
		result.node = NULL;
		result.used = 0;
		return result;
	}

	if (array[0] == '#')
	{
		result.node = NULL;
		result.used = 1;
		return result;
	}

	//��
	BTNode *pRoot = (BTNode *)malloc(sizeof(BTNode));
	pRoot->_data = array[0];

	//������
	Result leftR = CreateBinTree(array + 1, size - 1);

	//������
	Result rightR = CreateBinTree(array + 1 + leftR.used, size - 1 - leftR.used);

	pRoot->_pLeft = leftR.node;	
	pRoot->_pRight = rightR.node;	

	result.node = pRoot;
	result.used = 1 + leftR.used + rightR.used;
	return result;
}


// ���������� 
BTNode* CopyBinTree(BTNode* pRoot)
{
	BTNode *newNode = NULL;
	if (pRoot == NULL)
		return NULL;
	else
	{
		newNode = (BTNode *)malloc(sizeof(BTNode));
		newNode->_data = pRoot->_data;
		newNode->_pLeft = CopyBinTree(pRoot->_pLeft);
		newNode->_pRight = CopyBinTree(pRoot->_pRight);
		
	}
	return newNode;
}


// ���ٶ����� 
void DestroyBinTree(BTNode** pRoot)
{
	assert(pRoot);
	if (*pRoot)
	{
		DestroyBinTree(&((*pRoot)->_pLeft));
		DestroyBinTree(&((*pRoot)->_pRight));
		free(*pRoot);
		*pRoot = NULL;
	}
}


// �����������ֱ�����ʽ 
void PreOrder(BTNode* pRoot)	//ǰ�����
{
	//����
	assert(pRoot);
		return;
	//���ڵ�
	printf("%c ", pRoot->_data);

	//������
	PreOrder(pRoot->_pLeft);

	//������
	PreOrder(pRoot->_pRight);
}

#include <stack>
using std::stack;
void PreOrderNor(BTNode* pRoot)		//�ǵݹ�ǰ�����
{
	stack<BTNode *> s;
	BTNode *cur = pRoot;
	while (!s.empty() || cur != NULL)
	{
		while (cur != NULL)
		{
			printf("%c ", cur->_data);
			s.push(cur);
			cur = cur->_pLeft;
		}

		BTNode *top = s.top();
		s.pop();

		cur = cur->_pRight;
	}
	printf("\n");
}

void InOrder(BTNode* pRoot)		//�������
{
	//����
	assert(pRoot);
		return;

	//������
	InOrder(pRoot->_pLeft);

	//��
	printf("%c ", pRoot->_data);

	//������
	InOrder(pRoot->_pRight);
}

void InOrderNor(BTNode* pRoot)		//�ǵݹ��������
{
	stack<BTNode *> s;
	BTNode *cur = pRoot;

	while (!s.empty() || cur != NULL) {
		while (cur != NULL) {
			s.push(cur);
			cur = cur->_pLeft;
		}

		BTNode *top = s.top();
		s.pop();
		printf("%c ", top->_data);

		cur = top->_pRight;
	}

	printf("\n");
}

void PostOrder(BTNode* pRoot)		//�������
{
	//����
	assert(pRoot);
		return;

	//������
	PostOrder(pRoot->_pLeft);

	//������
	PostOrder(pRoot->_pRight);

	//��
	printf("%c ", pRoot->_data);
}

void PostOrderNor(BTNode* pRoot)		////�ǵݹ�������
{
	stack<BTNode *> s;
	BTNode *cur = pRoot;
	BTNode *last = NULL;	// ��һ�α���������������ĸ����

	while (!s.empty() || cur != NULL) {
		while (cur != NULL) {
			s.push(cur);
			cur = cur->_pLeft;
		}

		BTNode *top = s.top();
		if (top->_pRight == NULL) {
			printf("%c ", top->_data);
			s.pop();

			last = top;
		}
		else if (top->_pRight == last) {

			printf("%c ", top->_data);
			s.pop();

			last = top;
		}
		else {
			cur = top->_pRight;
		}
	}

	printf("\n");
}

#include <queue>
using std::queue;
void LevelOrder(BTNode* pRoot)		//�������
{
	assert(pRoot);
	printf("\n");

	queue<BTNode *> q;
	q.push(pRoot);	
	while (!q.empty()) {
		BTNode *front = q.front();
		q.pop();

		printf("%c ", front->_data);
		if (front->_pLeft != NULL) {
			q.push(front->_pLeft);
		}
		if (front->_pRight != NULL) {
			q.push(front->_pRight);
		}
	}
	printf("\n");
}


// ��ȡ�������нڵ�ĸ��� 
int GetNodeCount(BTNode* pRoot)
{
	
	//����
	//����
	assert(pRoot);
		return 0;
	
	//�������ڵ����
	int left = GetNodeCount(pRoot->_pLeft);

	//�������ڵ����
	int right = GetNodeCount(pRoot->_pRight);

	return left + right + 1;
	
}


// ��������ĸ߶� 
int Height(BTNode* pRoot)
{
	//����
	assert(pRoot);
		return 0;
	
	//�������߶�
	int left = Height(pRoot->_pLeft);

	//�������߶�
	int right = Height(pRoot->_pRight);

	return ((left > right) ? left : right) + 1;
}


// ���������Ƿ�ƽ��O(N^2)
//ƽ�����������������ƽ������� && ��������ƽ������� && ���������ĸ߶Ȳ�����1
int IsBalanceTree(BTNode* pRoot)
{
	if (pRoot == NULL)
		return 1;
	int left = Height(pRoot->_pLeft);
	int right = Height(pRoot->_pRight);
	
	return IsBalanceTree(pRoot->_pLeft) && IsBalanceTree(pRoot->_pRight) && (abs(left - right) <= 1);
}


// ���������Ƿ�ƽ��O(N) 
int IsBalanceTree_P(BTNode* pRoot, int* height)
{
	//����
	if (pRoot == NULL)
	{
		return 1;
	}

	int left = 0;
	int right = 0;
	if (IsBalanceTree_P(pRoot->_pLeft, &left) || IsBalanceTree_P(pRoot->_pRight, &right))
	{
		int ret = left - right;
		if ((ret >= 1) || (ret <= -1))
			return 1;
	}

	return 0;
}


// ��ȡ��������Ҷ�ӽڵ�ĸ��� 
int GetLeafNodeCount(BTNode* pRoot)
{
	//����
	assert(pRoot);
		return 0;

	//ֻ�и��ڵ����
	if ((pRoot->_pLeft == NULL) && (pRoot->_pRight == NULL))
		return 1;

	//������Ҷ�ӽڵ����
	int left = GetLeafNodeCount(pRoot->_pLeft);

	//������Ҷ�ӽڵ����
	int right = GetLeafNodeCount(pRoot->_pRight);

	return left + right;
}


// ��ȡ��������K��ڵ�ĸ��� 
int GetKLevelNodeCount(BTNode* pRoot, int K)
{
	//����
	assert(pRoot);
		return 0;

	//��һ��
	if (K == 1)
		return 1;

	//������
	int left = GetKLevelNodeCount(pRoot->_pLeft, K - 1);

	//������
	int right = GetKLevelNodeCount(pRoot->_pRight, K - 1);

	return left + right;
}


// ��ȡ��������ĳ���ڵ��˫�׽ڵ� 
BTNode* GetNodeParent(BTNode* pRoot, BTNode* pNode)
{
	if ((pRoot == NULL) || (pNode == pRoot) || (pNode == NULL))
		return NULL;

	if ((pRoot->_pLeft != NULL) || (pNode->_pRight != NULL))
		return pNode;

	return GetNodeParent(pRoot, pNode);
}


// ��������ľ��� 
void Mirror(BTNode* pRoot)
{
	if ((pRoot == NULL) || ((pRoot->_pLeft == NULL) && (pRoot->_pRight == NULL)))
		return;

	BTNode *temp = pRoot->_pLeft;
	pRoot->_pLeft = pRoot->_pRight;
	pRoot->_pRight = temp;

	if (pRoot->_pLeft != NULL)
		Mirror(pRoot->_pLeft);

	if (pRoot->_pRight != NULL)
		Mirror(pRoot->_pRight);

}

void Test1() {
	BTDataType *array = "adsad";
	int size = strlen(array);
	Result result = CreateBinTree(array, size);

	LevelOrder(result.node);
}

int main()
{
	Test1();

	return 0;
}
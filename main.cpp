#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "a.h"


// 创建二叉树 
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

	//根
	BTNode *pRoot = (BTNode *)malloc(sizeof(BTNode));
	pRoot->_data = array[0];

	//左子树
	Result leftR = CreateBinTree(array + 1, size - 1);

	//右子树
	Result rightR = CreateBinTree(array + 1 + leftR.used, size - 1 - leftR.used);

	pRoot->_pLeft = leftR.node;	
	pRoot->_pRight = rightR.node;	

	result.node = pRoot;
	result.used = 1 + leftR.used + rightR.used;
	return result;
}


// 拷贝二叉树 
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


// 销毁二叉树 
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


// 二叉树的三种遍历方式 
void PreOrder(BTNode* pRoot)	//前序遍历
{
	//空树
	assert(pRoot);
		return;
	//根节点
	printf("%c ", pRoot->_data);

	//左子树
	PreOrder(pRoot->_pLeft);

	//右子树
	PreOrder(pRoot->_pRight);
}

#include <stack>
using std::stack;
void PreOrderNor(BTNode* pRoot)		//非递归前序遍历
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

void InOrder(BTNode* pRoot)		//中序遍历
{
	//空树
	assert(pRoot);
		return;

	//左子树
	InOrder(pRoot->_pLeft);

	//根
	printf("%c ", pRoot->_data);

	//右子树
	InOrder(pRoot->_pRight);
}

void InOrderNor(BTNode* pRoot)		//非递归中序遍历
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

void PostOrder(BTNode* pRoot)		//后序遍历
{
	//空树
	assert(pRoot);
		return;

	//左子树
	PostOrder(pRoot->_pLeft);

	//右子树
	PostOrder(pRoot->_pRight);

	//根
	printf("%c ", pRoot->_data);
}

void PostOrderNor(BTNode* pRoot)		////非递归后序遍历
{
	stack<BTNode *> s;
	BTNode *cur = pRoot;
	BTNode *last = NULL;	// 上一次被完整遍历完的树的根结点

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
void LevelOrder(BTNode* pRoot)		//层序遍历
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


// 获取二叉树中节点的个数 
int GetNodeCount(BTNode* pRoot)
{
	
	//递推
	//空树
	assert(pRoot);
		return 0;
	
	//左子树节点个数
	int left = GetNodeCount(pRoot->_pLeft);

	//右子树节点个数
	int right = GetNodeCount(pRoot->_pRight);

	return left + right + 1;
	
}


// 求二叉树的高度 
int Height(BTNode* pRoot)
{
	//空树
	assert(pRoot);
		return 0;
	
	//左子树高度
	int left = Height(pRoot->_pLeft);

	//右子树高度
	int right = Height(pRoot->_pRight);

	return ((left > right) ? left : right) + 1;
}


// 检测二叉树是否平衡O(N^2)
//平衡二叉树：左子树是平衡二叉树 && 右子树是平衡二叉树 && 左右子树的高度不超过1
int IsBalanceTree(BTNode* pRoot)
{
	if (pRoot == NULL)
		return 1;
	int left = Height(pRoot->_pLeft);
	int right = Height(pRoot->_pRight);
	
	return IsBalanceTree(pRoot->_pLeft) && IsBalanceTree(pRoot->_pRight) && (abs(left - right) <= 1);
}


// 检测二叉树是否平衡O(N) 
int IsBalanceTree_P(BTNode* pRoot, int* height)
{
	//空树
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


// 获取二叉数中叶子节点的个数 
int GetLeafNodeCount(BTNode* pRoot)
{
	//空树
	assert(pRoot);
		return 0;

	//只有根节点的数
	if ((pRoot->_pLeft == NULL) && (pRoot->_pRight == NULL))
		return 1;

	//左子树叶子节点个数
	int left = GetLeafNodeCount(pRoot->_pLeft);

	//右子树叶子节点个数
	int right = GetLeafNodeCount(pRoot->_pRight);

	return left + right;
}


// 获取二叉树第K层节点的个数 
int GetKLevelNodeCount(BTNode* pRoot, int K)
{
	//空树
	assert(pRoot);
		return 0;

	//第一层
	if (K == 1)
		return 1;

	//左子树
	int left = GetKLevelNodeCount(pRoot->_pLeft, K - 1);

	//右子树
	int right = GetKLevelNodeCount(pRoot->_pRight, K - 1);

	return left + right;
}


// 获取二叉树中某个节点的双亲节点 
BTNode* GetNodeParent(BTNode* pRoot, BTNode* pNode)
{
	if ((pRoot == NULL) || (pNode == pRoot) || (pNode == NULL))
		return NULL;

	if ((pRoot->_pLeft != NULL) || (pNode->_pRight != NULL))
		return pNode;

	return GetNodeParent(pRoot, pNode);
}


// 求二叉树的镜像 
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
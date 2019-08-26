#pragma once


typedef char BTDataType;

typedef struct BTNode
{
	struct BTNode* _pLeft;
	struct BTNode* _pRight;
	BTDataType _data;
}BTNode;

typedef struct {
	BTNode *node;	// 构建出的二叉树的根结点
	int used;	// 构建过程中使用的序列长度
}Result;

typedef int DataType;

struct Node
{
	struct Node *_firstChild1;		//第一个孩子节点
	struct Node *_pNextBrother;		//指向其下一个兄弟节点
	DataType _data;					//节点中的数据域
};


// 创建二叉树 
Result CreateBinTree(BTDataType array[], int size);

// 拷贝二叉树 
BTNode* CopyBinTree(BTNode* pRoot);

// 销毁二叉树 
void DestroyBinTree(BTNode** pRoot);
// 二叉树的三种遍历方式 
void PreOrder(BTNode* pRoot);		//前序遍历
void PreOrderNor(BTNode* pRoot);	//非递归前序遍历
void InOrder(BTNode* pRoot);		//中序遍历
void InOrderNor(BTNode* pRoot);		//非递归中序遍历
void PostOrder(BTNode* pRoot);		//后序遍历
void PostOrderNor(BTNode* pRoot);	//非递归后序遍历
void LevelOrder(BTNode* pRoot);		//层次遍历

// 获取二叉树中节点的个数 
int GetNodeCount(BTNode* pRoot);

// 求二叉树的高度 
int Height(BTNode* pRoot);

// 检测二叉树是否平衡O(N^2) 
int IsBalanceTree(BTNode* pRoot);
// 检测二叉树是否平衡O(N) 
int IsBalanceTree_P(BTNode* pRoot, int* height);

// 获取二叉数中叶子节点的个数 
int GetLeafNodeCount(BTNode* pRoot);

// 获取二叉树第K层节点的个数 
int GetKLevelNodeCount(BTNode* pRoot, int K);

// 获取二叉树中某个节点的双亲节点 
BTNode* GetNodeParent(BTNode* pRoot, BTNode* pNode);

// 求二叉树的镜像 
void Mirror(BTNode* pRoot);



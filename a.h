#pragma once


typedef char BTDataType;

typedef struct BTNode
{
	struct BTNode* _pLeft;
	struct BTNode* _pRight;
	BTDataType _data;
}BTNode;

typedef struct {
	BTNode *node;	// �������Ķ������ĸ����
	int used;	// ����������ʹ�õ����г���
}Result;

typedef int DataType;

struct Node
{
	struct Node *_firstChild1;		//��һ�����ӽڵ�
	struct Node *_pNextBrother;		//ָ������һ���ֵܽڵ�
	DataType _data;					//�ڵ��е�������
};


// ���������� 
Result CreateBinTree(BTDataType array[], int size);

// ���������� 
BTNode* CopyBinTree(BTNode* pRoot);

// ���ٶ����� 
void DestroyBinTree(BTNode** pRoot);
// �����������ֱ�����ʽ 
void PreOrder(BTNode* pRoot);		//ǰ�����
void PreOrderNor(BTNode* pRoot);	//�ǵݹ�ǰ�����
void InOrder(BTNode* pRoot);		//�������
void InOrderNor(BTNode* pRoot);		//�ǵݹ��������
void PostOrder(BTNode* pRoot);		//�������
void PostOrderNor(BTNode* pRoot);	//�ǵݹ�������
void LevelOrder(BTNode* pRoot);		//��α���

// ��ȡ�������нڵ�ĸ��� 
int GetNodeCount(BTNode* pRoot);

// ��������ĸ߶� 
int Height(BTNode* pRoot);

// ���������Ƿ�ƽ��O(N^2) 
int IsBalanceTree(BTNode* pRoot);
// ���������Ƿ�ƽ��O(N) 
int IsBalanceTree_P(BTNode* pRoot, int* height);

// ��ȡ��������Ҷ�ӽڵ�ĸ��� 
int GetLeafNodeCount(BTNode* pRoot);

// ��ȡ��������K��ڵ�ĸ��� 
int GetKLevelNodeCount(BTNode* pRoot, int K);

// ��ȡ��������ĳ���ڵ��˫�׽ڵ� 
BTNode* GetNodeParent(BTNode* pRoot, BTNode* pNode);

// ��������ľ��� 
void Mirror(BTNode* pRoot);



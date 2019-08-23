#pragma once


//��̬˳���

#define N 100 
typedef int DataType;

typedef struct SeqList {
	DataType array[N]; // �������� ���ؿƼ�
	size_t size;        // ��Ч���ݵĸ���   
}SeqList;


//��̬˳���

typedef int DataType;

typedef struct SeqList
{
	DataType* _array;	  // ����˳�������ЧԪ��
	int _capacity;		  // �ռ��ܴ�С������
	int _size;			  // ��ЧԪ�ظ��� 
						  // ͬʱҲ��ʾ�Ӻ�����һ������λ�õ��±�
}SeqList, *PSeqList;


//��ʼ��
void SeqListInit(PSeqList ps);


//����
void SeqListDestroy(PSeqList ps);

//�������
void CheckCapacity(PSeqList ps);


// β�� 
void SeqListPushBack(PSeqList ps, DataType data);


// βɾ 
void SeqListPopBack(PSeqList ps);


// ͷ�� 
void SeqListPushFront(PSeqList ps, DataType data);


// ͷɾ 
void SeqListPopFront(PSeqList ps);


// ����λ��(pos)���� 
void SeqListInsert(PSeqList ps, int pos, DataType data);


// ����λ��ɾ�� 
void SeqListErase(PSeqList ps, int pos);


// �Ƴ�˳����е�һ��ֵΪdata��Ԫ�� 
void SeqListRemove(PSeqList ps, DataType data);


// �Ƴ�˳���������ֵΪdata��Ԫ�� 
void SeqListRemoveAll(PSeqList ps, DataType data);


// ��ȡ˳�����ЧԪ�ظ���
int SeqListSize(PSeqList ps);


// ��ȡ˳��������� 
int  SeqListCapacity(PSeqList ps);


// ���˳����Ƿ�Ϊ�� 
int SeqListEmpty(PSeqList ps);

// ��ȡ˳����е�һ��Ԫ�� 
int SeqListFront(PSeqList ps);


// ��ȡ˳��������һ��Ԫ�� 
int SeqListBack(PSeqList ps);


//��ӡ
void SeqListPrint(SeqList *ps);
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "Seqlist.h"


//��ʼ��
void SeqListInit(PSeqList ps)
{
	assert(ps != NULL);
	ps->_capacity = 10;
	ps->_array = (DataType *)malloc(sizeof(DataType)*ps->_capacity);
	ps->_size = 0;
}

//����
void SeqListDestroy(PSeqList ps)
{
	assert(ps != NULL);
	assert(ps->_array);
	free(ps->_array);

	ps->_array = NULL;
	ps->_capacity = 0;
	ps->_size = 0;
}

//�������
void CheckCapacity(PSeqList ps)
{
	assert(ps);
	if (ps->_size < ps->_capacity)
	{
		return;
	}

	int new_capacity = ps->_capacity * 2;
	DataType *new_array = (DataType *)malloc(sizeof(DataType)*new_capacity);
	assert(new_array);

	//����Ԫ��
	for (int i = 0; i < ps->_size; ++i)
	{
		new_array[i] = ps->_array[i];
	}

	//�ͷ�ԭ���Ŀռ䣬���¿ռ䣬�Լ��޸�˳�����Ϣ
	free(ps->_array);
	ps->_array = new_array;
	ps->_capacity = new_capacity;
}

// β�� 
void SeqListPushBack(PSeqList ps, DataType data)
{
	CheckCapacity(ps);
	ps->_array[ps->_size] = data;
	++ps->_size;
}

// βɾ 
void SeqListPopBack(PSeqList ps)
{
	assert(ps->_size > 0);
	--ps->_size;
}

// ͷ��
//��Ҫ������Ԫ�������ƣ�����Ϊ�˷�ֹ�������ݣ���Ҫ�����һ��Ԫ�ؿ�ʼ����
void SeqListPushFront(PSeqList ps, DataType data)
{
	CheckCapacity(ps);
	for (int i = ps->_size - 1; i >= 0; --i)
	{
		ps->_array[i + 1] = ps->_array[i];
	}
	ps->_array[0] = data;
	++ps->_size;
}

// ͷɾ
//������Ԫ����ǰ���ƣ��ӵ�һ��Ԫ�ؿ�ʼֱ�Ӹ�������ǰһ��λ��Ԫ�ؼ���
//���ܴ����һ��Ԫ�ذ��ƣ�Ҳ��Ϊ�˷�ֹ����ǰһ��Ԫ�أ���ʧ����
void SeqListPopFront(PSeqList ps)
{
	assert(ps->_size > 0);
	for (int i = 1; i < ps->_size; ++i)
	{
		ps->_array[i - 1] = ps->_array[i];
	}
	--ps->_size;
}

// ����λ��(pos)���� 
//�Ƚ� pos λ�õ� size Ԫ�������ƣ������ pos λ�ò��� data Ԫ�أ�������ͷ��
void SeqListInsert(PSeqList ps, int pos, DataType data)
{
	CheckCapacity(ps);
	for (int i = ps->_size - 1; i >= pos - 1; --i)
	{
		ps->_array[i + 1] = ps->_array[i];
	}
	ps->_array[pos-1] = data;
	++ps->_size;
}

// ����λ��ɾ��
//�� pos λ�õ� size λ��Ԫ����ǰ���ƣ�������ͷɾ
void SeqListErase(PSeqList ps, int pos)
{
	assert(ps->_size > 0);
	for (int i = pos; i < ps->_size; ++i)
	{
		ps->_array[i - 1] = ps->_array[i];
	}
	--ps->_size;
}

// ���data��˳����� 
int SeqListFind(PSeqList ps, DataType data)
{
	assert(ps);
	for (int i = 0; i < ps->_size; ++i)
	{
		if (ps->_array[i] == data)
		{
			return i+1;		
			//������Ҫ���ǿռ�λ���±꣬�� i �����ݴ洢�±꣬������Ҫ +1
		}
	}
	return -1;
}

// �Ƴ�˳����е�һ��ֵΪdata��Ԫ��
//�ȵ��� SeqListFind �ҵ� data Ԫ�ؿռ�λ���±�
//�ٵ��� SeqListErase ɾ����ǰλ��Ԫ��
void SeqListRemove(PSeqList ps, DataType data)
{
	int pos = SeqListFind(ps, data);
	if (pos != -1)
	{
		SeqListErase(ps, pos);
	}
}

// �Ƴ�˳���������ֵΪdata��Ԫ��
//����Ҫɾ��ֱ���ú�һ��Ԫ�ظ��ǵ�ǰԪ�أ����ó��µ�˳���
void SeqListRemoveAll(PSeqList ps, DataType data)
{
	int i, j;
	for (i = 0, j = 0; i < ps->_size; ++i)
	{
		if (ps->_array[i] != data)
		{
			ps->_array[j] = ps->_array[i];
			++j;
		}
	}
	ps->_size = j;
}

// ��ȡ˳�����ЧԪ�ظ���
int SeqListSize(PSeqList ps)
{
	assert(ps);
	return ps->_size;
}

// ��ȡ˳�������� 
int SeqListCapacity(PSeqList ps)
{
	assert(ps);
	return ps->_capacity;
}

// ���˳����Ƿ�Ϊ�� 
int SeqListEmpty(PSeqList ps)
{
	assert(ps);
	if (ps->_size == 0)
	{
		printf("˳���Ϊ��\n");
	}
	else
	{
		printf("˳���Ϊ��\n");
	}
	return 0;
}

// ��ȡ˳����е�һ��Ԫ�� 
DataType SeqListFront(PSeqList ps)
{
	assert(ps);
	return ps->_array[0];
}

// ��ȡ˳��������һ��Ԫ�� 
DataType SeqListBack(PSeqList ps)
{
	assert(ps);
	return ps->_array[ps->_size - 1];
}

//��ӡ
void SeqListPrint(PSeqList ps)
{
	for (int i = 0; i < ps->_size; ++i)
	{
		printf("%d ", ps->_array[i]);
	}
	printf("\n");
}

int main()
{
	SeqList ps;
	SeqListInit(&ps);

	SeqListEmpty(&ps);			//�ж�˳����Ƿ�Ϊ��

	SeqListPushFront(&ps, 5);		//ͷ��
	SeqListPushFront(&ps, 4);
	SeqListPushFront(&ps, 3);
	SeqListPushFront(&ps, 2);
	SeqListPushFront(&ps, 1);
	SeqListPrint(&ps);	//1 2 3 4 5

	SeqListPushBack(&ps, 6);		//β��
	SeqListPushBack(&ps, 7);
	SeqListPushBack(&ps, 8);
	SeqListPushBack(&ps, 9);
	SeqListPrint(&ps);		//1 2 3 4 5 6 7 8 9

	SeqListPopFront(&ps);		//ͷɾ
	SeqListPrint(&ps);			//2 3 4 5 6 7 8 9

	SeqListPopBack(&ps);		//βɾ
	SeqListPrint(&ps);			//2 3 4 5 6 7 8

	SeqListInsert(&ps, 3, 6);		//����λ�ò���
	SeqListPrint(&ps);			//2 3 6 4 5 6 7 8

	SeqListErase(&ps, 4);		//����λ��ɾ��
	SeqListPrint(&ps);			//2 3 6 5 6 7 8

	SeqListRemove(&ps, 6);		//ɾ����һ��ֵΪ6��Ԫ��
	SeqListPrint(&ps);			//2 3 5 6 7 8

	SeqListInsert(&ps, 3, 8);	//2 3 8 5 6 7 8
	SeqListInsert(&ps, 8, 8);	//2 3 8 5 6 7 8 8
	SeqListPrint(&ps);
	SeqListRemoveAll(&ps, 8);		//ɾ������ֵΪ8��Ԫ��
	SeqListPrint(&ps);				//2 3 5 6 7

	printf("%d\n", SeqListSize(&ps));		//��ȡ��ȡ˳�����ЧԪ�ظ�����5
	
	printf("%d\n", SeqListCapacity(&ps));		//��ȡ˳����������10

	printf("%d\n", SeqListFront(&ps));		//��ȡ��ȡ˳����һ��Ԫ�أ�2

	printf("%d\n", SeqListBack(&ps));		//��ȡ��ȡ˳������һ��Ԫ�أ�7

	SeqListInsert(&ps, 3, 6);
	SeqListInsert(&ps, 3, 8);
	SeqListInsert(&ps, 3, 2);
	SeqListInsert(&ps, 3, 1);
	SeqListInsert(&ps, 3, 9);
	SeqListPrint(&ps);		//2 3 9 1 2 8 6 5 6 7,��ǰ��������
	
	//����
	SeqListInsert(&ps, 3, 9);
	SeqListInsert(&ps, 5, 9);
	SeqListPrint(&ps);		//2 3 9 9 9 1 2 8 6 5 6 7

	SeqListEmpty(&ps);			//�ж�˳����Ƿ�Ϊ��

	SeqListDestroy(&ps);		//����˳���

	system("pause");
	return 0;
}
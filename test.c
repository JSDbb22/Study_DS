#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "Seqlist.h"


//初始化
void SeqListInit(PSeqList ps)
{
	assert(ps != NULL);
	ps->_capacity = 10;
	ps->_array = (DataType *)malloc(sizeof(DataType)*ps->_capacity);
	ps->_size = 0;
}

//销毁
void SeqListDestroy(PSeqList ps)
{
	assert(ps != NULL);
	assert(ps->_array);
	free(ps->_array);

	ps->_array = NULL;
	ps->_capacity = 0;
	ps->_size = 0;
}

//检查容量
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

	//搬移元素
	for (int i = 0; i < ps->_size; ++i)
	{
		new_array[i] = ps->_array[i];
	}

	//释放原来的空间，绑定新空间，以及修改顺序表信息
	free(ps->_array);
	ps->_array = new_array;
	ps->_capacity = new_capacity;
}

// 尾插 
void SeqListPushBack(PSeqList ps, DataType data)
{
	CheckCapacity(ps);
	ps->_array[ps->_size] = data;
	++ps->_size;
}

// 尾删 
void SeqListPopBack(PSeqList ps)
{
	assert(ps->_size > 0);
	--ps->_size;
}

// 头插
//需要将所有元素向后搬移，但是为了防止覆盖数据，需要从最后一个元素开始搬移
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

// 头删
//将所有元素向前搬移，从第一个元素开始直接覆盖它的前一个位置元素即可
//不能从最后一个元素搬移，也是为了防止覆盖前一个元素，丢失数据
void SeqListPopFront(PSeqList ps)
{
	assert(ps->_size > 0);
	for (int i = 1; i < ps->_size; ++i)
	{
		ps->_array[i - 1] = ps->_array[i];
	}
	--ps->_size;
}

// 任意位置(pos)插入 
//先将 pos 位置到 size 元素向后搬移，最后在 pos 位置插入 data 元素，类似与头插
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

// 任意位置删除
//将 pos 位置到 size 位置元素向前搬移，类似与头删
void SeqListErase(PSeqList ps, int pos)
{
	assert(ps->_size > 0);
	for (int i = pos; i < ps->_size; ++i)
	{
		ps->_array[i - 1] = ps->_array[i];
	}
	--ps->_size;
}

// 检测data在顺序表中 
int SeqListFind(PSeqList ps, DataType data)
{
	assert(ps);
	for (int i = 0; i < ps->_size; ++i)
	{
		if (ps->_array[i] == data)
		{
			return i+1;		
			//我们需要的是空间位置下标，而 i 是数据存储下标，所以需要 +1
		}
	}
	return -1;
}

// 移除顺序表中第一个值为data的元素
//先调用 SeqListFind 找到 data 元素空间位置下标
//再调用 SeqListErase 删除当前位置元素
void SeqListRemove(PSeqList ps, DataType data)
{
	int pos = SeqListFind(ps, data);
	if (pos != -1)
	{
		SeqListErase(ps, pos);
	}
}

// 移除顺序表中所有值为data的元素
//若需要删除直接用后一个元素覆盖当前元素，最后得出新的顺序表
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

// 获取顺序表有效元素个数
int SeqListSize(PSeqList ps)
{
	assert(ps);
	return ps->_size;
}

// 获取顺序表的容量 
int SeqListCapacity(PSeqList ps)
{
	assert(ps);
	return ps->_capacity;
}

// 检测顺序表是否为空 
int SeqListEmpty(PSeqList ps)
{
	assert(ps);
	if (ps->_size == 0)
	{
		printf("顺序表为空\n");
	}
	else
	{
		printf("顺序表不为空\n");
	}
	return 0;
}

// 获取顺序表中第一个元素 
DataType SeqListFront(PSeqList ps)
{
	assert(ps);
	return ps->_array[0];
}

// 获取顺序表中最后一个元素 
DataType SeqListBack(PSeqList ps)
{
	assert(ps);
	return ps->_array[ps->_size - 1];
}

//打印
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

	SeqListEmpty(&ps);			//判断顺序表是否为空

	SeqListPushFront(&ps, 5);		//头插
	SeqListPushFront(&ps, 4);
	SeqListPushFront(&ps, 3);
	SeqListPushFront(&ps, 2);
	SeqListPushFront(&ps, 1);
	SeqListPrint(&ps);	//1 2 3 4 5

	SeqListPushBack(&ps, 6);		//尾插
	SeqListPushBack(&ps, 7);
	SeqListPushBack(&ps, 8);
	SeqListPushBack(&ps, 9);
	SeqListPrint(&ps);		//1 2 3 4 5 6 7 8 9

	SeqListPopFront(&ps);		//头删
	SeqListPrint(&ps);			//2 3 4 5 6 7 8 9

	SeqListPopBack(&ps);		//尾删
	SeqListPrint(&ps);			//2 3 4 5 6 7 8

	SeqListInsert(&ps, 3, 6);		//任意位置插入
	SeqListPrint(&ps);			//2 3 6 4 5 6 7 8

	SeqListErase(&ps, 4);		//任意位置删除
	SeqListPrint(&ps);			//2 3 6 5 6 7 8

	SeqListRemove(&ps, 6);		//删除第一个值为6的元素
	SeqListPrint(&ps);			//2 3 5 6 7 8

	SeqListInsert(&ps, 3, 8);	//2 3 8 5 6 7 8
	SeqListInsert(&ps, 8, 8);	//2 3 8 5 6 7 8 8
	SeqListPrint(&ps);
	SeqListRemoveAll(&ps, 8);		//删除所有值为8的元素
	SeqListPrint(&ps);				//2 3 5 6 7

	printf("%d\n", SeqListSize(&ps));		//获取获取顺序表有效元素个数，5
	
	printf("%d\n", SeqListCapacity(&ps));		//获取顺序表的容量，10

	printf("%d\n", SeqListFront(&ps));		//获取获取顺序表第一个元素，2

	printf("%d\n", SeqListBack(&ps));		//获取获取顺序表最后一个元素，7

	SeqListInsert(&ps, 3, 6);
	SeqListInsert(&ps, 3, 8);
	SeqListInsert(&ps, 3, 2);
	SeqListInsert(&ps, 3, 1);
	SeqListInsert(&ps, 3, 9);
	SeqListPrint(&ps);		//2 3 9 1 2 8 6 5 6 7,当前容量已满
	
	//扩容
	SeqListInsert(&ps, 3, 9);
	SeqListInsert(&ps, 5, 9);
	SeqListPrint(&ps);		//2 3 9 9 9 1 2 8 6 5 6 7

	SeqListEmpty(&ps);			//判断顺序表是否为空

	SeqListDestroy(&ps);		//销毁顺序表

	system("pause");
	return 0;
}
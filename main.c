#include <stdio.h>
#include <assert.h>
#include <stdlib.h>


// ͷ��
Node->next = node;
head = node;

// ͷɾ
head = head->next;

//β��
last = findlastnode(head);
last->next = node;
node->next = NULL;
//βɾ
�����ڶ��� = find�����ڶ���(head);
�����ڶ���->next = NULL;

// ��ת����
struct ListNode* reverseList(struct ListNode* head)
{
	struct  ListNode* newHead = NULL;
	
	struct ListNode* cur = head;
	while (cur != NULL)
	{
		struct ListNode* node = cur;
		cur = cur->next;

		// �� node ���뵽������newHead��
		node->next = newHead;
		newHead = node;
	}

	return newHead;
}

struct ListNode* reverseList(struct ListNode* head)
{
	if (head == NULL||head->next==NULL)
		return head;

	struct ListNode* p1 = NULL;
	struct ListNode* p2 = head;
	struct ListNode* p3 = head->next;

	while (p2!=NULL)
	{
		p2->next = p1;
		p1 = p2;
		p2 = p3;
		if (p1 != NULL)
		{
			p3 = p3->next;
		}
	}

	return head;
}

// ɾ�������и���ֵ val �����нڵ�
struct ListNode* removeElements(struct ListNode* head, int val)
{
	if(head==NULL)
		return NULL;

	// �Ȳ��ܵ�һ���ڵ�
	struct ListNode* cur = head;
	while (cur->next != NULL)
	{
		if (cur->next->val == val)
		{
			struct ListNode* next = cur->next->next;
			free(cur->next);
			cur->next = next;
		}
		else
			cur = cur->next;
	}

	if (head->val == val)
	{
		struct ListNode* newHead = head->next;
		free(head);
		return newHead;
	}
	else
		return head;
}

// ������м�ڵ�
struct ListNode* middleNode(struct ListNode* head)
{
	if (head == NULL || head->next == NULL)
		return head;

	struct ListNode* fast = head;
	struct ListNode* slow = head;

	while (fast != NULL)
	{
		fast = fast->next;
		if (fast == NULL)
			break;

		slow = slow->next;
		fast = fast->next;
	}
	return head;
}

// �����е����� k ���ڵ�
ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
	ListNode* front = pListHead;
	ListNode* back = pListHead;

	unsigned i = 0;
	for (i = 0; front != NULL && i < k; ++i)
	{
		front = front->next;
	}

	if (i < k)
		return NULL;
	while (front)
	{
		front = front->next;
		back = back->next;
	}

	return back;
}

// �ϲ�������������
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
	if (l1 == NULL)
		return l2;

	if (l2 == NULL)
		return l1;

	struct ListNode* p1 = l1;
	struct ListNode* p2 = l2;
	struct ListNode* ret = NULL;
	struct ListNode* tail = NULL;

	while (p1 != NULL && p2 != NULL)
	{
		if (p1->val <= p2->val)
		{
			if (tail == NULL)
				ret = tail = p1;
			else
			{
				tail->next = p1;
				tail = p1;
			}

			p1 = p1->next;
		}
		else
		{
			if (tail == NULL)
				ret = tail = p2;
			else
			{
				tail->next = p2;
				tail = p2;
			}

			p2 = p2->next;
		}
	}

	if (p1 == NULL)
	{
		tail->next = p2;
	}
	else
		tail->next = p1;

	return ret;
}

// ��ת������
Node* Reverse(Node* head)
{
	Node* prev= NULL:
	Node * cur = head;

	while (cur != NULL)
	{
		Node* next = cur->next;

		cur->next = prev;
		prev = cur;
		cur = next;
	}

	return prev;
}

// ����ָ�
ListNode* partition(ListNode* pHead, int x) {
	if (pHead == NULL || pHead->next == NULL)
		return pHead;

	ListNode* small=NULL;
	ListNode* small_tail = NULL;
	ListNode* big = NULL;
	ListNode* big_tail = NULL;
	
	for (ListNode* p = pHead; p != NULL; p = p->next)
	{
		if (p->val < x)
		{
			if (small_tail == NULL)
				small = small_tail = p;
			else
			{
				small_tail->next = p;
				small_tail = p;
			}
		}
		else
		{
			if (big_tail == NULL)
				big = big_tail = p;
			else
			{
				big_tail->next = p;
				big_tail = p;
			}
		}
	}

	if (small_tail != NULL)
		small_tail->next = big;

	if (big_tail != NULL)
		big_tail->next = NULL;

	if (small != NULL)
		return small;
	else
		return big;
}

ListNode* partition2(ListNode* pHead, int x) {
	if (pHead == NULL || pHead->next == NULL)
		return pHead;

	ListNode* small = NULL;
	ListNode* big = NULL;
	ListNode* next;

	for (ListNode* p = pHead; p != NULL; p =next)
	{
		next = p->next;
		if (p->val < x)
		{
			p->next = small;
			small = p;
		}
		else
		{
			p->next = big;
			big = p;
		}
	}

	small = reverse(small);
	big = reverse(big);
}

// ɾ���������ظ��ڵ�
ListNode* deleteDuplication(ListNode* pHead)
{
	if (pHead == NULL)
		return pHead;

	//	�ٽڵ���Ϊ��һ�����ܱ�ɾ��
	ListNode* fake = (ListNode*)malloc(sizeof(ListNode));
	fake->next = pHead;

	ListNode* prev = fake;
	ListNode* p1 = pHead;
	ListNode* p2 = pHead->next;

	while (p2 != NULL)
	{
		if (p1->val != p2->val)
		{
			prev = p1;
			p1 = p2;
			p2 = p2->next;
		}
		else
		{
			while (p2 != NULL && p1->val = p2->val)
				p2 = p2->next;

			prev->next = p2;
			p1 = p2;
			if (p2 != NULL)
				p2 = p2->next;
		}
	}

	pHead = fake->next;
	free(fake);

	return pHead;
}

// ����Ļ��Ľṹ
bool 

// �ҵ������������ཻ����ʼ�ڵ�
int GetLength(struct ListNode* head)
{
	int l = 0;
	for (struct ListNode* n = head; n != NULL; n = n->next)
		++l;

	return l;
}

struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
	if (headA == NULL || headB == NULL)
		return NULL;

	int lenA = GetLength(headA);
	int lenB = GetLength(headB);

	struct ListNode* longer = headA;
	struct ListNode* shorter = headb;

	int diff = lenA - lenB;
	if (lenA < lenB)
	{
		longer = headB;
		shorter = headA;
		diff = lenb - lenA;
	}

	for (int i = 0; i < diff; ++i)
		longer = longer->next;

	while (longer != shorter)
	{
		longer = longer->next;
		shorter = shorter->next;
	}

	return longer;
}

// �ж��������Ƿ��л�
bool hasCycle(struct ListNode *head) {
	if (head == NULL)
		return false;

	struct ListNode* fast = head;
	struct ListNode* slow = head;

	while (1)
	{
		if (fast == NULL)
			return false;

		fast = fast->next;
		if (fast == NULL)
			return false;
		fast = fast->next;
		slow = slow->next;
		if (slow == fast)
			return true;
	}
}

// ����һ��������������ʼ�뻷�ĵ�һ���ڵ㡣 ��������޻����򷵻� null
struct ListNode *detectCycle(struct ListNode *head) {
	if (head == NULL)
		return NULL;

	struct ListNode* fast = head;
	struct ListNode* slow = head;

	while (1)
	{
		fast = fast->next;
		if (fast == NULL)
			return NULL;

		fast = fast->next;
		if (fast == NULL)
			return NULL;

		slow = slow->next;
		if (slow == fast)
			break;
	}

	struct ListNode* n1 = head;
	struct ListNode* n2 = slow;

	while (n1 != n2)
	{
		n1 = n1->next;
		n2 = n2->next;
	}

	return n1;
}

// ���ƴ����ָ�������
typedef struct RNode
{
	int value;
	struct RNode* next;
	struct RNode* random;
}RNode;

Node* copyRandomList(Node* head) {
	if (head == NULL)
		return NULL;

	// ����������ÿһ���ڵ㡣��ÿ���½ڵ�����Ͻڵ�ĺ���
	Node* cur = head;
	while (cur != NULL)
	{
		Node* newNode = new Node(cur->val, cur->next, NULL);
		cur->next = newNode;

		cur = cur->next->next;
	}

	// ���� random ��ָ���ϵ
	cur = head;
	while (cur != NULL)
	{
		Node* newNode = cur->next;
		if (cur->random != NULL)
		{
			newNode->random = cur->random->next;
		}

		cur = cur->next->next;
	}

	// ����������������
	cur = head;
	Node* newHead = NULL;
	if (head != NULL)
	{
		newHead = head->next;
	}
	while (cur != NULL)
	{
		Node* newNode = cur->next;
		cur->next = newNode->next;
		if (newNode->next != NULL)
		{
			newNode->next = newNode->next->next;
		}

		cur = cur->next;
	}

	return newHead;
}
#include "LinkList.h"
#include <iostream>

using namespace std;

void CreatHeadList(Node *&L,int length)
{
	Node* p,*Head;
	
	L = (Node*)malloc(sizeof(Node));
	L->data = -1;
	L->Next = NULL;
	Head = L;

	for (int i = 0;i < length;i++)
	{
		p = (Node*)malloc(sizeof(Node));
		p->data = i;
		p->Next = Head->Next;
		Head->Next = p;
		L = p;
	}
	Head ->Next = L;
	L = Head;
}

void CreatTailList(Node *&L,int length)
{
	Node* p,*r;

	L = (Node*)malloc(sizeof(Node));
	L->data = -1;
	L->Next = NULL;
	r = L;

	for (int i = 0;i < length;i++)
	{
		p = (Node*)malloc(sizeof(Node));
		p->data = i;
		r->Next = p;
		r = p;
	}
	r ->Next = NULL;
}

void InsertNodeHeade(Node *&L,int val)
{
	Node* p,*Head;
	Head = L;

	p = (Node*)malloc(sizeof(Node));
	p->data = val;
	p->Next = Head->Next;
	Head->Next = p;
	L = p;

	Head ->Next = L;
	L = Head;
}

//尾结点插入方法（易错）
void InsertNodeTail(Node *&L,int val)
{
	Node* p,*r;
	p = (Node*)malloc(sizeof(Node));

    r = L;

	while(r->Next)
	{
		r = r->Next;
	}

	p = (Node*)malloc(sizeof(Node));
	p->data = val;
	p->Next = NULL;
	r->Next = p;
}

void PrintList(Node *L)
{
	Node* p;
	p = L->Next;
	while (p)
	{
		cout << p->data;
		p = p->Next;
	}
	cout << endl;
}

bool GetElem(LinkList L,int index,int *e)
{
	LinkList p;
	p = L->Next;
	int j = 1;
	
	while (j<index && p)
	{
		j++;
		p = p->Next; 
	}

	if (!p ||j>index)
	{
		return false;
	}

	*e = p->data;
	return true;
}

bool DeleteElem(LinkList *L,int index)
{
	LinkList p,q,e;
	e = (Node*)malloc(sizeof(Node));

	p = (*L)->Next;
	int j = 1;

	while(j<index && p)
	{
		j++;
		q = p;
		p = p->Next;
	}
	if (!p || j>index)
	{
		return false;
	}
	
	q->Next = p->Next;
	e->data = p->data;
	e->Next = NULL;
	free(p);
	delete e;
}


bool ListInsert(LinkList *L,int index,int val)
{
	LinkList p,q,e;
	q = (Node*)malloc(sizeof(Node));
	p = (*L)->Next;
	int j =1;

	while(p && j<index)
	{
		j++;
		e = p;
		p = p->Next;
	}
	
	q->data = val;
	q->Next = p;
	e->Next = q;

	return true;
}

bool ClearList(LinkList *L)
{
	LinkList p;
	
	while((*L)->Next)
	{
		p = (Node*)malloc(sizeof(Node));
		p->data = (*L)->Next->data;
		p->Next = NULL;
		free(p);
		*L = (*L)->Next;
	}

	return true;

}
int GetListLength(LinkList L)
{
	LinkList p;
	p = L->Next;
	int j =0;
	while(p)
	{
		j++;
		p = p->Next;
	}
	return j;
}

int main()
{
	LinkList L= NULL;
	LinkList L1= NULL;

	cout<< "头插法创建链表"<< endl;
	CreatHeadList(L,5);
	PrintList(L);

	cout<< "尾插法创建链表"<< endl;
	CreatTailList(L1,5);
	PrintList(L1);

	cout<< "头插法插入链表"<< endl;
	InsertNodeHeade(L,5);
	PrintList(L);

	cout<< "尾插法创建链表"<< endl;
	InsertNodeTail(L,6);
	PrintList(L);

	cout<< "读取链表"<< endl;
	int *e;
	e = (int*)malloc(sizeof(int));
	GetElem(L,1,e);
	cout<< *e <<endl;
	PrintList(L);

	cout<< "删除链表第2个值"<< endl;
	DeleteElem(&L,2);
	PrintList(L);

	cout<< "链表插入第2个值"<< endl;
	ListInsert(&L,2,4);
	PrintList(L);
	cout<<"链表长度："<<GetListLength(L)<<endl;

	cout<< "删除链表"<< endl;
	ClearList(&L);
	PrintList(L);
	cout<<"链表长度："<<GetListLength(L)<<endl;
	
	system("pause");

	return 0;
}

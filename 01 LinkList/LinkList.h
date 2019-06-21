#pragma once

typedef struct Node
{
	int data;
	struct Node* Next;
}Node,*LinkList;

void CreatHeadList(Node *&L,int length);
void CreatTailList(Node *&L,int length);
void InsertNodeHeade(Node *&L,int val);
void InsertNodeTail(Node *&L,int val);
void PrintList(Node *L);
bool GetElem(LinkList L,int index,int *e);
bool DeleteElem(LinkList *L,int index);
bool ListInsert(LinkList *L,int index,int val);
bool ClearList(LinkList *L);
int GetListLength(LinkList L);
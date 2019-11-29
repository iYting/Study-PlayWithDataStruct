#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE  20
#define ERROR    0
#define OK       1
#define TRUE     1
#define FALSE    0
typedef int Status;
typedef int ElemType;

typedef struct Link {
	ElemType data;
	struct Link * Next;
}Link;

typedef struct Link * LinkList;

Status initList(LinkList *L)
{
	*L = (LinkList)malloc(sizeof(Link));
	(*L)->Next = NULL;
	if(!(*L))
	{
		return ERROR;
	}

	return OK;
}
Status ListInsert(LinkList *Link, int pos, ElemType val)
{
	if(pos<1)
	{
		puts("插入位置有误");
		return ERROR;
	}
	LinkList p;
	int j = 1;
	p = *Link;
	while(p && j<pos)
	{
		j++;
		p = p->Next;
	}
	LinkList m = (LinkList)malloc(sizeof(Link));
	m->data = val;
	m->Next = p->Next;
	p->Next = m;
	return OK;
}
int ListLength(LinkList L)
{
	int j = 0;
	LinkList i = L->Next;
	while(i)
	{
		j++;
		i = i->Next;
	}
	return j;
}
void showList(LinkList L)
{
	LinkList p = L->Next;
	while(p)
	{
		printf("%d\n",p->data );
		p = p->Next;
	}
}
Status ListDelete(LinkList *Link, int pos, int *e)
{
	if(pos<1)
	{
		return ERROR;
	}
	int j = 1;
	LinkList n,q;
	n = (*Link);
	while(n && j < pos)
	{
		j++;
		n = n->Next;
	}
	q = n->Next;
	n->Next = q->Next;
	free(q);


	//printf("%d\n",n->data );
	return OK;
}
Status GetElem(LinkList L,int pos, ElemType *e)
{
	if(pos<1)
	{
		return ERROR;
	}
	LinkList n;
	n = L->Next;
	int j = 1;
	while(n && j < pos )
	{
		++j;
		n = n->Next;
	}
	if ( !n || j>pos )
		return ERROR;  /*  第i个元素不存在 */

	return OK;
}
int main(int argc, char const *argv[])
{
	LinkList L;
	initList(&L);
	ListInsert(&L,1,10);
	ListInsert(&L,2,20);
	ListInsert(&L,3,30);
	printf("%d\n",ListLength(L) );
	return 0;
}

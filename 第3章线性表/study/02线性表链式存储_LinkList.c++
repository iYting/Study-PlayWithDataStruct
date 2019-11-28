#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXSIZE 20

typedef int Status;
typedef int ElemType;

typedef struct Node
{
	ElemType data;
	struct Node * next;
}Node;

typedef struct Node *LinkList;

/*初始化*/
Status InitList(LinkList *L){

	*L = (LinkList)malloc(sizeof(Node));
	(*L)->next = NULL;
	if(!(*L))
	{
		return ERROR;
	}
	return OK;
}
Status ListEmpty(LinkList L)
{
	if(L->next)
	{
		return FALSE;
	} else {
		return TRUE;
	}
}
Status ListInsert(LinkList *L,int pos,ElemType data)
{
	if(pos<1)
	{
		puts("初始化位置有误");
		exit(0);
	}
	LinkList p,s;
	p = *L;
	int j = 1;
	while(p && j<pos)
	{

		p = p->next;
		++j;
	}
	s = (LinkList)malloc(sizeof(Node));
	s->data = data;
	s->next = p->next;
	p->next=s;
	return OK;
}
Status visit(ElemType c)
{
    printf("%d ",c);
    return OK;
}
/* 初始条件：顺序线性表L已存在 */
/* 操作结果：依次对L的每个数据元素输出 */
Status ListTraverse(LinkList L)
{
    LinkList p=L->next;
   // printf("%d\n",L->next->data );
    while(p)
    {
        visit(p->data);
        p=p->next;
    }
  	printf("\n");
    return OK;
}
Status ListDelete(LinkList *L, int pos,ElemType *e)
{
	int j = 1;
	if(pos<1)
	{
		puts("位置错位");
		exit(0);
	}
	LinkList p,q;
	p = (*L)->next;
	while(p && j<pos)
	{
		j++;
		p = p->next;
	}
	if(!(p->next) || j>pos)
	{

		return ERROR;
	}
	q = p->next;
	p->next = q->next;
	*e = q->data;
	free(q);
	return OK;
}
int main(int argc, char const *argv[])
{
	LinkList Link;
	InitList(&Link);
	ListInsert(&Link, 1,10);
	ListInsert(&Link, 2,20);
	ListInsert(&Link, 3,30);
	ListInsert(&Link, 4,40);
	int e;
	ListDelete(&Link,2,&e);
	ListTraverse(Link);
	//printf("%d\n",ListTraverse(Link) );
	return 0;
}
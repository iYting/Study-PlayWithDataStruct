#include <stdio.h>


/**
 * 线性表顺序存储
 */

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXSIZE 10

typedef int Status;
typedef int ElemType;

typedef struct
{
	ElemType data[MAXSIZE];
	int length;
}SqList;

//初始化线性表
Status InitList(SqList * L);
//插入
Status ListInsert(SqList * L, int pos, ElemType e);
//删除
Status ListDelete(SqList * L, int pos, ElemType *e);

Status GetElem(SqList * L, int pos, ElemType *e);
void   ShowList(SqList *L);
Status ClearList(SqList *L);
Status ListEmpty(SqList *L);
Status ListLength(SqList *L);
int main(int argc, char const *argv[])
{
	SqList L;
	InitList(&L);
	ListInsert(&L,1,10);
	ListInsert(&L,2,20);
	ListInsert(&L,3,30);
	ListInsert(&L,4,40);
	ShowList(&L);
	puts("-------");
	int num;
	ListDelete(&L,1, &num);

	ShowList(&L);
	return 0;
}
Status InitList(SqList * L)
{
	L->length = 0;
	return OK;
}
Status GetElem(SqList * L, int pos, ElemType *e)
{

	if (L->length==0 || pos<1 ||pos > L->length)
	{
		return ERROR;
	}
	*e = L->data[pos-1];
	return OK;
}
Status ListInsert(SqList * L, int pos, ElemType e)
{

	if(L->length==MAXSIZE)
	{
		puts("线性表已满");
		return  ERROR;
	}
	if(i<1 || i>L->length+1)
	{
		return ERROR;
	}
	if( i<=L->length )
	{
		for (int pos = L->length-1; pos >= i-1; --pos)
		{
			L->data[pos+1] = L->data[pos];
		}
	}
	L->data[i-1] = e;
	L->length++;
	return OK;
}
Status ListDelete(SqList * L, int pos, ElemType *e)
{
	if(L->length<1 || pos<1)
	{
		return ERROR;
	}
	if(pos>L->length)
	{
		return ERROR;
	}
	*e = L->data[pos-1];
	if(pos<L->length) //删除的不是最后一个元素
	{
		for (int i = pos-1; i < L->length; ++i)
		{
			L->data[i] = L->data[i+1];
		}
	}
	L->length--;
	return OK;
}
Status ClearList(SqList *L)
{
	L->length = 0;
	return OK;
}
Status ListLength(SqList *L){

	return L->length;
}
void ShowList(SqList * L)
{
	for (int i = 0; i <= L->length-1; ++i)
	{
		printf("%d\n",L->data[i] );
	}
}
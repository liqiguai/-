#include <stdio.h>
#include <stdlib.h>

struct slist//定义单链表结构体 
{
	double data;
	struct slist *next;
};

struct dlist//定义双链表结构体 
{
	struct dlist *front;
	double data;
	struct dlist *next;
};

struct slist *add_slist(struct slist *p, double data)//定义单链表增加结点的函数  
{
	p->next = (struct slist*)malloc(sizeof(struct slist));
	p->next->data = data;
	return p->next;
}

struct dlist *add_dlist(struct dlist *p, double data)//定义双链表增加结点的函数 
{
	p->next = (struct dlist*)malloc(sizeof(struct dlist));
	p->next->front = p;
	p->next->data = data;
	return p->next;
}

struct slist *c_slist(void)//创建单链表的函数，返回头指针 
{
	struct slist *head, *p;
	double num;
	p = head = (struct slist*)malloc(sizeof(struct slist));
	scanf("%lf",&num);
	while(num!=0)
	{
		p = add_slist(p,num);
		scanf("%lf",&num);
	}
	p->next = NULL;
	return head;
}

struct dlist *c_dlist(void)//创建双链表的函数，返回头指针 
{
	struct dlist *head, *p;
	double num;
	p = head = (struct dlist*)malloc(sizeof(struct dlist));
	scanf("%lf",&num);
	while(num!=0)
	{
		p = add_dlist(p,num);
		scanf("%lf",&num);
	}
	p->next = NULL;
	head->front = NULL;
	return head;
}

struct dlist *last(struct dlist *head)//返回双链表最后结点的指针 
{
	while(head->next!=NULL)
	head = head->next;
	return head;
}

void sprint(struct slist *p)//打印单链表数据 
{
	for(;p!=NULL;p=p->next)
	{
		printf("%f\n",p->data);
	}
}

void dprint(struct dlist *p)//打印双链表数据 
{
	for(;p!=NULL;p=p->next)
	{
		printf("%f\n",p->data);
	}
}

void redprint(struct dlist *p)//逆序打印双链表 
{
	for(;p->front!=NULL;p=p->front)
	{
		printf("%f\n",p->data);
	}
}

int main()
{
	struct slist *shead;
	struct dlist *dhead;
	printf("请输入单链表数据（输入0结束）：\n");
	shead = c_slist();
	printf("输出单链表：\n");
	sprint(shead->next);
	printf("请输入双链表数据（输入0结束）：\n");
	dhead = c_dlist();
	printf("输出双链表：\n");
	dprint(dhead->next);
	printf("逆序输出双链表：\n");
	redprint(last(dhead));
	return 0;
}

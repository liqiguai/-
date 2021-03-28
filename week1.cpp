#include <stdio.h>
#include <stdlib.h>

struct slist//���嵥����ṹ�� 
{
	double data;
	struct slist *next;
};

struct dlist//����˫����ṹ�� 
{
	struct dlist *front;
	double data;
	struct dlist *next;
};

struct slist *add_slist(struct slist *p, double data)//���嵥�������ӽ��ĺ���  
{
	p->next = (struct slist*)malloc(sizeof(struct slist));
	p->next->data = data;
	return p->next;
}

struct dlist *add_dlist(struct dlist *p, double data)//����˫�������ӽ��ĺ��� 
{
	p->next = (struct dlist*)malloc(sizeof(struct dlist));
	p->next->front = p;
	p->next->data = data;
	return p->next;
}

struct slist *c_slist(void)//����������ĺ���������ͷָ�� 
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

struct dlist *c_dlist(void)//����˫����ĺ���������ͷָ�� 
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

struct dlist *last(struct dlist *head)//����˫����������ָ�� 
{
	while(head->next!=NULL)
	head = head->next;
	return head;
}

void sprint(struct slist *p)//��ӡ���������� 
{
	for(;p!=NULL;p=p->next)
	{
		printf("%f\n",p->data);
	}
}

void dprint(struct dlist *p)//��ӡ˫�������� 
{
	for(;p!=NULL;p=p->next)
	{
		printf("%f\n",p->data);
	}
}

void redprint(struct dlist *p)//�����ӡ˫���� 
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
	printf("�����뵥�������ݣ�����0��������\n");
	shead = c_slist();
	printf("���������\n");
	sprint(shead->next);
	printf("������˫�������ݣ�����0��������\n");
	dhead = c_dlist();
	printf("���˫����\n");
	dprint(dhead->next);
	printf("�������˫����\n");
	redprint(last(dhead));
	return 0;
}

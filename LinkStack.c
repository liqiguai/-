#include "LinkStack.h"
#include<stdio.h>
#include<stdlib.h>

Status initLStack(LinkStack *s){
	(s)->count = -1;
	(s)->top = NULL;
}//��ʼ��ջ

Status isEmptyLStack(LinkStack *s){
	if(s->count==-1)return SUCCESS;
	else return ERROR;
}//�ж�ջ�Ƿ�Ϊ��

Status getTopLStack(LinkStack *s,ElemType *e){
	LinkStackPtr p = s->top;
	for(int i = 0;i < s->count;i++){
		p = p->next;
	}
	*e = p->data;
}//�õ�ջ��Ԫ��

Status clearLStack(LinkStack *s){
	s->count = -1;
}//���ջ
Status destroyLStack(LinkStack *s){
	LinkStackPtr p;
	while(s->top!=NULL){
		p = s->top;
		s->top = s->top->next;
		free(p);
	}
	s->count = -2;
}//����ջ

Status LStackLength(LinkStack *s,int *length){
	*length = s->count + 1;
}//���ջ����

Status pushLStack(LinkStack *s,ElemType data){
	LinkStackPtr *p = &s->top;
	for(int i = 0;i <= s->count;i++){
		p = &(*p)->next;
	}
	*p = (LinkStackPtr)malloc(sizeof(StackNode));
	(*p)->data = data;
	(*p)->next = NULL;
	s->count += 1;
}//��ջ

Status popLStack(LinkStack *s,ElemType *data){
	LinkStackPtr p = s->top;
	for(int i = 0;i < s->count;i++){
		p = p->next;
	}
	*data = p->data;
	free(p);
	s->count -= 1;
}//��ջ

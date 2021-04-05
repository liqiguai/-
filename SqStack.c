#include "SqStack.h"
#include<stdio.h>
#include<stdlib.h>

Status initStack(SqStack *s,int sizes){
	s->elem = (int *)malloc(sizeof(int)*sizes);
	s->size = sizes;
	s->top = -1;
}//��ʼ��ջ

Status isEmptyStack(SqStack *s){
	if(s->top==-1)return SUCCESS;
	else return ERROR;
}//�ж�ջ�Ƿ�Ϊ��

Status getTopStack(SqStack *s,ElemType *e){
	*e = *(s->elem + s->top);
}//�õ�ջ��Ԫ��

Status clearStack(SqStack *s){
	s->top = -1;
	printf("�ɹ�\n");
}//���ջ

Status destroyStack(SqStack *s){
	if(s->size == 0) 
	printf("δ��ʼ��\n");
	else{
		free(s->elem);
		s->elem = NULL;
		s->top = 0;
		s->size = 0;
		printf("�ɹ�\n");
	}
}//����ջ

Status stackLength(SqStack *s,int *length){
	*length = s->top + 1;
}//���ջ����

Status pushStack(SqStack *s,ElemType data){
	s->top += 1;
	*(s->elem + s->top) = data;
}//��ջ

Status popStack(SqStack *s,ElemType *data){
	*data = *(s->elem + s->top);
	s->top -= 1;
}//��ջ

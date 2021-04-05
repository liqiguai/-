#include "LinkStack.h"
#include<stdio.h>
#include<stdlib.h>

Status initLStack(LinkStack *s){
	(s)->count = -1;
	(s)->top = NULL;
}//初始化栈

Status isEmptyLStack(LinkStack *s){
	if(s->count==-1)return SUCCESS;
	else return ERROR;
}//判断栈是否为空

Status getTopLStack(LinkStack *s,ElemType *e){
	LinkStackPtr p = s->top;
	for(int i = 0;i < s->count;i++){
		p = p->next;
	}
	*e = p->data;
}//得到栈顶元素

Status clearLStack(LinkStack *s){
	s->count = -1;
}//清空栈
Status destroyLStack(LinkStack *s){
	LinkStackPtr p;
	while(s->top!=NULL){
		p = s->top;
		s->top = s->top->next;
		free(p);
	}
	s->count = -2;
}//销毁栈

Status LStackLength(LinkStack *s,int *length){
	*length = s->count + 1;
}//检测栈长度

Status pushLStack(LinkStack *s,ElemType data){
	LinkStackPtr *p = &s->top;
	for(int i = 0;i <= s->count;i++){
		p = &(*p)->next;
	}
	*p = (LinkStackPtr)malloc(sizeof(StackNode));
	(*p)->data = data;
	(*p)->next = NULL;
	s->count += 1;
}//入栈

Status popLStack(LinkStack *s,ElemType *data){
	LinkStackPtr p = s->top;
	for(int i = 0;i < s->count;i++){
		p = p->next;
	}
	*data = p->data;
	free(p);
	s->count -= 1;
}//出栈

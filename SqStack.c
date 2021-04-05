#include "SqStack.h"
#include<stdio.h>
#include<stdlib.h>

Status initStack(SqStack *s,int sizes){
	s->elem = (int *)malloc(sizeof(int)*sizes);
	s->size = sizes;
	s->top = -1;
}//初始化栈

Status isEmptyStack(SqStack *s){
	if(s->top==-1)return SUCCESS;
	else return ERROR;
}//判断栈是否为空

Status getTopStack(SqStack *s,ElemType *e){
	*e = *(s->elem + s->top);
}//得到栈顶元素

Status clearStack(SqStack *s){
	s->top = -1;
	printf("成功\n");
}//清空栈

Status destroyStack(SqStack *s){
	if(s->size == 0) 
	printf("未初始化\n");
	else{
		free(s->elem);
		s->elem = NULL;
		s->top = 0;
		s->size = 0;
		printf("成功\n");
	}
}//销毁栈

Status stackLength(SqStack *s,int *length){
	*length = s->top + 1;
}//检测栈长度

Status pushStack(SqStack *s,ElemType data){
	s->top += 1;
	*(s->elem + s->top) = data;
}//入栈

Status popStack(SqStack *s,ElemType *data){
	*data = *(s->elem + s->top);
	s->top -= 1;
}//出栈

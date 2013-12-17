#include "stack_lib.h"
#include <stdlib.h>
#include <string.h>

typedef struct 
{
	void** elements;
	int top;
	int length; 	
}Stack;

Stack* stack;
void* create(int length){
	stack=calloc(1,sizeof(Stack));
	stack->length=length;
	stack->top=-1;
	stack->elements=calloc(stack->length,sizeof(void*));
	return stack;
}

void dispose(){
	free(stack);
}

boolean IsStackFull(Stack *st){
	if((st->top+1) >= st->length)
		return true;
	else
		return false;
}

boolean push(void* st,void* elementToPush){
	Stack* stack = (Stack*)st;
	void* address;
	if(IsStackFull(stack)){
		stack->length *= 2;
		stack->elements = realloc(stack->elements, stack->length*sizeof(void*));		
	}
	stack->elements[++stack->top] = elementToPush;
	return true;
}

boolean IsEmpty(Stack* stack){
        return stack->top==-1;
}

void* pop(void* st){
	Stack* stack = (Stack*)st;
	if(IsEmpty(stack))
		return false;
	stack->top--;
	return stack->elements[stack->top + 1];
}

void* top(void* st){
	Stack* stack = (Stack*)st;
	return stack->elements[stack->top];
}
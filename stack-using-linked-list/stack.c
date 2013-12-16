#include "stack.h"

int push(Stack* start, int* data){
	insert(start, start->length, data);
	return 1;
}

void pop(Stack* start){
	remove(start, start->length-1);
}
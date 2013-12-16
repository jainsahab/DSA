#include "stack.h"
#include <stdlib.h>
int push(Stack* start, void* data){
	insert(start, start->length, data);
	return 1;
}

void pop(Stack* start){
	remove(start, start->length-1);
}

void* top(Stack* start){
	Node* head = start->head;
	while(head->next != NULL){
		head = head->next;
	}
	return head->data;
}
#include "priorityQueue.h"
#include <stdlib.h>
Head* create(){
	Head* st;
	st = calloc(1,sizeof(Head));
	st->length = 0;
	st->head=NULL;
	return st;
}

int enqueue(Head* start, Node* element){
	Node* temp = start->head;
	Node* temp2;
	int count=0;
			// printf("%d\n", element->priority);
	if(temp == NULL){
		start->head = element;
		start->length++;
		return 1;
	}
	while(element->priority > temp->priority ){
		++count;
		temp2 = temp;
		temp = temp->next;
		if(temp == NULL){
			temp2->next = element;
			start->length++;
			return 1;
		}

	}
	element->next = temp;
	if(count==0)
		start->head = element;
	else
		temp2->next = element;
	start->length++;
	return 1;
}

void dequeue(Head* start){
	Node* temp = start->head;
	start->head = temp->next;
	start->length--;
	return;
}

void dispose(Head* start){
	Node* temp = start->head;
	Node* t1 = temp ;
	int count = 0;
	while(t1 != NULL){
		if(count != 0)
			temp = t1;
		t1 = temp->next;
		if (temp != NULL)
			free(temp);
		count++;
	}
}
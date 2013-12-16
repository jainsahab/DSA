#include "doubleLL.h"
#include <stdlib.h>
#include <stdlib.h>

List* create(){
	List* start = calloc(1,sizeof(List));
	start->length=0;
	start->head=NULL;
	return start;
}

Node* createNode(void* prevAddress,void* nextAddress){
	Node* newNode =  calloc(1, sizeof(Node));
	newNode->next = nextAddress;
	newNode->previous = prevAddress;
	return newNode;
}

int insert(List *start, int index, void *data){
	Node *head=NULL,*prev=NULL,*next=NULL;
	int i;
	head = start->head;
    while(head!= NULL){
        prev = head;
        head = head->next;
    }
    head = prev;
	if(start->length==0){
		start->head = createNode(prev, next);;
		start->head->data=data;
		start->length++;	
		return 1;
	}
	if(start->length == index){
        head->next = createNode(prev, next);
        head->next->data = data;
        start->length++;
        return 1;
	}
	if(index >= 0 && index < start->length){
		next = prev->next;
		head->next = createNode(prev, next);
		head->data = data;
		start->length ++;
		return 1;
	}
	return 1;	
}

int remove(List *start, int index){
	Node *temp,*temp2;
	int count = 1;
	if(index >= start->length)
		return 0;
	if(index == 0){
		start->head = start->head->next;
		start->length--;
		return 1;
	}
	temp = start->head;
	while(count < index){
		temp = temp->next;
		count++;
	}
	temp2=temp->next;
	temp->next = temp->next->next;
	if(temp->next != NULL)
		temp->next->previous = temp;
	free(temp2);
	start->length--;
	return 1;
}

void dispose(List* start){
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

int isEmpty(List* start){
	if(start->head == NULL)
		return 1;
	return 0;
}
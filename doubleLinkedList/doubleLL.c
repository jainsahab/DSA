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
	Node *temp,*head;
	Node *prev,*next;
	int i;
	head = start->head;
	for (i = 0; i < index ; ++i){
        if(head->next != NULL)
            head = head->next;
    }
	if(start->length==0){
		temp = createNode(NULL, NULL);
		start->head=temp;
		temp->data=data;
		start->length++;	
		return 1;
	}
	if(start->length == index){
		temp = createNode(head, NULL);
        head->next = temp;
        head->data = data;
        start->length++;
        return 1;
	}
	if(index >= 0 && index < start->length){
		prev = head;
		for(i=0;i<index-1;i++){
			prev = prev->next;
		}
		next = prev->next;
		temp = createNode(prev, next);
		head->next = temp;
		head->data = data;
		start->length ++;
		return 1;
	}
	return 1;	
}

void remove(List *start, int index){
	Node *temp,*temp2;
	int count = 1;
	if(index == 0){
		start->head = start->head->next;
		start->length--;
		return;
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
}
#include "sLL_lib.h"
#include <stdlib.h>

List* create(){
	List* list;
	list = malloc(sizeof(List));
	return list;	
}

int insertion(List *list, int index, void *data){
	int location=0;
	Node* ptr;
	ptr->next = list->head;
	for(location = 0 ; location < index ; location++){
		ptr->next = ptr->next->next;
	}
	ptr->next =  (Node*)malloc(sizeof(Node));
	ptr->next->data = data;
	return 1;
}
#include "ArrayList.h"
#include <stdlib.h>
List create(int capacity){
	List list;
	list.base = malloc((capacity+1)*sizeof(void *));
	list.capacity = capacity;
	list.length = 0;
	return list;
}



void reallocateIfNeeded(List* list, int index){
	int targetCapacity;
	if(list->length >= list->capacity){
		targetCapacity = 2 * list->capacity;
		list->base = realloc(list->base, targetCapacity);
		list->capacity = targetCapacity;
	}
}

void slideElementToRightIfNeed(List* list, int index){
	int count;
	if(index < list->length){
		list->base[list->length+1] = NULL;
		for (count = list->length; count > index; --count)
		{
			list->base[count] = list->base[count-1];
		}
	}
}

int add(List* list, void* data){
	reallocateIfNeeded(list, list->length);
	list->base[list->length] = data;
	list->base[list->length+1] = NULL;
	list->length++;
	return 1;
}

int insert(List* list, int index, void* data){
	reallocateIfNeeded(list, index);
	slideElementToRightIfNeed(list, index);
	list->base[index] = data;
	list->length++;
	return 1;
}

void* get(List *list, int index){	
	return list->base[index];
}

int remove(List* list, int index){
	int count;
	if(index >= list->length)
		return 0;
	for(count  = index; count < list->length-1 ; count++)
		list->base[count] = list->base[count+1];
	
	list->base[list->length-1] = NULL;
	return 1;
}

int search(List *list, compare areEqual, void *elementToBeSearch){
	int count;
	for(count = 0 ; count < list->length ; count ++){
 		if(!areEqual(elementToBeSearch,list->base[count]))
			return count;
	}
	return -1;
}

void dispose(void* ptr){
	free(ptr);
}

int hasnext (Iterator* it){
	List* temp = (List*)it->list;
	if(temp->base[it->position+1] != NULL)
		return 1;
	return 0;
}

void* giveNextElement(Iterator* it){
	List* temp = (List*)it->list;
	return temp->base[++it->position];	
}

Iterator getIterator(List* list){
	Iterator it;
	it.position = -1;
	it.list = list;
	it.hasNext = hasnext;
	it.next = giveNextElement;
	return it;
}
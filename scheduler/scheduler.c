#include "scheduler.h"
#include <stdlib.h>
schedulerQueue* create(){
	schedulerQueue* sQ = malloc(sizeof(schedulerQueue));
	sQ->length=0;
	sQ->rear=-1;
	return sQ;
}

int insert(schedulerQueue *sq, Process *process){
	if(sq->length==0 && sq->rear==-1){
		sq->head = process;
		process->next = sq->head;
		sq->rear++;
		sq->length++;
		return 1;
	}
	if(sq->length > 0 && sq->rear > -1){
		void* next	;
		int count=0;
		Process* temp = sq->head;
		while(process->priority > temp->priority ){
			++count;
			temp = temp->next;
		}
		// next = temp;
		// temp = process;
		// process->next = next;
		process->next = temp->next;
		temp->next = process;
		if(count==0)
			sq->head = process;
		sq->rear++;
		sq->length++;
		return 1;
	}
	return 1;
}

int process(schedulerQueue* sQ){
	int count=0;
	Process* temp = sQ->head;
	while(count == 0 || sQ->length > 0){
		if(temp->next == sQ->head)
			count=1;
		if(temp->duration <= 0){
			temp=temp->next;
			sQ->length--;
			sQ->rear--;
		}
		temp->duration -= 5;
		temp = temp->next;
	}
	return 1;
}
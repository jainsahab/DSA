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
		Process* temp = sq->head;
		while(temp->next != sq->head){
			temp = temp->next;
		}
		temp->next = process;
		process->next = sq->head;
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
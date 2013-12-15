#include "scheduler.h"
#include <stdlib.h>
int insert(Scheduler* scheduler,processInfo* process,int priority){
	Node* node = calloc(1, sizeof(Node));
	node->data = process;
	node->priority = priority;
	node->next = NULL;
	enqueue(scheduler, node);
	return 1;
}


void executeProcess(Scheduler* scheduler){
	int count = 0;
	Node* temp;
	processInfo* currentProcess;
	temp = scheduler->head;
	while(count <= scheduler->length){
		if(temp == NULL)
			temp = scheduler->head;
		currentProcess = temp->data;
		if(currentProcess->duration <= 0)
			count++;
		currentProcess->duration-=5;
		temp = temp->next;
	}
}
#include "testUtils.h"
#include "scheduler.h"
#include <stdlib.h>
#include <string.h>

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

Scheduler* scheduler;
processInfo *process1,*process2,*process3;
void setup(){
	scheduler = create();
	process1 = calloc(1, sizeof(processInfo));
	process2 = calloc(1, sizeof(processInfo));
	process3 = calloc(1, sizeof(processInfo));
}

void tearDown(){
	free(scheduler);
}

void assertIt(processInfo** expected,Head* start){
	int count=0;
	Node* node = start->head;
	while(node != NULL){
		ASSERT(expected[count] == node->data);
		node = node->next;
		count++;
	}
}


void assertToKnowAboutExecution(Scheduler* scheduler){
	Node* temp;
	processInfo* p1;
	temp = scheduler->head;
	p1 = temp->data;
	ASSERT((p1->duration <= 0));
	temp = temp->next;
	while(temp != NULL){
		p1 = temp->data;
		ASSERT((p1->duration <= 0));
		temp = temp->next;
	}
}

void assignProcess(processInfo* process,int duration, char* name){
	strcpy(process->processName,name);
	process->duration = duration;
}

void test_to_create_head_for_process_queue(){
	ASSERT(scheduler->head == NULL);
	ASSERT(scheduler->length == 0);
}

void test_to_insert_a_process_in_scheduler(){
	strcpy(process1->processName,"Chrome");
	process1->duration = 20;
	insert(scheduler,process1, 3);
	ASSERT(process1 == scheduler->head->data);
	executeProcess(scheduler);
}

void test_to_insert_process_of_higher_priority_than_previous_one(){
	processInfo* expected2[]={process2,process1};
	assignProcess(process1,20,"Chrome");
	insert(scheduler,process1, 3);
	ASSERT(process1 == scheduler->head->data);
	assignProcess(process2,15,"Turbo C");
	insert(scheduler,process2, 1);
	assertIt(expected2, scheduler);
	executeProcess(scheduler);
	assertToKnowAboutExecution(scheduler);
}

void test_to_insert_process_with_worst_case(){
	int count=0;
	Node* temp;
	processInfo* p1;
	processInfo* expected2[]={process2,process1};
	processInfo* expected3[]={process3,process2,process1};
	assignProcess(process1,20,"Chrome");
	insert(scheduler,process1, 3);
	ASSERT(process1 == scheduler->head->data);
	assignProcess(process2,15,"Turbo C");
	insert(scheduler,process2, 2);
	assertIt(expected2, scheduler);
	assignProcess(process3,10,"keyboard");
	process3->duration = 10;
	insert(scheduler,process3, 1);
	assertIt(expected3, scheduler);
	executeProcess(scheduler);
	assertToKnowAboutExecution(scheduler);
}


#include "testUtils.h"
#include "priorityQueue.h"
#include <stdlib.h>
//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed
Head* start;
Node* elements0;
Node* elements1;
Node* elements2;
Node* elements3;



void setup(){
	start = create();
	elements0 = malloc(sizeof(Node)*1);
	elements1 = malloc(sizeof(Node)*1);
	elements2 = malloc(sizeof(Node)*1);
	elements3 = malloc(sizeof(Node)*1);

}

void tearDown(){
	dispose(start);
}

void assertIt(int* expected,int length ,Head* start){
	int count=0;
	Node* node = start->head;
	ASSERT(length == start->length);
	while(node != NULL){
		ASSERT(expected[count] == *(int*)(node->data));
		node = node->next;
		count++;
	}
}

void test_to_create_queue(){
	ASSERT(0==start->length);
	ASSERT(NULL==start->head);
}

void test_to_enqueue_an_element(){
	int expected[]={1};
	int* arr = malloc(3*sizeof(int));
	Node* element = calloc(1, sizeof(Node));
	element[0].data = arr; element[0].priority = 1; element[0].next=NULL;
	arr[0]=1;
	ASSERT(enqueue(start, element));
	assertIt(expected, 1, start);
}

void test_to_enqueue_two_elements(){
	int* arr = calloc(3,sizeof(int));
	int expected[] = {2,1};
	elements0[0].data = arr; elements0[0].priority = 2; elements0[0].next=NULL;
	elements1[0].data = arr+1; elements1[0].priority = 1; elements1[0].next=NULL;
	arr[0]=1;
	arr[1]=2;
	ASSERT(enqueue(start, elements0));
	ASSERT(enqueue(start, elements1));
	assertIt(expected,2, start);
}



void test_to_enqueue_three_elements_with_complex_priority(){
	int* arr = malloc(3*sizeof(int));
	int expected[]={2,3,1};
	elements0[0].data = arr;elements0[0].priority = 5;elements0[0].next = NULL;
	elements1[0].data = arr+1;elements1[0].priority = 2;elements1[0].next = NULL;
	elements2[0].data = arr+2;elements2[0].priority = 3;elements2[0].next = NULL;
	arr[0]=1;
	arr[1]=2;
	arr[2]=3;
	ASSERT(enqueue(start, elements0));
	ASSERT(enqueue(start, elements1));
	ASSERT(enqueue(start, elements2));
	assertIt(expected,3,start);
}


void test_to_dequeue_an_element(){
	int* arr = malloc(3*sizeof(int));
	int expected[]={1};
	Node element = {arr,1,NULL};
	arr[0]=1;
	enqueue(start, &element);
	assertIt(expected, 1, start);
	ASSERT(&element == dequeue(start));
	assertIt(NULL, 0, start);
}


void test_to_dequeue_one_element_from_two_elements(){
	int* arr = malloc(3*sizeof(int));
	int beforeDequeue[]={2,1};
	int afterDequeue[]={1};
	elements0[0].data = arr; elements0[0].priority = 2; elements0[0].next=NULL;
	elements1[0].data = arr+1; elements1[0].priority = 1; elements1[0].next=NULL;
	arr[0]=1;
	arr[1]=2;
	ASSERT(enqueue(start, elements0));
	ASSERT(enqueue(start, elements1));
	assertIt(beforeDequeue, 2, start);
	ASSERT(elements1 == dequeue(start));
	assertIt(afterDequeue, 1, start);	
}
void test_to_enqueue_two_elements_at_end(){
	int* arr = malloc(3*sizeof(int));
	int expected[]={1,2};
	elements0[0].data = arr; elements0[0].priority = 1; elements0[0].next=NULL;
	elements1[0].data = arr+1; elements1[0].priority = 2; elements1[0].next=NULL;
	arr[0]=1;
	arr[1]=2;
	ASSERT(enqueue(start, elements0));
	ASSERT(enqueue(start, elements1));
	assertIt(expected, 2, start);
}


void test_to_enqueue_elements_in_between_of_queue(){
	int* arr = malloc(5*sizeof(int));
	int expected[]={2,4,3,1};
	elements0[0].data = arr;elements0[0].priority = 5;elements0[0].next = NULL;
	elements1[0].data = arr+1;elements1[0].priority = 1;elements1[0].next = NULL;
	elements2[0].data = arr+2;elements2[0].priority = 3;elements2[0].next = NULL;
	elements3[0].data = arr+3;elements3[0].priority = 2;elements3[0].next = NULL;
	arr[0]=1; arr[1]=2; arr[2]=3;arr[3]=4;arr[4]=5;
	ASSERT(enqueue(start, elements0));
	ASSERT(enqueue(start, elements1));
	ASSERT(enqueue(start, elements2));
	ASSERT(enqueue(start, elements3));
	assertIt(expected, 4, start);
}
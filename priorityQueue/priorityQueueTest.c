#include "testUtils.h"
#include "priorityQueue.h"
#include <stdlib.h>
//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed


void test_to_create_queue(){
	Head* start;
	start = create();
	ASSERT(0==start->length);
	ASSERT(NULL==start->head);
}

void test_to_enqueue_an_element(){
	Head* start;
	int* arr = malloc(3*sizeof(int));
	Node element = {arr,1,NULL};
	arr[0]=1;
	start = create();
	enqueue(start, &element);
	ASSERT(1==start->length);
	ASSERT(1==*(int*)(start->head->data));
}

void test_to_enqueue_two_elements(){
	Head* start;
	int* arr = malloc(3*sizeof(int));
	Node element = {arr,2,NULL};
	Node element2 = {arr+1,1,NULL};
	arr[0]=1;
	arr[1]=2;
	start = create();
	enqueue(start, &element);
	enqueue(start, &element2);
	ASSERT(2==start->length);
	ASSERT(2==*(int*)(start->head->data));
	ASSERT(1==*(int*)(start->head->next->data));
}



void test_to_enqueue_three_elements_with_complex_priority(){
	Head* start;
	int* arr = malloc(3*sizeof(int));
	Node* elements = malloc(sizeof(Node)*3);
	elements[0].data = arr;elements[0].priority = 5;elements[0].next = NULL;
	elements[1].data = arr+1;elements[1].priority = 2;elements[1].next = NULL;
	elements[2].data = arr+2;elements[2].priority = 3;elements[2].next = NULL;
	arr[0]=1;
	arr[1]=2;
	arr[2]=3;
	start = create();
	enqueue(start, &elements[0]);
	enqueue(start, &elements[1]);
	enqueue(start, &elements[2]);
	ASSERT(3==start->length);
	ASSERT(2==*(int*)(start->head->data));
	ASSERT(3==*(int*)(start->head->next->data));
	ASSERT(1==*(int*)(start->head->next->next->data));
}


void test_to_dequeue_an_element(){
	Head* start;
	int* arr = malloc(3*sizeof(int));
	Node element = {arr,1,NULL};
	arr[0]=1;
	start = create();
	enqueue(start, &element);
	ASSERT(1==start->length);
	ASSERT(1==*(int*)(start->head->data));
	dequeue(start);
	ASSERT(NULL == start->head);
	ASSERT(0==start->length);
}


void test_to_dequeue_one_element_from_two_elements(){
	Head* start;
	int* arr = malloc(3*sizeof(int));
	Node element = {arr,2,NULL};
	Node element2 = {arr+1,1,NULL};
	arr[0]=1;
	arr[1]=2;
	start = create();
	enqueue(start, &element);
	enqueue(start, &element2);
	ASSERT(2==start->length);
	ASSERT(2==*(int*)(start->head->data));
	ASSERT(1==*(int*)(start->head->next->data));
	dequeue(start);
	ASSERT(start->length==1);
	ASSERT(1==*(int*)(start->head->data));
}
void test_to_enqueue_two_elements_at_end(){
	Head* start;
	int* arr = malloc(3*sizeof(int));
	Node element = {arr,1,NULL};
	Node element2 = {arr+1,2,NULL};
	arr[0]=1;
	arr[1]=2;
	start = create();
	enqueue(start, &element);
	enqueue(start, &element2);
	ASSERT(2==start->length);
	ASSERT(1==*(int*)(start->head->data));
	ASSERT(2==*(int*)(start->head->next->data));
}


void test_to_enqueue_many_elements_on_manish_wish(){
	Head* start;
	int* arr = malloc(5*sizeof(int));
	Node* elements = malloc(sizeof(Node)*4);
	elements[0].data = arr;elements[0].priority = 5;elements[0].next = NULL;
	elements[1].data = arr+1;elements[1].priority = 1;elements[1].next = NULL;
	elements[2].data = arr+2;elements[2].priority = 3;elements[2].next = NULL;
	elements[3].data = arr+3;elements[3].priority = 2;elements[3].next = NULL;
	arr[0]=1;
	arr[1]=2;
	arr[2]=3;
	arr[3]=4;
	arr[4]=5;
	start = create();
	enqueue(start, &elements[0]);
	enqueue(start, &elements[1]);
	enqueue(start, &elements[2]);
	enqueue(start, &elements[3]);
	ASSERT(2==*(int*)(start->head->data));
	ASSERT(4==*(int*)(start->head->next->data));
	ASSERT(3==*(int*)(start->head->next->next->data));
	ASSERT(1==*(int*)(start->head->next->next->next->data));
}
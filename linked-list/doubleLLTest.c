#include "testUtils.h"
#include "doubleLL.h"
#include <stdlib.h>
//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

List* start;

void setup(){
	start = create();
}

void tearDown(){
	dispose(start);
}

void test_1_to_create_list(){
	ASSERT(0==start->length);
}

void test_2_to_insert_an_element(){
	int data = 2;
	insert(start, 0, &data);
	ASSERT(NULL == start->head->next);
	ASSERT(1==start->length);
}

void test_3_to_insert_element_at_end_of_linked_list(){
	int data=2,data2 =3;
	insert(start, 0, &data);
	insert(start, 1, &data2);
	ASSERT(2==*(int*)(start->head->data));
	ASSERT(3==*(int*)(start->head->next->data));
	ASSERT(NULL == start->head->next->next);
	ASSERT(start->head == start->head->next->previous);
	ASSERT(2==start->length);
}

void test_4_to_insert_element_in_between(){
	int data=2,data2=3;
	insert(start, 0, &data);
	insert(start, 1, &data2);
	insert(start, 2, &data2);
	insert(start, 1, &data);
	ASSERT(4==start->length);
}

void test_5_to_delete_an_element_from_beginning(){
	int data=2,data2=3;
	insert(start, 0, &data);
	insert(start, 1, &data2);
	insert(start, 2, &data2);
	ASSERT(3==start->length);
	ASSERT(2==*(int*)(start->head->data));
	remove(start, 0);
	ASSERT(3==*(int*)(start->head->next->data));
	ASSERT(2==start->length);
}

void test_6_to_delete_an_element_in_between(){
	int data=2,data2=3;
	insert(start, 0, &data);
	insert(start, 1, &data2);
	insert(start, 2, &data);
	ASSERT(3==start->length);
	ASSERT(3==*(int*)(start->head->next->data));
	remove(start, 1);
	ASSERT(2==*(int*)(start->head->next->data));
	ASSERT(2==start->length);
}

void test_7_to_delete_an_element_from_last(){
	int data=2,data2=3;
	insert(start, 0, &data);
	insert(start, 1, &data2);
	insert(start, 2, &data2);
	ASSERT(3==start->length);
	remove(start, 2	);
	ASSERT(2==start->length);
}

void test_8_to_delete_an_element_of_more_index(){
	int data=2,data2=3;
	insert(start, 0, &data);
	insert(start, 1, &data2);
	insert(start, 2, &data2);
	ASSERT(3==start->length);
	ASSERT(0==remove(start, 3));
}

void test_9_to_know_whether_the_list_is_empty_or_not(){
	ASSERT(isEmpty(start));
}	
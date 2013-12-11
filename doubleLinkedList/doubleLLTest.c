#include "testUtils.h"
#include "doubleLL.h"
#include <stdlib.h>
//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed


void test_to_create_list(){
	List* start;
	start=create();
	ASSERT(0==start->length);
}

void test_to_insert_an_element(){
	List* start;
	int data = 2;
	start = create();
	ASSERT(1==insert(start, 0, &data));
	ASSERT(1==start->length);
}

void test_to_insert_element_at_end_of_linked_list(){
	List* start;
	int data=2,data2 =3;
	start = create();
	ASSERT(1==insert(start, 0, &data));
	ASSERT(1==insert(start, 1, &data2));
	ASSERT(2==start->length);
}

void test_to_insert_element_in_between(){
	List* start;
	int data=2,data2=3;
	start = create();
	ASSERT(1==insert(start, 0, &data));
	ASSERT(1==insert(start, 1, &data2));
	ASSERT(1==insert(start, 2, &data2));
	ASSERT(1==insert(start, 1, &data));
	ASSERT(4==start->length);
}
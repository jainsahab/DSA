#include "testUtils.h"
#include "stack_lib.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed
void* stack;


void tearDown(){
	dispose();
}



void test_to_push_1_into_Stack(){
	int value=1;
	stack=create(2);
	ASSERT(push(stack,&value));
}

void test_to_push_beyond_its_limit(){
	int arr[] = {1,2,3};
	stack=create(2);
	ASSERT(push(stack, arr));
	ASSERT(push(stack, &arr[1]));
	ASSERT(push(stack, &arr[2]));
}

void test_to_pop_from_an_empty_stack(){
	stack=create(2);
	ASSERT(false==pop(stack));
}

void test_to_push_and_pop_together(){
	int value = 2;
	stack=create(2);
	ASSERT(push(stack, &value));
	ASSERT(&value ==  pop(stack));
}

void test_to_find_top_element_of_stack(){
	int arr[] = {1,2,3};
	stack = create(2);
	push(stack, arr);
	ASSERT(arr == pop(stack));
	push(stack, &arr[1]);
	ASSERT(&arr[1] == pop(stack));
}

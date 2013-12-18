#include "testUtils.h"
#include "stack_lib.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

int areEqual(Stack* src, Stack* expected){
	int res = (src->stackinfo.elementSize == expected->stackinfo.elementSize) 
				&& (src->stackinfo.size == expected->stackinfo.size)
				&& (src->stackinfo.top == expected->stackinfo.top);
	if(!res)
		return res;
	res = memcmp(src->elements,expected->elements,src->stackinfo.size*src->stackinfo.elementSize);
	return 0==res;
}

void debugStack(Stack* st){
	printf("Top = %d\n",st->stackinfo.top);
	printf("Element Size= %d\n",st->stackinfo.elementSize);
	printf("Stack Length=%d\n",st->stackinfo.size);
	printf("Pointing to %p\n",st->elements);
}

void test_to_create_int_Stack(){
	int expArr[2]={0,0};
	Stack expected = {expArr,-1,sizeof(int),2};
	Stack* stack=create(sizeof(int), 2);
	ASSERT(areEqual(stack, &expected));
	free(stack->elements);
	free(stack);
}

void test_to_create_float_Stack(){
	float expArr[2]={0.0f,0.0f};
	Stack expected = {expArr,-1,sizeof(float),2};
	Stack* stack=create(sizeof(float), 2);
	ASSERT(areEqual(stack, &expected));
	free(stack->elements);
	free(stack);
}

void test_to_create_char_Stack(){
	char expArr[2]={0,0};
	Stack expected = {expArr,-1,sizeof(char),2};
	Stack* stack=create(sizeof(char), 2);
	ASSERT(areEqual(stack, &expected));
	free(stack->elements);
	free(stack);
}

void test_to_create_double_Stack(){
	double expArr[2]={0,0};
	Stack expected = {expArr,-1,sizeof(double),2};
	Stack* stack=create(sizeof(double), 2);
	ASSERT(areEqual(stack, &expected));
	free(stack->elements);
	free(stack);
}

void test_to_create_String_Stack(){
	String expArr[2]={0,0};
	Stack expected = {expArr,-1,sizeof(String),2};
	Stack* stack=create(sizeof(String), 2);
	ASSERT(areEqual(stack, &expected));
	free(stack->elements);
	free(stack);
}


void test_to_push_1_into_Stack(){
	Stack* stack=create(sizeof(int), 2);
	int value=1;
	boolean result=push(stack,&value);
	int* data=stack->elements;
	ASSERT(data[0]==1);
	free(stack->elements);
	free(stack);
}

void test_to_push_one_point_four_point_5_into_float_Stack(){
	Stack* stack=create(sizeof(float), 2);
	float value=1.4f;
	boolean result=push(stack,&value);
	float* data=stack->elements;
	ASSERT(data[0]==1.4f);
	free(stack->elements);
	free(stack);
}

void test_to_push_one_point_two_five_six_point_5_into_double_Stack(){
	Stack* stack=create(sizeof(double), 2);
	double value=1.256;
	boolean result=push(stack,&value);
	double* data=stack->elements;
	ASSERT(data[0]==1.256);
	free(stack->elements);
	free(stack);
}

void test_to_push_character_a_into_char_Stack(){
	Stack* stack=create(sizeof(char), 2);
	char value='a';
	boolean result=push(stack,&value);
	char* data=stack->elements;
	ASSERT(data[0]=='a');
	free(stack->elements);
	free(stack);
}

void test_to_push_a_String_into_String_Stack(){
	String value,value2;
	String* data;
	Stack* stack=create(sizeof(String), 2);
	strcpy(value,"Prateek");
	strcpy(value2,"Jain");
	push(stack,&value);
	push(stack, &value2);
	data=stack->elements;
	ASSERT(0==strcmp("Prateek",data[0]));
	ASSERT(0==strcmp("Jain", data[1]));
	free(stack->elements);
	free(stack);
}

void test_to_pop_an_element_from_an_int_array(){
	Stack* stack = create(sizeof(int), 5);
	int* data = (int*)stack->elements;
	data[0]=1;
	data[1]=2;
	data[2]=3;
	data[3]=4;
	data[4]=5;
	stack->stackinfo.top=4;
	ASSERT(5==*(int*)pop(stack));
	ASSERT(3==stack->stackinfo.top);
	free(stack->elements);
	free(stack->elements);
	free(stack);
}

void test_to_pop_an_element_from_an_float_array(){
	Stack* stack = create(sizeof(float), 5);
	float* data=stack->elements;
	data[0]=1.2f;
	data[1]=2.2f;
	data[2]=3.2f;
	data[3]=4.2f;
	data[4]=5.2f;
	stack->stackinfo.top=4;
	ASSERT(5.2f==*(float*)pop(stack));
	ASSERT(3==stack->stackinfo.top);
	free(stack->elements);
	free(stack);
}

void test_to_pop_an_element_from_an_char_array(){
	Stack* stack = create(sizeof(char), 5);
	char* data=stack->elements;
	data[0]='a';
	data[1]='b';
	data[2]='c';
	data[3]='d';
	data[4]='e';
	stack->stackinfo.top=4;
	ASSERT('e'==*(char*)pop(stack));
	ASSERT(3==stack->stackinfo.top);
	free(stack->elements);
	free(stack);
}


void test_to_pop_an_element_from_an_String_array(){
	Stack* stack = create(sizeof(String), 5);
	String* data=stack->elements;
	strcpy(data[0],"abc");
	strcpy(data[1],"def");
	strcpy(data[2],"ghi");
	strcpy(data[3],"jkl");
	strcpy(data[4],"mno");
	stack->stackinfo.top=4;
	ASSERT(0==strcmp("mno",*(String*)pop(stack)));
	ASSERT(3==stack->stackinfo.top);
	free(stack->elements);
	free(stack);
}


void test_to_pop_an_element_from_an_double_array(){
        Stack* stack = create(sizeof(double), 3);
		double data[]={1.0,2.0,3.0};        
        memcpy(stack->elements, data, sizeof(data));
		stack->stackinfo.top=2;
		ASSERT(3.0==*(double*)pop(stack));        
}

void test_to_pop_an_element_from_double_array(){
	double _4_nums[4] = {12.0,14.0,45.0,12.0};
    Stack* stack = create(sizeof(double),4);
    push(stack, &_4_nums[0]);
    push(stack, &_4_nums[1]);
    push(stack, &_4_nums[2]);
    push(stack, &_4_nums[3]);
	ASSERT(12.0==*(double*)pop(stack));        
}

void test_to_find_top_element_should_return_4(){
	int expected[4]={1,2,3,4};
	Stack* stack=create(sizeof(int), 4);
	push(stack, &expected[0]);
	push(stack, &expected[1]);
	push(stack, &expected[2]);
	push(stack, &expected[3]);
	ASSERT(4==*(int*)top(stack));
}

void test_to_find_top_element_should_return_one_point_four(){
	float expected[4]={1.4f,2.4f,3.4f,4.4f};
	Stack* stack=create(sizeof(float), 4);
	push(stack, &expected[0]);
	push(stack, &expected[1]);
	push(stack, &expected[2]);
	push(stack, &expected[3]);
	ASSERT(4.4f==*(float*)top(stack));
}

void test_to_find_top_element_should_return_d(){
	char expected[4]={'a','b','c','d'};
	Stack* stack=create(sizeof(char), 4);
	push(stack, &expected[0]);
	push(stack, &expected[1]);
	push(stack, &expected[2]);
	push(stack, &expected[3]);
	ASSERT('d'==*(char*)top(stack));
}

void test_to_find_top_element_should_return_one_point_four_five_six(){
	double expected[4]={1.456,2.456,3.456,4.456};
	Stack* stack=create(sizeof(double), 4);
	push(stack, &expected[0]);
	push(stack, &expected[1]);
	push(stack, &expected[2]);
	push(stack, &expected[3]);
	ASSERT(4.456==*(double*)top(stack));
}

void test_to_find_top_element_should_return_pallavi(){
	String expected[4]={"Prateek","Samiksha","Manali","Pallavi"};
	Stack* stack=create(sizeof(String), 4);
	push(stack, &expected[0]);
	push(stack, &expected[1]);
	push(stack, &expected[2]);
	push(stack, &expected[3]);
	ASSERT(0==strcmp("Pallavi",*(String*)top(stack)));
}

void test_to_push_element_beyond_its_size_in_int_stack(){
	Stack* stack=create(sizeof(int), 2);
	int value=1;
	push(stack,&value);
	push(stack, &value);
	ASSERT(2 == stack->stackinfo.size);
	push(stack, &value);
	ASSERT(4 == stack->stackinfo.size);
	free(stack->elements);
	free(stack);
}

void test_to_push_element_beyond_its_size_in_float_stack(){
	Stack* stack=create(sizeof(float), 2);
	float value=1.2f;
	push(stack,&value);
	push(stack, &value);
	ASSERT(2 == stack->stackinfo.size);
	push(stack, &value);
	ASSERT(4 == stack->stackinfo.size);
	free(stack->elements);
	free(stack);
}

void test_to_push_element_beyond_its_size_in_double_stack(){
	Stack* stack=create(sizeof(double), 2);
	double value=11.345;
	push(stack,&value);
	push(stack, &value);
	ASSERT(2 == stack->stackinfo.size);
	push(stack, &value);
	ASSERT(4 == stack->stackinfo.size);
	free(stack->elements);
	free(stack);
}

void test_to_push_element_beyond_its_size_in_char_stack(){
	Stack* stack=create(sizeof(char), 2);
	char value='A';
	push(stack,&value);
	push(stack, &value);
	ASSERT(2 == stack->stackinfo.size);
	push(stack, &value);
	ASSERT(4 == stack->stackinfo.size);
	free(stack->elements);
	free(stack);
}

void test_to_push_element_beyond_its_size_in_String_stack(){
	Stack* stack=create(sizeof(String), 2);
	String value="Prateek Jain";
	push(stack,&value);
	push(stack, &value);
	ASSERT(2 == stack->stackinfo.size);
	push(stack, &value);
	ASSERT(4 == stack->stackinfo.size);
	free(stack->elements);
	free(stack);
}
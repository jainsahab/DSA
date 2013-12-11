#include "testUtils.h"
#include "bSearchLib.h"
#include <stdlib.h>
#include <string.h>
//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed


int compareInt(void* key,void* element){
	return ( *(int*)key -  *(int*)element );
}

int compareFloat(void* key,void* element){
	return ( *(float*)key -  *(float*)element );
}

int compareDouble(void* key,void* element){
	return ( *(double*)key -  *(double*)element );
}

int compareString(void* key,void* element){
	return strcmp( *(String*)key, *(String*)element );
}

void test_to_search_3_in_the_array_of_1_2_3(){
	int threeInts[3]={1,2,3};
	int key=3;
	ASSERT(3==*(int*)binarySearch(&key, threeInts, sizeof(threeInts)/sizeof(threeInts[0]), sizeof(threeInts[0]), compareInt));
	ASSERT(&threeInts[2] == binarySearch(&key, threeInts, sizeof(threeInts)/sizeof(threeInts[0]), sizeof(threeInts[0]), compareInt));
}

void test_to_search_2_in_the_array_of_1_2(){
	int threeInts[3]={1,2};
	int key=1;
	ASSERT(1==*(int*)binarySearch(&key, threeInts, sizeof(threeInts)/sizeof(threeInts[0]), sizeof(threeInts[0]), compareInt));
	ASSERT(&threeInts[0] == binarySearch(&key, threeInts, sizeof(threeInts)/sizeof(threeInts[0]), sizeof(threeInts[0]), compareInt));
}

void test_to_search_5_in_the_array_of_1_2_3_4_5(){
	int fiveInts[]={1,2,3,4,5};
	int key=5;
	ASSERT(5==*(int*)binarySearch(&key, fiveInts, sizeof(fiveInts)/sizeof(fiveInts[0]), sizeof(fiveInts[0]), compareInt));
}

void test_to_search_1_in_the_array_of_1_2_3_4_5(){
	int fiveInts[]={1,2,3,4,5};
	int key=1;
	ASSERT(1==*(int*)binarySearch(&key, fiveInts, sizeof(fiveInts)/sizeof(fiveInts[0]), sizeof(fiveInts[0]), compareInt));
}

void test_to_search_3_in_the_array_of_1_2_3_4_5(){
	int fiveInts[]={1,2,3,4,5};
	int key=3;
	ASSERT(3==*(int*)binarySearch(&key, fiveInts, sizeof(fiveInts)/sizeof(fiveInts[0]), sizeof(fiveInts[0]), compareInt));
}

void test_to_find_value_which_is_not_present(){
	int fiveInts[]={1,2,3,4,5};
	int key=7;
	ASSERT(NULL==(int*)binarySearch(&key, fiveInts, sizeof(fiveInts)/sizeof(fiveInts[0]), sizeof(fiveInts[0]), compareInt));
}


void test_to_search_5point2_in_the_array_of_1_2_3_4_5_having_each_element_point_2(){
	float fiveFloats[]={1.2f,2.2f,3.2f,4.2f,5.2f};
	float key=5.2f;
	ASSERT(5.2f==*(float*)binarySearch(&key, fiveFloats, sizeof(fiveFloats)/sizeof(fiveFloats[0]), sizeof(fiveFloats[0]), compareFloat));
}

void test_to_search_1point2_in_the_array_of_1_2_3_4_5_having_each_element_point_2(){
	float fiveFloats[]={1.2f,2.2f,3.2f,4.2f,5.2f};
	float key=1.2f;
	ASSERT(1.2f==*(float*)binarySearch(&key, fiveFloats, sizeof(fiveFloats)/sizeof(fiveFloats[0]), sizeof(fiveFloats[0]), compareFloat));
}

void test_to_search_3point2_in_the_array_of_1_2_3_4_5_having_each_element_point_2(){
	float fiveFloats[]={1.2f,2.2f,3.2f,4.2f,5.2f};
	float key=3.2f;
	ASSERT(3.2f==*(float*)binarySearch(&key, fiveFloats, sizeof(fiveFloats)/sizeof(fiveFloats[0]), sizeof(fiveFloats[0]), compareFloat));
}

void test_to_search_in_float_element_which_is_not_present(){
	float fiveFloats[]={1.2f,2.2f,3.2f,4.2f,5.2f};
	float key=6.2f;
	ASSERT(NULL==(float*)binarySearch(&key, fiveFloats, sizeof(fiveFloats)/sizeof(fiveFloats[0]), sizeof(fiveFloats[0]), compareFloat));
}

void test_to_search_5point2_in_double_array_of_1_2_3_4_5_having_each_element_point_2(){
	double fiveDoubles[]={1.2,2.2,3.2,4.2,5.2};
	double key=5.2;
	ASSERT(5.2==*(double*)binarySearch(&key, fiveDoubles, sizeof(fiveDoubles)/sizeof(fiveDoubles[0]), sizeof(fiveDoubles[0]), compareDouble));
}

void test_to_search_1point2_in_double_array_of_1_2_3_4_5_having_each_element_point_2(){
	double fiveDoubles[]={1.2,2.2,3.2,4.2,5.2};
	double key=1.2;
	ASSERT(1.2==*(double*)binarySearch(&key, fiveDoubles, sizeof(fiveDoubles)/sizeof(fiveDoubles[0]), sizeof(fiveDoubles[0]), compareDouble));
}

void test_to_search_3point2_in_double_array_of_1_2_3_4_5_having_each_element_point_2(){
	double fiveDoubles[]={1.2,2.2,3.2,4.2,5.2};
	double key=3.2;
	ASSERT(3.2==*(double*)binarySearch(&key, fiveDoubles, sizeof(fiveDoubles)/sizeof(fiveDoubles[0]), sizeof(fiveDoubles[0]), compareDouble));
}

void test_to_search_element_in_double_array_which_is_not_present(){
	double fiveDoubles[]={1.2,2.2,3.2,4.2,5.2};
	double key=6.2;
	ASSERT(NULL==(double*)binarySearch(&key, fiveDoubles, sizeof(fiveDoubles)/sizeof(fiveDoubles[0]), sizeof(fiveDoubles[0]), compareDouble));
}

void test_to_search_a_in_the_array_of_a_b_c_d_e(){
	String fiveString[]={"a","b","c","d","e"};
	String key="a";
	ASSERT(!strcmp("a",*(String*)binarySearch(&key, fiveString, sizeof(fiveString)/sizeof(fiveString[0]), sizeof(fiveString[0]), compareString)));
}

void test_to_search_e_in_the_array_of_a_b_c_d_e(){
	String fiveString[]={"a","b","c","d","e"};
	String key="e";
	ASSERT(!strcmp("e",*(String*)binarySearch(&key, fiveString, sizeof(fiveString)/sizeof(fiveString[0]), sizeof(fiveString[0]), compareString)));
}

void test_to_search_c_in_the_array_of_a_b_c_d_e(){
	String fiveString[]={"a","b","c","d","e"};
	String key="c";
	ASSERT(!strcmp("c",*(String*)binarySearch(&key, fiveString, sizeof(fiveString)/sizeof(fiveString[0]), sizeof(fiveString[0]), compareString)));
}

void test_to_search_element_in_string_array_which_is_not_present(){
	String fiveString[]={"a","b","c","d","e"};
	String key="f";
	ASSERT(NULL==binarySearch(&key, fiveString, sizeof(fiveString)/sizeof(fiveString[0]), sizeof(fiveString[0]), compareString));
}
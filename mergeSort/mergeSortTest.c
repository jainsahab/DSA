#include "testUtils.h"
#include "mergeSort.h"

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

typedef struct {
	int  AccNo;
	char* name;
} Account;

int compareInt(void* prev, void* next){
	return *(int*)prev < *(int*)next;
}

int compareFloat (void* prev, void* next){
	return *(float*)prev <
	 *(float*)next;
}

int compareChar (void* prev, void* next){
	return *(char*)prev < *(char*)next;
}

int compareAccount (void* prev, void* next){
	Account* first = (Account*)prev;
	Account* second = (Account*)next;
	return first->AccNo < second->AccNo;
}


void test_Merge_int_array(){
	int count;
	int destination[] = {0,0};
	int left[]= {2};
	int right[]={1};
	merge(destination, left, right, 1, 1, sizeof(int), compareInt);
	for (count = 0; count < 2; ++count)
	{
		ASSERT(count+1 == destination[count]);
	}
}


void test_should_sort_int_data(){
	int count;
	int data[] = {4,3,2,1};
	mergeSort(&data,4,sizeof(int),compareInt);
	for(count=0 ; count < 4 ; count++){
		ASSERT(data[count]==count+1);
	}
}

void test_should_sort_int_data_for_odd_no_of_elements(){
	int count;
	int data[] = {5,4,3,2,1};
	mergeSort(&data,5,sizeof(int),compareInt);
	for(count=0 ; count < 5 ; count++){
		ASSERT(data[count]==count+1);
	}
}

void test_should_sort_float_data_for_int_no_of_elements(){
	int count;
	float data[] = {4.1f,3.1f,2.1f,1.1f};
	float expected[] = {1.1f,2.1f,3.1f,4.1f};
	mergeSort(&data,4,sizeof(float),compareFloat);
	for(count=0 ; count < 4 ; count++){
		ASSERT(data[count]==expected[count]);
	}
}

void test_to_sort_char_data(){
	char arr[] = {'e','d','c','b','a'};
	mergeSort(arr, 5, sizeof(char), compareChar );
	ASSERT(arr[0] == 'a');
	ASSERT(arr[1] == 'b');
	ASSERT(arr[2] == 'c');
	ASSERT(arr[3] == 'd');
	ASSERT(arr[4] == 'e');
}

void test_to_sort_Account_data(){
	Account arr[] = {{3,"Prayas"},{1,"Manish"},{2,"Shabrin"}};
	mergeSort(arr, 3, sizeof(Account), compareAccount );
	ASSERT(1 == arr[0].AccNo);
	ASSERT(2 == arr[1].AccNo);
	ASSERT(3 == arr[2].AccNo);
}


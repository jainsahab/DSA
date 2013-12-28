#include "testUtils.h"
#include "bubbleSort.h"

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed
typedef struct {
	int  AccNo;
	char* name;
} Account;

int compareInt (void* prev, void* next){
	return *(int*)prev > *(int*)next;
}

int compareFloat (void* prev, void* next){
	return *(float*)prev > *(float*)next;
}

int compareChar (void* prev, void* next){
	return *(char*)prev > *(char*)next;
}

int compareAccount (void* prev, void* next){
	Account* first = (Account*)prev;
	Account* second = (Account*)next;
	return first->AccNo > second->AccNo;
}


void test_to_sort_int_data(){
	int arr[] = {5,4,3,2,1};
	bubbleSort(arr, 5, sizeof(int), compareInt );
	ASSERT(arr[0] == 1);
	ASSERT(arr[1] == 2);
	ASSERT(arr[2] == 3);
	ASSERT(arr[3] == 4);
	ASSERT(arr[4] == 5);
}

void test_to_sort_float_data(){
	float arr[] = {5.1f,4.2f,3.3f,2.4f,1.5f};
	bubbleSort(arr, 5, sizeof(float), compareFloat );
	ASSERT(arr[0] == 1.5f);
	ASSERT(arr[1] == 2.4f);
	ASSERT(arr[2] == 3.3f);
	ASSERT(arr[3] == 4.2f);
	ASSERT(arr[4] == 5.1f);
}

void test_to_sort_char_data(){
	char arr[] = {'e','d','c','b','a'};
	bubbleSort(arr, 5, sizeof(char), compareChar );
	ASSERT(arr[0] == 'a');
	ASSERT(arr[1] == 'b');
	ASSERT(arr[2] == 'c');
	ASSERT(arr[3] == 'd');
	ASSERT(arr[4] == 'e');
}

void test_to_sort_Account_data(){
	Account arr[] = {{3,"Prayas"},{1,"Manish"},{2,"Shabrin"}};
	bubbleSort(arr, 3, sizeof(Account), compareAccount );
	ASSERT(1 == arr[0].AccNo);
	ASSERT(2 == arr[1].AccNo);
	ASSERT(3 == arr[2].AccNo);
}
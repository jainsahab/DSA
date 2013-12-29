#include "testUtils.h"
#include "mergeSort.h"

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

int compare(void* prev, void* next){
	return *(int*)prev < *(int*)next;
}


void test_Merge_int_array(){
	int count;
	int destination[] = {0,0};
	int left[]= {2};
	int right[]={1};
	merge(destination, left, right, 1, 1, sizeof(int), compare);
	for (count = 0; count < 2; ++count)
	{
		ASSERT(count+1 == destination[count]);
	}
}



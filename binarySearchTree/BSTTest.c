#include "testUtils.h"
#include "BST.h"
#include <stdlib.h>

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

int compareInt(void* prev, void* next){
	return *(int*)prev - *(int*)next;
}

int SUCCESS = 1;
int FAILURE = 0;

Tree tree;
void setup(){
	tree = create(compareInt);
}

void test_should_put_data_as_root_into_Tree(){
	int result;
	int arr[] = {1,2,3,4,5,6,7,8,9};
	result = insert(&tree,&arr[4]);	
	ASSERT(SUCCESS == result);

}

void test_should_put_data_on_the_left_side_of_root_Tree(){
	int result;
	int arr[] = {1,2,3,4,5,6,7,8,9};
	result = insert(&tree,&arr[4]);	
	ASSERT(SUCCESS == result);
	result = insert(&tree, &arr[2]);
	ASSERT(SUCCESS == result);
}

void test_should_put_data_on_the_left_sidsdfe_of_root_Tree(){
	int result;
	Children* children;
	int arr[] = {1,2,3,4,5,6,7,8,9};
	result = insert(&tree,&arr[4]);	
	ASSERT(SUCCESS == result);
	result = insert(&tree, &arr[2]);
	ASSERT(SUCCESS == result);
	result = insert(&tree, &arr[1]);
	ASSERT(SUCCESS == result);
	result = insert(&tree, &arr[3]);
	ASSERT(SUCCESS == result);
}
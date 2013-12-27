#include "testUtils.h"
#include "tree.h"
#include <stdlib.h>
//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed


int areNodesEqualInt(void* ID, void* data){
        return (*(int*)ID == *(int*)data);
}

Tree tree;
int SUCCESS = 1;
int FAILURE = 0;

void setup(){
	tree = createTree(areNodesEqualInt);
}

void test_to_insert_root(){
	int arr[] = {1,2,3,4,5,6,7,8,9,10};
	int result = insertNode(&tree, NULL, &arr[0]);
	ASSERT(SUCCESS == result);
}

void test_to_insert_nodes_under_root_node(){
	int arr[] = {1,2,3,4,5,6,7,8,9,10};
	int result ;
	int count = 1;
	Iterator it;
	result = insertNode(&tree, NULL, &arr[0]);
	ASSERT(SUCCESS == result);
	insertNode(&tree, &arr[0], &arr[1]);
	insertNode(&tree, &arr[0], &arr[2]);
	it = getChildData(&tree, &arr[0]);
	while(it.hasNext(&it)){
		ASSERT(arr[count] == *(int*)(it.next(&it)));
		count++;
	}
}

void test_to_insert_multiple_nodes_at_root_node(){
	int arr[] = {1,2,3,4,5,6,7,8,9,10};
	int result ;
	int count = 1;
	Iterator it;
	result = insertNode(&tree, NULL, &arr[0]);
	ASSERT(SUCCESS == result);
	insertNode(&tree, &arr[0], &arr[1]);
	insertNode(&tree, &arr[0], &arr[1]);
	insertNode(&tree, &arr[0], &arr[1]);
	it = getChildData(&tree, &arr[0]);
	while(it.hasNext(&it)){
		ASSERT(2 == *(int*)(it.next(&it)));
		count++;
	}
}

void test_to_insert_child_at_child_of_root(){
	int arr[] = {1,2,3,4,5,6,7,8,9,10};
	int result ;
	int count = 3;
	Iterator it;
	result = insertNode(&tree, NULL, &arr[0]);
	ASSERT(SUCCESS == result);
	insertNode(&tree, &arr[0], &arr[1]);
	insertNode(&tree, &arr[0], &arr[2]);
	insertNode(&tree, &arr[0], &arr[3]);
	result = insertNode(&tree, &arr[1], &arr[4]);	
	ASSERT(result == SUCCESS);
}
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
	int count = 2;
	Iterator it;
	result = insertNode(&tree, NULL, &arr[0]);
	ASSERT(SUCCESS == result);
	insertNode(&tree, &arr[0], &arr[1]);
	insertNode(&tree, &arr[0], &arr[2]);
	it = getChildData(&tree, &arr[0]);
	while(it.hasNext(&it)){
		ASSERT(arr[count] == *(int*)(it.next(&it)));
		count--;
	}
}

void test_to_insert_multiple_nodes_at_root_node(){
	int arr[] = {1,2,3,4,5,6,7,8,9,10};
	int result ;
	int count = 3;
	Iterator it;
	result = insertNode(&tree, NULL, &arr[0]);
	ASSERT(SUCCESS == result);
	insertNode(&tree, &arr[0], &arr[1]);
	insertNode(&tree, &arr[0], &arr[2]);
	insertNode(&tree, &arr[0], &arr[3]);
	it = getChildData(&tree, &arr[0]);
	while(it.hasNext(&it)){
		ASSERT(arr[count] == *(int*)(it.next(&it)));
		count--;
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
	it = getChildData(&tree, &arr[1]);
	while(it.hasNext(&it)){
		ASSERT(5 == *(int*)(it.next(&it)));
		count++;
	}
}

void test_to_insert_child_for_3rd_generations(){
	int arr[] = {1,2,3,4,5,6,7,8,9,10};
	int result ;
	int count = 3;
	Iterator it;
	result = insertNode(&tree, NULL, &arr[0]);
	ASSERT(SUCCESS == result);
	insertNode(&tree, &arr[0], &arr[1]);
	insertNode(&tree, &arr[1], &arr[2]);
	insertNode(&tree, &arr[2], &arr[3]);
	it = getChildData(&tree, &arr[2]);
	while(it.hasNext(&it)){
		ASSERT(4 == *(int*)(it.next(&it)));
		count++;
	}
}

void test_to_check_child_of_node_of_a_leaf_node(){
	int arr[] = {1,2,3,4,5,6,7,8,9,10};
	int result ;
	int count = 3;
	Iterator it;
	result = insertNode(&tree, NULL, &arr[0]);
	ASSERT(SUCCESS == result);
	insertNode(&tree, &arr[0], &arr[1]);
	insertNode(&tree, &arr[0], &arr[2]);
	insertNode(&tree, &arr[0], &arr[3]);
	it = getChildData(&tree, &arr[1]);
	ASSERT(0 == it.hasNext(&it));
	it = getChildData(&tree, &arr[2]);
	ASSERT(0 == it.hasNext(&it));
	it = getChildData(&tree, &arr[3]);
	ASSERT(0 == it.hasNext(&it));
}

void test_to_delete_node_under_root_node_from_one_node(){
	int arr[] = {1,2,3,4,5,6,7,8,9,10};
	int result ;
	int count = 1;
	Iterator it;
	result = insertNode(&tree, NULL, &arr[0]);
	ASSERT(SUCCESS == result);
	insertNode(&tree, &arr[0], &arr[1]);
	it = getChildData(&tree, &arr[0]);
	while(it.hasNext(&it)){
		ASSERT(arr[count] == *(int*)(it.next(&it)));
		count--;
	}
	result = deleteNode(&tree, &arr[1]);
	ASSERT(SUCCESS == result);
}

void test_to_delete_node_under_root_node_from_two_nodes(){
	int arr[] = {1,2,3,4,5,6,7,8,9,10};
	int result ;
	int count = 2;
	Iterator it;
	result = insertNode(&tree, NULL, &arr[0]);
	ASSERT(SUCCESS == result);
	insertNode(&tree, &arr[0], &arr[1]);
	insertNode(&tree, &arr[0], &arr[2]);
	it = getChildData(&tree, &arr[0]);
	while(it.hasNext(&it)){
		ASSERT(arr[count] == *(int*)(it.next(&it)));
		count--;
	}
	result = deleteNode(&tree, &arr[1]);
	ASSERT(SUCCESS == result);
}

void test_to_delete_node_under_root_node_from_three_nodes(){
	int arr[] = {1,2,3,4,5,6,7,8,9,10};
	int result ;
	int count = 3;
	Iterator it;
	result = insertNode(&tree, NULL, &arr[0]);
	ASSERT(SUCCESS == result);
	insertNode(&tree, &arr[0], &arr[1]);
	insertNode(&tree, &arr[0], &arr[2]);
	insertNode(&tree, &arr[0], &arr[3]);
	it = getChildData(&tree, &arr[0]);
	while(it.hasNext(&it)){
		ASSERT(arr[count] == *(int*)(it.next(&it)));
		count--;
	}
	result = deleteNode(&tree, &arr[1]);
	ASSERT(SUCCESS == result);
}

void test_to_delete_node_under_root_node_from_middle_of_three_nodes(){
	int arr[] = {1,2,3,4,5,6,7,8,9,10};
	int result ;
	int count = 3;
	Iterator it;
	result = insertNode(&tree, NULL, &arr[0]);
	ASSERT(SUCCESS == result);
	insertNode(&tree, &arr[0], &arr[1]);
	insertNode(&tree, &arr[0], &arr[2]);
	insertNode(&tree, &arr[0], &arr[3]);
	it = getChildData(&tree, &arr[0]);
	while(it.hasNext(&it)){
		ASSERT(arr[count] == *(int*)(it.next(&it)));
		count--;
	}
	result = deleteNode(&tree, &arr[2]);
	ASSERT(SUCCESS == result);
}

// void test_to_delete_node_under_root_node_which_does_not_exist(){
// 	int arr[] = {1,2,3,4,5,6,7,8,9,10};
// 	int result ;
// 	int count = 3;
// 	Iterator it;
// 	result = insertNode(&tree, NULL, &arr[0]);
// 	ASSERT(SUCCESS == result);
// 	insertNode(&tree, &arr[0], &arr[1]);
// 	insertNode(&tree, &arr[0], &arr[2]);
// 	insertNode(&tree, &arr[0], &arr[3]);
// 	it = getChildData(&tree, &arr[0]);
// 	while(it.hasNext(&it)){
// 		ASSERT(arr[count] == *(int*)(it.next(&it)));
// 		count--;
// 	}
// 	result = deleteNode(&tree, &arr[7]);
// 	ASSERT(SUCCESS == result);
// }
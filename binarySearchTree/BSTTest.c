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
	Children children;
	int arr[] = {1,2,3,4,5,6,7,8,9};
	result = insert(&tree,&arr[4]);	
	ASSERT(SUCCESS == result);
	children = getChildren(&tree,&arr[4],compareInt);
	ASSERT(children.left == NULL);
	ASSERT(children.right == NULL);

}

void test_should_put_data_on_the_left_side_of_root_Tree(){
	int result;
	Children children;
	int arr[] = {1,2,3,4,5,6,7,8,9};
	result = insert(&tree,&arr[4]);	
	ASSERT(SUCCESS == result);
	result = insert(&tree, &arr[2]);
	ASSERT(SUCCESS == result);
	children = getChildren(&tree,&arr[4],compareInt);
	ASSERT(children.left == &arr[2]);
	ASSERT(children.right == NULL);
}

void test_should_put_data_on_the_right_side_of_root_Tree(){
	int result;
	Children children;
	int arr[] = {1,2,3,4,5,6,7,8,9};
	result = insert(&tree,&arr[4]);	
	ASSERT(SUCCESS == result);
	result = insert(&tree, &arr[7]);
	ASSERT(SUCCESS == result);
	children = getChildren(&tree,&arr[4],compareInt);
	ASSERT(children.left == NULL);
	ASSERT(children.right == &arr[7]);
}

void test_should_not_put_data_as_it_is_previously_present(){
	int result;
	Children children;
	int arr[] = {1,2,3,4,5,6,7,8,9};
	result = insert(&tree,&arr[4]);	
	ASSERT(SUCCESS == result);
	result = insert(&tree, &arr[7]);
	ASSERT(SUCCESS == result);
	result = insert(&tree, &arr[7]);
	ASSERT(FAILURE == result);
}

void test_should_make_a_left_sub_tree(){
	int result;
	Children children;
	int arr[] = {1,2,3,4,5,6,7,8,9};
	result = insert(&tree,&arr[4]);	
	ASSERT(SUCCESS == result);
	result = insert(&tree, &arr[2]);
	ASSERT(SUCCESS == result);
	result = insert(&tree, &arr[1]);
	ASSERT(SUCCESS == result);
	result = insert(&tree, &arr[3]);
	ASSERT(SUCCESS == result);
	children = getChildren(&tree,&arr[2],compareInt);
	ASSERT(children.left == &arr[1]);
	ASSERT(children.right == &arr[3]);
}

void test_should_make_a_right_sub_tree(){
	int result;
	Children children;
	int arr[] = {1,2,3,4,5,6,7,8,9};
	result = insert(&tree,&arr[4]);	
	ASSERT(SUCCESS == result);
	result = insert(&tree, &arr[6]);
	ASSERT(SUCCESS == result);
	result = insert(&tree, &arr[5]);
	ASSERT(SUCCESS == result);
	result = insert(&tree, &arr[7]);
	ASSERT(SUCCESS == result);
	children = getChildren(&tree,&arr[6],compareInt);
	ASSERT(children.left == &arr[5]);
	ASSERT(children.right == &arr[7]);
}

void test_to_get_the_children_of_a_node(){
	int result;
	Children children;
	int arr[] = {1,2,3,4,5,6,7,8,9};
	insert(&tree,&arr[4]);	
	insert(&tree, &arr[2]);
	insert(&tree, &arr[1]);
	insert(&tree, &arr[3]);
	children = getChildren(&tree,&arr[2],compareInt);
	ASSERT(children.left == &arr[1]);
	ASSERT(children.right == &arr[3]);
}

void test_to_get_the_children_of_a_leaf_node(){
	int result;
	Children children;
	int arr[] = {1,2,3,4,5,6,7,8,9};
	insert(&tree,&arr[4]);	
	insert(&tree, &arr[2]);
	insert(&tree, &arr[1]);
	insert(&tree, &arr[3]);
	children = getChildren(&tree,&arr[1],compareInt);
	ASSERT(children.left == NULL);
	ASSERT(children.right == NULL);
}


void test_to_delete_a_leaf_node(){
	int result;
	Children children;
	int arr[] = {1,2,3,4,5,6,7,8,9};
	insert(&tree,&arr[4]);	
	insert(&tree, &arr[2]);
	remove(&tree, &arr[2]);
	children = getChildren(&tree,&arr[4],compareInt);
	ASSERT(children.left == NULL);
	ASSERT(children.right == NULL);
}

void test_to_delete_a_node_with_one_child_on_its_left(){
	int result;
	Children children;
	int arr[] = {1,2,3,4,5,6,7,8,9};
	insert(&tree,&arr[4]);	
	insert(&tree, &arr[2]);
	insert(&tree, &arr[1]);
	remove(&tree, &arr[2]);
	children = getChildren(&tree,&arr[4],compareInt);
	ASSERT(children.left == &arr[1]);
	ASSERT(children.right == NULL);
}

void test_to_delete_a_node_with_one_child_on_its_right(){
	int result;
	Children children;
	int arr[] = {1,2,3,4,5,6,7,8,9};
	insert(&tree, &arr[4]);	
	insert(&tree, &arr[2]);
	insert(&tree, &arr[3]);
	remove(&tree, &arr[2]);
	children = getChildren(&tree,&arr[4],compareInt);
	ASSERT(children.left == &arr[3]);
	ASSERT(children.right == NULL);
}

void test_to_delete_a_node_with_one_child_on_its_left_from_right_sub_tree_of_root(){
	int result;
	Children children;
	int arr[] = {1,2,3,4,5,6,7,8,9};
	insert(&tree, &arr[4]);	
	insert(&tree, &arr[6]);
	insert(&tree, &arr[5]);
	remove(&tree, &arr[6]);
	children = getChildren(&tree,&arr[4],compareInt);
	ASSERT(children.left == NULL);
	ASSERT(children.right == &arr[5]);
}

void test_to_delete_a_node_with_one_child_on_its_right_from_right_sub_tree_of_root(){
	int result;
	Children children;
	int arr[] = {1,2,3,4,5,6,7,8,9};
	insert(&tree, &arr[4]);	
	insert(&tree, &arr[6]);
	insert(&tree, &arr[7]);
	remove(&tree, &arr[6]);
	children = getChildren(&tree,&arr[4],compareInt);
	ASSERT(children.left == NULL);
	ASSERT(children.right == &arr[7]);
}

void test_to_delete_a_node_with_two_child(){
	int result;
	Children children;
	int arr[] = {1,2,3,4,5,6,7,8,9};
	insert(&tree, &arr[4]);	
	insert(&tree, &arr[2]);
	insert(&tree, &arr[1]);
	insert(&tree, &arr[3]);
	remove(&tree, &arr[2]);
	children = getChildren(&tree,&arr[5],compareInt);
	ASSERT(children.left == &arr[1]);
	ASSERT(children.right == NULL);
	children = getChildren(&tree,&arr[1],compareInt);
	ASSERT(children.left == NULL);
	ASSERT(children.right == &arr[3]);
}

void test_to_delete_a_node_with_two_child_with_a_bit_complex_tree(){
	int result;
	Children children;
	int arr[] = {1,2,3,4,5,6,7,8,9};
	insert(&tree, &arr[1]);	
	insert(&tree, &arr[0]);
	insert(&tree, &arr[3]);
	insert(&tree, &arr[2]);
	insert(&tree, &arr[5]);
	insert(&tree, &arr[4]);
	insert(&tree, &arr[8]);
	remove(&tree, &arr[3]);
	children = getChildren(&tree,&arr[1],compareInt);
	ASSERT(children.left == &arr[0]);
	ASSERT(children.right == &arr[4]);
	children = getChildren(&tree,&arr[5],compareInt);
	ASSERT(children.left == NULL);
	ASSERT(children.right == &arr[8]);
}
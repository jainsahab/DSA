#include "testUtils.h"
#include "BST.h"

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

int compareInt(void* prev, void* next){
	return *(int*)prev - *(int*)next;
}

Tree tree;
void setup(){
	tree = create(compareInt);
}


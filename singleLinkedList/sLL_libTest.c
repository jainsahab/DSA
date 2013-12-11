#include "testUtils.h"
#include "sLL_lib.h"

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

void test_fail(){
	ASSERT(0);
}

void test_to(){
	int element = 2;
	create();
	insertion(list, 0, &element);
}

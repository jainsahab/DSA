#include "testUtils.h"
#include "hashTable.h"

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed


void test_to_generate_hash_code_for_Armaan(){
	int expected = 5;
	ASSERT(expected ==hashCodeGenerator("Armaan"));
}
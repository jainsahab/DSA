#include "testUtils.h"
#include "hashTable.h"
#include <string.h>

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

int keyCompare(void* key1, void* key2){
	return 0 == strcmp((char*)key1 , (char*)key2);
}

int CodeGenerator(void *key,HashTable* hastable){
	int count = 0,result = 0;
	for(count = 0; count < strlen((char*)key) ; count++){
		result  += ((char*)key)[count];
	}
	return result % hastable->bucketsSize;
}

HashTable hashtable;
int SUCCESS = 1;
int FAILURE = 0;

void setup(){
	hashtable = createHashTable(10, keyCompare, CodeGenerator);
}

void test_to_put_a_record_in_hashtable(){
	char* key = "Apple";
	char* value = "Seb";
	int result = put(&hashtable, key, value);
	ASSERT(result == SUCCESS);
}

void test_to_get_a_record_from_hashtable(){
	void* answer;
	char* key = "Apple";
	char* value = "Seb";
	int result = put(&hashtable, key, value);
	ASSERT(result == SUCCESS);
	answer = getValue(&hashtable, key);
	ASSERT(0 == strcmp((char*)answer, (char*)value));
}

void test_to_get_a_record_from_hashtable_when_there_are_more_elements(){
	void* answer;
	char* key = "Apple";
	char* value = "Seb";
	char* key2 = "Mango";
	char* value2 = "Aam";
	int result = put(&hashtable, key, value);
	ASSERT(result == SUCCESS);
	result = put(&hashtable,key2,value2);
	ASSERT(result == SUCCESS);
	answer = getValue(&hashtable, key2);
	ASSERT(0 == strcmp((char*)answer, (char*)value2));
}

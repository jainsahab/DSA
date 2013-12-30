#include "testUtils.h"
#include "hashTable.h"
#include <string.h>
//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

int keyCompare(void* key1, void* key2){
	return (int*)key1 - (int*)key2;
}

int CodeGenerator(void *key,HashTable* hastable){
	int count = 0,result = 0;
	for(count = 0; count < strlen((char*)key) ; count++){
		result  += ((char*)key)[count];
	}
	return result % hastable->bucketsSize;
}

HashTable hashtable;
void setup(){
	hashtable = createHastTable(10, keyCompare, CodeGenerator);
}


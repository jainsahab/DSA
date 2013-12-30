#include "hashTable.h"
#include <stdlib.h>


HashTable createHashTable(int size, keyComparator keycmp, hashCodeGenerator hashCodegen){
	HashTable hashtable;
	hashtable.bucketsSize = size;
	hashtable.cmp  = keycmp;
	hashtable.codeGenerator = hashCodegen;
	hashtable.buckets = createList(size);
	return hashtable;
}
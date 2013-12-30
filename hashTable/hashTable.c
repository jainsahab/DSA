#include "hashTable.h"
#include <stdlib.h>

typedef struct {
	void* key;
	void* value;
}Record;


HashTable createHashTable(int size, keyComparator keycmp, hashCodeGenerator hashCodegen){
	int count;
	HashTable hashtable;
	hashtable.bucketsSize = size;
	hashtable.cmp  = keycmp;
	hashtable.codeGenerator = hashCodegen;
	hashtable.buckets = createList(size);
	for(count = 0 ; count < size ; count++){
		hashtable.buckets.base[count] = create();
	}
	return hashtable;
}

Record getRecord(void* key, void* value){
	Record record;
	record.key = key;
	record.value = value;
	return record;
}


int put(HashTable* hashtable,void* key, void* value){
	Record record;
	int bucketNo;
	record = getRecord(key,value);
	bucketNo = hashtable->codeGenerator(key,hashtable);
	insert((List*)(hashtable->buckets.base[bucketNo - 1]), 0, &record);
	return 1;
}

void* getValue(HashTable *hashtable, void *key){
	Iterator it;
	int bucketNo;
	Record* temp;
	bucketNo = hashtable->codeGenerator(key,hashtable);
	it = getIterator(((List*)(hashtable->buckets.base[bucketNo - 1])));
	while(it.hasNext(&it)){
		temp = it.next(&it);
		if(hashtable->cmp(temp->key,key))
			return temp->value;
	}
	return NULL;
}
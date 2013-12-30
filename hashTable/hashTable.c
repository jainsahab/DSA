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

Record* getRecord(void* key, void* value){
	Record* record = malloc(sizeof(Record));
	record->key = key;
	record->value = value;
	return record;
}


int put(HashTable* hashtable,void* key, void* value){
	Record *record;
	int bucketNo;
	record = getRecord(key,value);
	bucketNo = hashtable->codeGenerator(key,hashtable);
	insert((List*)(hashtable->buckets.base[bucketNo - 1]), 0, record);
	return 1;
}

void* getValue(HashTable *hashtable, void *key){
	Iterator it;
	int bucketNo,count;
	Node* temp;
	Record* elem;
	List* currentBucket;
	bucketNo = hashtable->codeGenerator(key,hashtable);
	currentBucket = ((List*)(hashtable->buckets.base[bucketNo - 1]));
	it = getIterator(currentBucket);
	while(it.hasNext(&it)){
		elem = it.next(&it);
		if(hashtable->cmp(elem->key,key))
			return elem->value;
	}
	return NULL;
}
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

Record* checkForExistence(List* currentBucket, HashTable* hashtable,void* key){
	Iterator it;
	Record* elem;
	it = getIterator(currentBucket);
	while(it.hasNext(&it)){
		elem = it.next(&it);
		if(hashtable->cmp(elem->key,key))
			return elem;
	}
	return NULL;
}

int put(HashTable* hashtable,void* key, void* value){
	Record *record;
	int bucketNo;
	Record* temp;
	List* currentBucket;
	record = getRecord(key,value);
	bucketNo = hashtable->codeGenerator(key,hashtable);
	currentBucket = (List*)(hashtable->buckets.base[bucketNo]);
	temp = checkForExistence(currentBucket,hashtable,key);
	if(temp == NULL)
		insert(currentBucket, 0, record);
	else
		temp->value = value;
	return 1;
}

void* getValue(HashTable *hashtable, void *key){
	Iterator it;
	int bucketNo;
	Record* elem;
	List* currentBucket;
	bucketNo = hashtable->codeGenerator(key,hashtable);
	currentBucket = ((List*)(hashtable->buckets.base[bucketNo]));
	it = getIterator(currentBucket);
	while(it.hasNext(&it)){
		elem = it.next(&it);
		if(hashtable->cmp(elem->key,key))
			return elem->value;
	}
	return NULL;
}

int deleteRecord(HashTable* hashtable, void* key){
	Iterator it;
	int bucketNo,index=0;
	Record* elem;
	List* currentBucket;
	bucketNo = hashtable->codeGenerator(key,hashtable);
	currentBucket = ((List*)(hashtable->buckets.base[bucketNo]));
	it = getIterator(currentBucket);
	while(it.hasNext(&it)){
		elem = it.next(&it);
		if(hashtable->cmp(elem->key,key))
			break;
		index++;
	}
	remove(currentBucket, index);
	return 1;
}
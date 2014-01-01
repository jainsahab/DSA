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
	hashtable.allKeys = create();
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
	if(currentBucket->length >= 2)
		return rehashing(hashtable, record);
	temp = checkForExistence(currentBucket,hashtable,key);
	if(temp == NULL){
		insert(currentBucket, 0, record);
		insert((List*)hashtable->allKeys, 0, record);
	}
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

void* returnKeys(Iterator* it){
	Record* record;
	Iterator first = getIterator(it->list);
	first.position = it->position;
	record = first.next(&first);
	it->position++;
	return record->key;
}

Iterator getAllKeys(HashTable* hashtable){
	Iterator it = getIterator((List*)hashtable->allKeys);
	it.next = returnKeys;
	return it;
}

void disposeAllLists(ArrayList* arrList){
	Iterator it = getIteratorOfArrayList(arrList);
	List* temp;
	while(it.hasNext(&it)){
		temp = (List*)(it.next(&it));
		dispose(temp);
	}
}

void initializeAllListsAgain(ArrayList* buckets, int length){
	int count;
	for(count = 0 ; count < length ; count++){
		buckets->base[count] = create();
	}
} 


int putAgain(HashTable* hashtable,void* key, void* value){
	Record *record;
	int bucketNo;
	Record* temp;
	List* currentBucket;
	record = getRecord(key,value);
	bucketNo = hashtable->codeGenerator(key,hashtable);
	currentBucket = (List*)(hashtable->buckets.base[bucketNo]);
	insert(currentBucket, 0, record);
	return 1;
}


int rehashing(HashTable* hashtable, void* record){
	Record* temp;
	Iterator it;
	int count;	
	List *list = hashtable->allKeys;
	disposeAllLists(&hashtable->buckets);
	hashtable->bucketsSize *= 2;
	hashtable->buckets.base = realloc(hashtable->buckets.base, hashtable->bucketsSize * sizeof(void*));
	initializeAllListsAgain(&hashtable->buckets, hashtable->bucketsSize);
	it = getIterator(list);
	while(it.hasNext(&it)){
		temp = it.next(&it);
		putAgain(hashtable, temp->key, temp->value);
	}
	putAgain(hashtable, ((Record*)record)->key, ((Record*)record)->value);
	return 1;
}
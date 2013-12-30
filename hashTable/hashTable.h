#include "../iterator.h"
#include "include/doubleLL.h"
#include "include/ArrayList.h"

typedef int (*keyComparator)(void* key1, void* key2);

typedef struct hash_table{
	ArrayList buckets;
	int bucketsSize;
	keyComparator cmp;
	int (*codeGenerator)(void *key,struct hash_table* hashtable);
}HashTable;

typedef int (*hashCodeGenerator)(void *key,HashTable* hashtable);

HashTable createHastTable(int size, keyComparator keycmp, hashCodeGenerator hashCodegen);
int put(HashTable* hashtable,void* key, void* value);

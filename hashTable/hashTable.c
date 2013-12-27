#include "hashTable.h"

int hashCodeGenerator(char *key){
	return key[0]%10;
}
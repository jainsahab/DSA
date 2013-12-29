#include "mergeSort.h"
#include <memory.h>
#include <stdlib.h>
int merge(void* destination, void* left, void* right, size_t leftLength, size_t rightLength,size_t elementSize, comparator cmp	){
	int  i=0,j=0,k=0;
	while(i < leftLength && j < rightLength){
		if(cmp(left+(i*elementSize), right+(j*elementSize))){
			memcpy(destination+(k*elementSize), left+(i*elementSize), elementSize);
			i++;
		}
		else{
			memcpy(destination+(k*elementSize), right+(j*elementSize), elementSize);
			j++;
		}
			k++;
	}
	while( j < rightLength){
		memcpy(destination+(k*elementSize), right+(j*elementSize), elementSize);
		j++;
		k++;
	}
	while(i < leftLength){
		memcpy(destination+(k*elementSize), left+(i*elementSize), elementSize);
		i++;
		k++;
	}
	return 1;
}


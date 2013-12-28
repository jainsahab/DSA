#include "bubbleSort.h"
#include <string.h>
#include <stdlib.h>

void bubbleSort(void* arr, size_t noOfElements, size_t elementsSize, compare cmp ){
	int limit,index;
	void *temp,*prev,*next;
	temp = calloc(1,elementsSize);
	for(limit = noOfElements - 2; limit >= 0; limit--){
		for (index = 0; index <= limit; ++index)
		{
			prev = arr+(index*elementsSize);
			next = arr+((index+1)*elementsSize);
			if(cmp(prev,next)){
				memcpy(temp, prev, elementsSize);
				memcpy(prev, next, elementsSize);
				memcpy(next, temp, elementsSize);
			}
		}
	}
}
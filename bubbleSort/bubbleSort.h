#include <stddef.h>
typedef int (*compare) (void* prev, void* next);

void bubbleSort(void* arr, size_t noOfElements, size_t elementsSize, compare cmp );
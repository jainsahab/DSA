#ifndef _Iterator_
#define _Iterator_

typedef struct itrt{
	int position;
	void* list;
	void* (*next)(struct itrt* itr);
	int (*hasNext)(struct itrt* itr);

} Iterator;

#endif
typedef int (*compare)(void* prev, void*next);

typedef struct{
	void* root;
	compare cmp;
} Tree;

Tree create(compare cmp);
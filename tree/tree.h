#include "doubleLL.h"


typedef struct {
	void* root;
	int (*compare)(void* ID, void * node);
} Tree;

Tree createTree();
int insertNode(Tree* tree, void* parentData, void* data);
int deleteNode(Tree* tree, void* data);
Iterator getChildData(Tree* tree, void* data);

#include "doubleLL.h"


typedef struct {
	void* root;
	int (*compare)(void* ID, void * node);
} Tree;

Tree createTree();
int insertNode(Tree* tree, void* parentData, void* data);
int deleteNode(Tree* tree, void* data);
int searchNode(Tree* tree, void* data);
void DisposeTree(List *list);
Iterator getChildren(Tree* tree, void* data);

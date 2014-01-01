#include "BST.h"
#include <stdlib.h>
Tree create(compare cmp){
	Tree tree;
	tree.root = NULL;
	tree.cmp = cmp;
	return tree;
}
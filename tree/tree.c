#include "tree.h"
#include <stdlib.h>
typedef struct treenode {
	struct treenode* parent;
	void* data;
	List* children;
} TreeNode;

Tree createTree(int (*compare)(void* ID, void* node)){
	Tree tree;
	tree.root = NULL;
	tree.compare = compare;
	return tree;
}


TreeNode* getNode(TreeNode* parentNode, void* data){
	TreeNode* treenode = calloc(1, sizeof(TreeNode));
	treenode->children = create();
	treenode->parent =  parentNode;
	treenode->data = data;
	return treenode;
}

TreeNode* Traverse(List *list, void* parentData,int (*compare)(void*,void*)){
	TreeNode* temp;
	Iterator it = getIterator(list);
	while(it.hasNext(&it)){
		temp = it.next(&it);
		if (0 == compare(temp,parentData)){
			return temp;
		}
		if(NULL != temp->children->head){
			return Traverse(temp->children, parentData, compare);
		}
	}
	return NULL;
}


int insertNode(Tree* tree, void* parentData, void* data){
	TreeNode* parent;
	TreeNode* treenode;
	if(parentData == NULL){
		treenode = getNode(parentData,data);
		tree->root = create();
		insert((List*)tree->root, ((List*)tree->root)->length, treenode);
		return 1;
	}
	parent = Traverse((List*)tree->root,parentData,tree->compare);
	if(parent == NULL)
		return 0;
	treenode = getNode(parent, data);
	insert(parent->children,((List*)tree->root)->length,treenode);
	return 1;
}

void* getChildrenData(Iterator* it){
	TreeNode* node;
	Iterator treeIt = getIterator(it->list);
	treeIt.position = it->position;
	node = treeIt.next(&treeIt);
	it->position++;
	return node->data;
}

Iterator getChildData(Tree* tree,  void* data){
	TreeNode* parentNode;
	Iterator it;
	parentNode = Traverse((List*)tree->root, data,tree->compare);
	it = getIterator(parentNode->children);
	it.next = getChildrenData;
	return it;
}
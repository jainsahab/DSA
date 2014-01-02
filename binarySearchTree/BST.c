#include "BST.h"
#include <stdlib.h>

typedef struct {
	void* left;
	void* right;
	void* data;
	void* parent;
} TreeNode;

Tree create(compare cmp){
	Tree tree;
	tree.root = NULL;
	tree.cmp = cmp;
	return tree;
}

void* getNode(TreeNode* treenode, void* data){
	TreeNode* temp =  calloc(1, sizeof(TreeNode));
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;
	temp->parent = NULL;
	return temp;
}

TreeNode* traverse(TreeNode* node, void* data, compare cmp){
	int result;
	TreeNode* temp = node;
	result = cmp(temp->data,data);
	if(result > 0 && temp->left != NULL)
		temp = temp->left;
	else if(result < 0 && temp->right != NULL)
		temp = temp->right;
	else
		return temp;
	return traverse(temp, data, cmp);
}	

int insert(Tree* tree, void* data){
	int result;
	TreeNode *treenode,*parentNode;
	treenode = getNode(treenode,data);
	if(tree->root == NULL){
		tree->root = treenode;
		return 1;
	}
	parentNode = traverse((TreeNode*)(tree->root),data,tree->cmp);
	result = tree->cmp(parentNode->data,data);
	if(result > 0)
		parentNode->left = treenode;
	else
		parentNode->right = treenode;
	parentNode = treenode;
	return 1;
}

Children* getChildren(Tree* tree,void* data,compare cmp){
	TreeNode* parentNode;
	Children* temp;
	parentNode = traverse(tree->root, data, cmp);
	temp->left = (parentNode->left == NULL) ? parentNode->left : ((TreeNode*)parentNode->left)->data;
	temp->right = (parentNode->right == NULL) ? parentNode->right : ((TreeNode*)parentNode->right)->data;
	return temp;
}
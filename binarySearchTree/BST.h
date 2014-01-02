typedef int (*compare)(void* prev, void*next);

typedef struct{
	void* root;
	compare cmp;
} Tree;

typedef struct {
	void* left;
	void* right;
} Children;

Tree create(compare cmp);
int insert(Tree* tree, void* data);
Children* getChildren(Tree* tree,void* data,compare cmp);
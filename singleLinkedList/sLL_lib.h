
typedef struct Struct_type{
	void* data;
	struct Struct_type *next;
} Node;

typedef struct {
	Node* head;
} List;

List* create();
int insertion(List*,int index,void* data);
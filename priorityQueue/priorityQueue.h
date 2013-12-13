typedef struct Struct_type{
	void* data;
	int priority;
	struct Struct_type *next;
} Node;

typedef struct {
	int length;
	Node* head;
} Head;

Head* create();
int enqueue(Head*, Node*);
void dequeue(Head*);
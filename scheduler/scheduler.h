typedef char String[260];
typedef struct p{
	String processName;
	int duration;
	int priority;
	struct p *next;
} Process;

typedef struct {
	Process *head;
	void *End;
	int length;
	int rear;
} schedulerQueue;

schedulerQueue* create();
int insert(schedulerQueue*, Process*);
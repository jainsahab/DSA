typedef char String[260];
typedef struct p{
	String processName;
	int duration;
	int priority;
	struct p *next;
} Process;

typedef struct {
	Process *head;
	int length;
	int rear;
} schedulerQueue;

schedulerQueue* create();
int insert(schedulerQueue*, Process*);
int process(schedulerQueue*);

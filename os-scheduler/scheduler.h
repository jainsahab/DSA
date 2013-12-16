#include "priorityQueue.h"
typedef Head Scheduler;
typedef char String [256];
typedef struct {
	String processName;
	int duration;
} processInfo;

int insert(Scheduler* scheduler,processInfo* process,int priority);
void executeProcess(Scheduler* scheduler);

typedef char String[256];
typedef int boolean;
#define true 1
#define false 0
void* create( int length);
boolean push(void* stack,void* InsertElement);
void* pop(void* stack);
void* top(void* stack);
void dispose();
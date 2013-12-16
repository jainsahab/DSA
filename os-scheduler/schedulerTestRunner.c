#include <stdio.h>

int testCount=-1;
int passCount=0;
void setup();
void tearDown();

void fixtureSetup();
void fixtureTearDown();
void incrementTestCount();
void incrementPassCount();
int currentTestFailed=0;

void testStarted(char* name){
	incrementTestCount();
	currentTestFailed=0;
	printf("\t%s\n",name);
}

void testEnded(){
	if(!currentTestFailed)
		incrementPassCount();
}

void resetTestCount(){
	testCount=0;
	passCount=0;
	printf("********* Starting tests\n\n");
}

void summarizeTestCount(){
	printf("\n********* Ran %d tests passed %d failed %d\n",testCount,passCount,testCount-passCount);
}

void incrementTestCount(){
	testCount++;
}

void incrementPassCount(){
	passCount++;
}

void testFailed(const char* fileName, int lineNumber, char* expression){
	currentTestFailed = 1;
	printf("\t\t %s : failed at %s:%d\n",expression, fileName,lineNumber);
}

int main(){
	fixtureSetup();
	resetTestCount();

	testStarted("test_to_create_head_for_process_queue");
	setup();
		test_to_create_head_for_process_queue();
	tearDown();
	testEnded();
	testStarted("test_to_insert_a_process_in_scheduler");
	setup();
		test_to_insert_a_process_in_scheduler();
	tearDown();
	testEnded();
	testStarted("test_to_insert_process_of_higher_priority_than_previous_one");
	setup();
		test_to_insert_process_of_higher_priority_than_previous_one();
	tearDown();
	testEnded();
	testStarted("test_to_insert_process_with_worst_case");
	setup();
		test_to_insert_process_with_worst_case();
	tearDown();
	testEnded();

	summarizeTestCount();
	fixtureTearDown();
	return 0;
}

void fixtureSetup(){}

void fixtureTearDown(){}

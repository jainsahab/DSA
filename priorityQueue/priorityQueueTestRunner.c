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

	testStarted("test_to_create_queue");
	setup();
		test_to_create_queue();
	tearDown();
	testEnded();
	testStarted("test_to_enqueue_an_element");
	setup();
		test_to_enqueue_an_element();
	tearDown();
	testEnded();
	testStarted("test_to_enqueue_two_elements");
	setup();
		test_to_enqueue_two_elements();
	tearDown();
	testEnded();
	testStarted("test_to_enqueue_three_elements_with_complex_priority");
	setup();
		test_to_enqueue_three_elements_with_complex_priority();
	tearDown();
	testEnded();
	testStarted("test_to_dequeue_an_element");
	setup();
		test_to_dequeue_an_element();
	tearDown();
	testEnded();
	testStarted("test_to_dequeue_one_element_from_two_elements");
	setup();
		test_to_dequeue_one_element_from_two_elements();
	tearDown();
	testEnded();
	testStarted("test_to_enqueue_two_elements_at_end");
	setup();
		test_to_enqueue_two_elements_at_end();
	tearDown();
	testEnded();
	testStarted("test_to_enqueue_many_elements_on_manish_wish");
	setup();
		test_to_enqueue_many_elements_on_manish_wish();
	tearDown();
	testEnded();

	summarizeTestCount();
	fixtureTearDown();
	return 0;
}

void setup(){}

void tearDown(){}

void fixtureSetup(){}

void fixtureTearDown(){}

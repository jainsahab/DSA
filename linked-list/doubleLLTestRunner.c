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

	testStarted("test_1_to_create_list");
	setup();
		test_1_to_create_list();
	tearDown();
	testEnded();
	testStarted("test_2_to_insert_an_element");
	setup();
		test_2_to_insert_an_element();
	tearDown();
	testEnded();
	testStarted("test_3_to_insert_element_at_end_of_linked_list");
	setup();
		test_3_to_insert_element_at_end_of_linked_list();
	tearDown();
	testEnded();
	testStarted("test_4_to_insert_element_in_between");
	setup();
		test_4_to_insert_element_in_between();
	tearDown();
	testEnded();
	testStarted("test_5_to_delete_an_element_from_beginning");
	setup();
		test_5_to_delete_an_element_from_beginning();
	tearDown();
	testEnded();
	testStarted("test_6_to_delete_an_element_in_between");
	setup();
		test_6_to_delete_an_element_in_between();
	tearDown();
	testEnded();
	testStarted("test_7_to_delete_an_element_from_last");
	setup();
		test_7_to_delete_an_element_from_last();
	tearDown();
	testEnded();
	testStarted("test_8_to_delete_an_element_which_is_no_longer_exist");
	setup();
		test_8_to_delete_an_element_which_is_no_longer_exist();
	tearDown();
	testEnded();
	testStarted("test_9_to_know_whether_the_list_is_empty_or_not");
	setup();
		test_9_to_know_whether_the_list_is_empty_or_not();
	tearDown();
	testEnded();

	summarizeTestCount();
	fixtureTearDown();
	return 0;
}

void fixtureSetup(){}

void fixtureTearDown(){}

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

	testStarted("test_1_insert_into_array_list");
	setup();
		test_1_insert_into_array_list();
	tearDown();
	testEnded();
	testStarted("test_2_insert_multiple_element");
	setup();
		test_2_insert_multiple_element();
	tearDown();
	testEnded();
	testStarted("test_3_insert_element_beyond_its_capacity");
	setup();
		test_3_insert_element_beyond_its_capacity();
	tearDown();
	testEnded();
	testStarted("test_4_insert_element_in_between");
	setup();
		test_4_insert_element_in_between();
	tearDown();
	testEnded();
	testStarted("test_5_remove_element_from_between");
	setup();
		test_5_remove_element_from_between();
	tearDown();
	testEnded();
	testStarted("test_6_remove_element_from_beginning");
	setup();
		test_6_remove_element_from_beginning();
	tearDown();
	testEnded();
	testStarted("test_7_remove_element_from_end");
	setup();
		test_7_remove_element_from_end();
	tearDown();
	testEnded();
	testStarted("test_8_to_search_into_arrayList");
	setup();
		test_8_to_search_into_arrayList();
	tearDown();
	testEnded();
	testStarted("test_9_insert_element_with_getiterator");
	setup();
		test_9_insert_element_with_getiterator();
	tearDown();
	testEnded();

	summarizeTestCount();
	fixtureTearDown();
	return 0;
}

void fixtureSetup(){}

void fixtureTearDown(){}

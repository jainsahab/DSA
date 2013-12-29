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

	testStarted("test_Merge_int_array");
	setup();
		test_Merge_int_array();
	tearDown();
	testEnded();
	testStarted("test_should_sort_int_data");
	setup();
		test_should_sort_int_data();
	tearDown();
	testEnded();
	testStarted("test_should_sort_int_data_for_odd_no_of_elements");
	setup();
		test_should_sort_int_data_for_odd_no_of_elements();
	tearDown();
	testEnded();
	testStarted("test_should_sort_float_data_for_int_no_of_elements");
	setup();
		test_should_sort_float_data_for_int_no_of_elements();
	tearDown();
	testEnded();
	testStarted("test_to_sort_char_data");
	setup();
		test_to_sort_char_data();
	tearDown();
	testEnded();
	testStarted("test_to_sort_Account_data");
	setup();
		test_to_sort_Account_data();
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

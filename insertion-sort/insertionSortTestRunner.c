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

	testStarted("test_should_arrange_data_in_order_by_Account_Number");
	setup();
		test_should_arrange_data_in_order_by_Account_Number();
	tearDown();
	testEnded();
	testStarted("test_should_arrange_data_in_order_by_Account_balance");
	setup();
		test_should_arrange_data_in_order_by_Account_balance();
	tearDown();
	testEnded();
	testStarted("test_should_arrange_data_in_order_by_Account_name");
	setup();
		test_should_arrange_data_in_order_by_Account_name();
	tearDown();
	testEnded();
	testStarted("test_should_arrange_int_data_in_order");
	setup();
		test_should_arrange_int_data_in_order();
	tearDown();
	testEnded();
	testStarted("test_should_arrange_double_data_in_order");
	setup();
		test_should_arrange_double_data_in_order();
	tearDown();
	testEnded();
	testStarted("test_should_arrange_float_data_in_order");
	setup();
		test_should_arrange_float_data_in_order();
	tearDown();
	testEnded();
	testStarted("test_should_arrange_char_data_in_order");
	setup();
		test_should_arrange_char_data_in_order();
	tearDown();
	testEnded();
	testStarted("test_should_arrange_string_data_in_order");
	setup();
		test_should_arrange_string_data_in_order();
	tearDown();
	testEnded();
	testStarted("test_2");
	setup();
		test_2();
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

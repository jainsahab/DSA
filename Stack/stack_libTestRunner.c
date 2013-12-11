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

	testStarted("test_to_create_int_Stack");
	setup();
		test_to_create_int_Stack();
	tearDown();
	testEnded();
	testStarted("test_to_create_float_Stack");
	setup();
		test_to_create_float_Stack();
	tearDown();
	testEnded();
	testStarted("test_to_create_char_Stack");
	setup();
		test_to_create_char_Stack();
	tearDown();
	testEnded();
	testStarted("test_to_create_double_Stack");
	setup();
		test_to_create_double_Stack();
	tearDown();
	testEnded();
	testStarted("test_to_create_String_Stack");
	setup();
		test_to_create_String_Stack();
	tearDown();
	testEnded();
	testStarted("test_to_push_1_into_Stack");
	setup();
		test_to_push_1_into_Stack();
	tearDown();
	testEnded();
	testStarted("test_to_push_one_point_four_point_5_into_float_Stack");
	setup();
		test_to_push_one_point_four_point_5_into_float_Stack();
	tearDown();
	testEnded();
	testStarted("test_to_push_one_point_two_five_six_point_5_into_double_Stack");
	setup();
		test_to_push_one_point_two_five_six_point_5_into_double_Stack();
	tearDown();
	testEnded();
	testStarted("test_to_push_character_a_into_char_Stack");
	setup();
		test_to_push_character_a_into_char_Stack();
	tearDown();
	testEnded();
	testStarted("test_to_push_a_String_into_String_Stack");
	setup();
		test_to_push_a_String_into_String_Stack();
	tearDown();
	testEnded();
	testStarted("test_to_pop_an_element_from_an_int_array");
	setup();
		test_to_pop_an_element_from_an_int_array();
	tearDown();
	testEnded();
	testStarted("test_to_pop_an_element_from_an_float_array");
	setup();
		test_to_pop_an_element_from_an_float_array();
	tearDown();
	testEnded();
	testStarted("test_to_pop_an_element_from_an_char_array");
	setup();
		test_to_pop_an_element_from_an_char_array();
	tearDown();
	testEnded();
	testStarted("test_to_pop_an_element_from_an_String_array");
	setup();
		test_to_pop_an_element_from_an_String_array();
	tearDown();
	testEnded();
	testStarted("test_to_pop_an_element_from_an_double_array");
	setup();
		test_to_pop_an_element_from_an_double_array();
	tearDown();
	testEnded();
	testStarted("test_to_pop_an_element_from_double_array");
	setup();
		test_to_pop_an_element_from_double_array();
	tearDown();
	testEnded();
	testStarted("test_to_find_top_element_should_return_4");
	setup();
		test_to_find_top_element_should_return_4();
	tearDown();
	testEnded();
	testStarted("test_to_find_top_element_should_return_one_point_four");
	setup();
		test_to_find_top_element_should_return_one_point_four();
	tearDown();
	testEnded();
	testStarted("test_to_find_top_element_should_return_d");
	setup();
		test_to_find_top_element_should_return_d();
	tearDown();
	testEnded();
	testStarted("test_to_find_top_element_should_return_one_point_four_five_six");
	setup();
		test_to_find_top_element_should_return_one_point_four_five_six();
	tearDown();
	testEnded();
	testStarted("test_to_find_top_element_should_return_pallavi");
	setup();
		test_to_find_top_element_should_return_pallavi();
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

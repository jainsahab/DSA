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

	testStarted("test_to_put_a_record_in_hashtable");
	setup();
		test_to_put_a_record_in_hashtable();
	tearDown();
	testEnded();
	testStarted("test_to_get_a_record_from_hashtable");
	setup();
		test_to_get_a_record_from_hashtable();
	tearDown();
	testEnded();
	testStarted("test_to_get_a_record_from_hashtable_when_there_are_more_elements");
	setup();
		test_to_get_a_record_from_hashtable_when_there_are_more_elements();
	tearDown();
	testEnded();
	testStarted("test_should_update_value_when_same_key_inserted_again");
	setup();
		test_should_update_value_when_same_key_inserted_again();
	tearDown();
	testEnded();
	testStarted("test_should_delete_a_record_from_hashtable");
	setup();
		test_should_delete_a_record_from_hashtable();
	tearDown();
	testEnded();
	testStarted("test_should_return_all_the_keys_from_hashTable");
	setup();
		test_should_return_all_the_keys_from_hashTable();
	tearDown();
	testEnded();

	summarizeTestCount();
	fixtureTearDown();
	return 0;
}

void tearDown(){}

void fixtureSetup(){}

void fixtureTearDown(){}

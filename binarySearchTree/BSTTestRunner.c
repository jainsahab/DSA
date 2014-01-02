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

	testStarted("test_should_put_data_as_root_into_Tree");
	setup();
		test_should_put_data_as_root_into_Tree();
	tearDown();
	testEnded();
	testStarted("test_should_put_data_on_the_left_side_of_root_Tree");
	setup();
		test_should_put_data_on_the_left_side_of_root_Tree();
	tearDown();
	testEnded();
	testStarted("test_should_put_data_on_the_right_side_of_root_Tree");
	setup();
		test_should_put_data_on_the_right_side_of_root_Tree();
	tearDown();
	testEnded();
	testStarted("test_should_make_a_left_sub_tree");
	setup();
		test_should_make_a_left_sub_tree();
	tearDown();
	testEnded();
	testStarted("test_should_make_a_right_sub_tree");
	setup();
		test_should_make_a_right_sub_tree();
	tearDown();
	testEnded();
	testStarted("test_to_get_the_children_of_a_node");
	setup();
		test_to_get_the_children_of_a_node();
	tearDown();
	testEnded();
	testStarted("test_to_get_the_children_of_a_leaf_node");
	setup();
		test_to_get_the_children_of_a_leaf_node();
	tearDown();
	testEnded();

	summarizeTestCount();
	fixtureTearDown();
	return 0;
}

void tearDown(){}

void fixtureSetup(){}

void fixtureTearDown(){}

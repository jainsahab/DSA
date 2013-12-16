#include "testUtils.h"
#include "insertionSort.h"

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed


int compareAccountsByAccountNumber(void* first, void* second) {
	Account* firstAccount = (Account*)first;
	Account* secondAccount = (Account*)second;
	return firstAccount->accountNumber - secondAccount->accountNumber;
}

int compareAccountsByBalance(void* first, void* second) {
	Account* firstAccount = (Account*)first;
	Account* secondAccount = (Account*)second;
	return firstAccount->balance - secondAccount->balance;
}

int compareAccountsByName(void* first, void* second) {
	Account* firstAccount = (Account*)first;
	Account* secondAccount = (Account*)second;
	return firstAccount->name - secondAccount->name;
}


int compareInt (void* first, void* second){
        return (*(int*)first - *(int*)second);
}

int compareFloat(void* first, void* second){
        return (*(float*)first - *(float*)second);
}

int compareDouble(void* first, void* second){
        return (*(double*)first - *(double*)second);
}

int compareChar(void* first, void* second){
        return (*(char*)first - *(char*)second);
}

int compareString(void* first, void* second){
        return strcmp((char*)first, (char*)second);
}


void test_should_arrange_data_in_order_by_Account_Number(){
	Account account[2] = {{"a",500,12.4},{"b",200,13.6}};;
	isort(account, 2, sizeof(Account), compareAccountsByAccountNumber);
	ASSERT(account[0].accountNumber==200);
	ASSERT(account[1].accountNumber==500);			
}

void test_should_arrange_data_in_order_by_Account_balance(){
	Account account[2] = {{"a",500,123.4},{"b",200,13.6}};;
	isort(account, 2, sizeof(Account), compareAccountsByAccountNumber);
	ASSERT(account[0].balance==13.6f);
	ASSERT(account[1].balance==123.4f);			
}

void test_should_arrange_data_in_order_by_Account_name(){
	Account account[2] = {{"b",500,123.4},{"a",200,13.6}};;
	isort(account, 2, sizeof(Account), compareAccountsByAccountNumber);
	ASSERT(strcmp(account[0].name,"a")==0);
	ASSERT(strcmp(account[1].name,"b")==0);		
}
 
void test_should_arrange_int_data_in_order(){
	int data[5] = {5,4,3,2,1};
    int expected[5] = {1,2,3,4,5};
    isort(data, 5, sizeof(int), compareInt);
    ASSERT(data[0]==1);
    ASSERT(data[4]==5);
}

void test_should_arrange_double_data_in_order(){
	double data[5] = {5.1,4.1,3.1,2.1,1.1};
    double expected[5] = {1.1,2.1,3.1,4.1,5.1};
    isort(data, 5, sizeof(double), compareDouble);
    ASSERT(data[0]==1.1);
    ASSERT(data[4]==5.1);
}

void test_should_arrange_float_data_in_order(){
	float data[5] = {200.0,100.0,400.0,300.0,500.0};
    isort(data, 5, sizeof(float), compareFloat);
    ASSERT(data[0]==100.0f);
    ASSERT(data[4]==500.0f);
}

void test_should_arrange_char_data_in_order(){
	char data[5] = {'e','d','c','b','a'};
    isort(data, 5, sizeof(char), compareChar);
    ASSERT(data[0]=='a');
    ASSERT(data[4]=='e');
}

void test_should_arrange_string_data_in_order(){
	string data[2] = {"manish","amit"};
	isort(data,2,sizeof(string),compareString);
	ASSERT(strcmp(data[0],"amit")==0);
	ASSERT(strcmp(data[1],"manish")==0);
}

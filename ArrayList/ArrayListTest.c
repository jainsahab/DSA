#include "testUtils.h"
#include "ArrayList.h"
#include <stdlib.h>
#include <string.h>
//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

typedef struct {
	int rollNo;
	char* name;
	int marks;
} sampleData;

sampleData first = {1,"Prateek",79};
sampleData second = {2,"Dubey",80};
sampleData third = {3,"Manish",90};

const int SUCCESS = 1;
const int FAILURE = 0;
ArrayList list;

void setup(){
	int noOfElements = 2;
	list = createList(noOfElements);
}

void tearDown(){
	disposeList(list.base);
}

void test_1_insert_into_array_list(){
	int result = insertIntoList(&list, 0, &first);
	sampleData* actual = (sampleData*)get(&list, 0);
	ASSERT(SUCCESS == result);
	ASSERT(actual->rollNo == first.rollNo);
}

void test_2_insert_multiple_element(){
	sampleData* actual ;
	insertIntoList(&list, 0, &first);
	insertIntoList(&list, 1, &second);
	actual = (sampleData*)get(&list, 0);
	ASSERT(actual->rollNo == first.rollNo);	
	actual = (sampleData*)get(&list, 1);
	ASSERT(actual->rollNo == second.rollNo);
}

void test_3_insert_element_beyond_its_capacity(){
	sampleData* actual ;
	insertIntoList(&list, 0, &first);
	insertIntoList(&list, 1, &second);
	insertIntoList(&list, 2, &third);
	actual = (sampleData*)get(&list, 0);
	ASSERT(actual->rollNo == first.rollNo);	
	actual = (sampleData*)get(&list, 1);
	ASSERT(actual->rollNo == second.rollNo);
}


void test_4_insert_element_in_between(){
	sampleData* actual ;
	addIntoList(&list,  &first);
	addIntoList(&list,  &second);
	insertIntoList(&list, 1, &third);
	actual = (sampleData*)get(&list, 0);
	ASSERT(actual->rollNo == first.rollNo);	
	actual = (sampleData*)get(&list, 1);
	ASSERT(actual->rollNo == third.rollNo);
	actual = (sampleData*)get(&list, 2);
	ASSERT(actual->rollNo == second.rollNo);
}

void test_5_remove_element_from_between(){
	sampleData* actual ;
	addIntoList(&list,  &first);
	addIntoList(&list,  &second);
	addIntoList(&list, &third);
	removeFromList(&list, 1);
	actual = (sampleData*)get(&list, 0);
	ASSERT(actual->rollNo == first.rollNo);	
	actual = (sampleData*)get(&list, 1);
	ASSERT(actual->rollNo == third.rollNo);
	actual = (sampleData*)get(&list, 2);
	ASSERT(actual == NULL);
}

void test_6_remove_element_from_beginning(){
	sampleData* actual ;
	addIntoList(&list,  &first);
	addIntoList(&list,  &second);
	addIntoList(&list, &third);
	removeFromList(&list, 0);
	actual = (sampleData*)get(&list, 0);
	ASSERT(actual->rollNo == second.rollNo);	
	actual = (sampleData*)get(&list, 1);
	ASSERT(actual->rollNo == third.rollNo);
	actual = (sampleData*)get(&list, 2);
	ASSERT(actual == NULL);
}

void test_7_remove_element_from_end(){
	sampleData* actual ;
	addIntoList(&list,  &first);
	addIntoList(&list,  &second);
	addIntoList(&list, &third);
	removeFromList(&list, 2);
	actual = (sampleData*)get(&list, 0);
	ASSERT(actual->rollNo == first.rollNo);	
	actual = (sampleData*)get(&list, 1);
	ASSERT(actual->rollNo == second.rollNo);
	actual = (sampleData*)get(&list, 2);
	ASSERT(actual == NULL);
}

int comparison (void *valueToBeSearch, void* element){
	return strcmp((char*)valueToBeSearch,((sampleData*)element)->name);
}

void test_8_to_search_into_arrayList(){
	sampleData* actual;
	int index ;
	int expected = 1;
	char* str = "Dubey";
	addIntoList(&list,  &first);
	addIntoList(&list,  &second);
	addIntoList(&list, &third);
	actual = (sampleData*)get(&list, 2);
	ASSERT(&third == actual);
	index = search(&list, comparison, str);
	ASSERT(index == expected);
}

void test_9_insert_element_with_getiterator(){
	sampleData* temp;
	int count =0;
	int expected[]={79 ,80, 90};
	Iterator it = getIteratorOfArrayList(&list);
	addIntoList(&list,  &first);
	addIntoList(&list,  &second);
	addIntoList(&list, &third);
	while(it.hasNext(&it)){
		temp = (sampleData*)it.next(&it);
		ASSERT(expected[count] == temp->marks);
		count++;
	}
}

void test_10_insert_element_at_negative_index(){
	sampleData* actual ;
	int result = insertIntoList(&list, -1, &first);
	ASSERT(result == FAILURE);
}

void test_11_to_check_empty_iterator(){
	sampleData* temp;
	Iterator it = getIteratorOfArrayList(&list);
	int result = it.hasNext(&it);
	ASSERT(FAILURE == result);
}

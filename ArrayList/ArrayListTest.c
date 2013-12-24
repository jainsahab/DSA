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
List list;

void setup(){
	int noOfElements = 2;
	list = create(noOfElements);
}

void tearDown(){
	dispose(list.base);
}

void test_1_insert_into_array_list(){
	int result = insert(&list, 0, &first);
	sampleData* actual = (sampleData*)get(&list, 0);
	ASSERT(SUCCESS == result);
	ASSERT(actual->rollNo == first.rollNo);
}

void test_2_insert_multiple_element(){
	sampleData* actual ;
	insert(&list, 0, &first);
	insert(&list, 1, &second);
	actual = (sampleData*)get(&list, 0);
	ASSERT(actual->rollNo == first.rollNo);	
	actual = (sampleData*)get(&list, 1);
	ASSERT(actual->rollNo == second.rollNo);
}

void test_3_insert_element_beyond_its_capacity(){
	sampleData* actual ;
	insert(&list, 0, &first);
	insert(&list, 1, &second);
	insert(&list, 2, &third);
	actual = (sampleData*)get(&list, 0);
	ASSERT(actual->rollNo == first.rollNo);	
	actual = (sampleData*)get(&list, 1);
	ASSERT(actual->rollNo == second.rollNo);
}


void test_4_insert_element_in_between(){
	sampleData* actual ;
	add(&list,  &first);
	add(&list,  &second);
	insert(&list, 1, &third);
	actual = (sampleData*)get(&list, 0);
	ASSERT(actual->rollNo == first.rollNo);	
	actual = (sampleData*)get(&list, 1);
	ASSERT(actual->rollNo == third.rollNo);
	actual = (sampleData*)get(&list, 2);
	ASSERT(actual->rollNo == second.rollNo);
}

void test_5_remove_element_from_between(){
	sampleData* actual ;
	add(&list,  &first);
	add(&list,  &second);
	add(&list, &third);
	remove(&list, 1);
	actual = (sampleData*)get(&list, 0);
	ASSERT(actual->rollNo == first.rollNo);	
	actual = (sampleData*)get(&list, 1);
	ASSERT(actual->rollNo == third.rollNo);
	actual = (sampleData*)get(&list, 2);
	ASSERT(actual == NULL);
}

void test_6_remove_element_from_beginning(){
	sampleData* actual ;
	add(&list,  &first);
	add(&list,  &second);
	add(&list, &third);
	remove(&list, 0);
	actual = (sampleData*)get(&list, 0);
	ASSERT(actual->rollNo == second.rollNo);	
	actual = (sampleData*)get(&list, 1);
	ASSERT(actual->rollNo == third.rollNo);
	actual = (sampleData*)get(&list, 2);
	ASSERT(actual == NULL);
}

void test_7_remove_element_from_end(){
	sampleData* actual ;
	add(&list,  &first);
	add(&list,  &second);
	add(&list, &third);
	remove(&list, 2);
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
	add(&list,  &first);
	add(&list,  &second);
	add(&list, &third);
	actual = (sampleData*)get(&list, 2);
	ASSERT(&third == actual);
	index = search(&list, comparison, str);
	ASSERT(index == expected);
}

void test_9_insert_element_with_getiterator(){
	sampleData* temp;
	int count =0;
	int expected[]={79 ,80, 90};
	Iterator it = getIterator(&list);
	add(&list,  &first);
	add(&list,  &second);
	add(&list, &third);
	while(it.hasNext(&it)){
		temp = (sampleData*)it.next(&it);
		ASSERT(expected[count] == temp->marks);
		count++;
	}

}
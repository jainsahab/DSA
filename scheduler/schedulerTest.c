#include "testUtils.h"
#include "scheduler.h"

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed


void test_to_create_process_head(){
	schedulerQueue* sq;
	Process p1 = {"Browser",10,1};
	sq = create();
	ASSERT(0==sq->length);
	ASSERT(-1==sq->rear);
}

// void test_to_insert_process_in_the_scheduler(){
// 	schedulerQueue* sq;
// 	Process p1 = {"Browser",10,1};
// 	sq = create();
// 	insert(sq, &p1);
// 	ASSERT(sq->head=&p1);
// 	ASSERT(sq->length==1);
// 	ASSERT(sq->rear==0);
// }

// void test_to_insert_two_processes_in_the_scheduler(){
// 	schedulerQueue* sq;
// 	Process p1 = {"Browser",10,1};
// 	Process p2 = {"GCC",10,1};
// 	sq = create();
// 	insert(sq, &p1);
// 	insert(sq, &p2);
// 	ASSERT(sq->head=&p1);
// 	ASSERT(sq->head->next=&p2);
// 	ASSERT(sq->length==2);
// 	ASSERT(sq->rear==1);
// }

void test_to_insert_two_processes_in_the_scheduler(){
	schedulerQueue* sq;
	Process p1 = {"Browser",10,3};
	Process p2 = {"GCC",15,1};
	sq = create();
	insert(sq, &p1);
	insert(sq, &p2);
	ASSERT(sq->head==&p2);
	ASSERT(sq->head->next==&p1);
	ASSERT(sq->length==2);
	ASSERT(sq->rear==1);
}

void test_to_insert_three_processes_in_the_scheduler(){
	schedulerQueue* sq;
	Process p1 = {"Browser",10,3};
	Process p2 = {"GCC",15,1};
	Process p3 = {"Pencil",20,2};
	sq = create();
	insert(sq, &p1);
	insert(sq, &p2);
	insert(sq, &p3);
	ASSERT(sq->head==&p2);
	ASSERT(sq->head->next==&p3);
	ASSERT(sq->head->next->next==&p1);

}
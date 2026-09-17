#include "pch.h"
#include "Lib.h"

TEST(TestCaseName, TestName) {
	EXPECT_EQ(1, 1);
	EXPECT_TRUE(true);
}

TEST(TestTask, init_construct) {
	Task t1;
	EXPECT_TRUE(t1.num_1 >= 0);
	EXPECT_TRUE(t1.num_1 < RAND_MAX);
	EXPECT_TRUE(t1.num_2 >= 0);
	EXPECT_TRUE(t1.num_2 < RAND_MAX);
	EXPECT_TRUE(t1.operation == Operation::add || t1.operation == Operation::struck || t1.operation == Operation::multiplication || t1.operation == Operation::division);
	int answer;
	switch (t1.operation) {
	case add:
		answer = t1.num_1 + t1.num_2;
		break;
	case struck:
		answer = t1.num_1 - t1.num_2;
		break;

	case multiplication:
		answer = t1.num_1 * t1.num_2;
		break;

	case division:
		answer = t1.num_1 / t1.num_2;
		break;

	}
	EXPECT_EQ(t1.answer, answer);
}
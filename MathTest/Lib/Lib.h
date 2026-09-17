#pragma once
#include <random>
#include <ctime>

enum Operation { add = 0, struck, multiplication, division };

struct Task {
	int num_1;
	int num_2;
	int answer;
	enum Operation operation;

	Task();
	Task(int, int, int, char);

};

Task::Task() {
	num_1 = rand() % 10;
	num_2 = rand() % 10;
	operation = static_cast <Operation>(rand() % 4);
	switch (operation) {
		case add:
			answer = num_1 + num_2;
			break;
		case struck:
			answer = num_1 - num_2;
			break;
		
		case multiplication:
			answer = num_1 * num_2;
			break;
		
		case division:
			answer = rand() % 10;
			num_1 = num_2 * answer;
			break;
		
	}
}

class MathTest {
	Task* _tasks;
	int _count;
	int* _user_answers;
	int _correct_answers;
	int _correct_count;
public:
	MathTest(int count);
	MathTest(int count, int min, int max);
	MathTest(int count, int min, int max, char operation);

	~MathTest();

	void run();
	void show_statistics();
	void user_contact();
	void create_tasks(int min, int max, char op);
};




MathTest::MathTest(int count) {

}

void MathTest::create_tasks(int min , int max, char op) {
	for (int i = 0; i < _count ; i++) {
		_tasks[i] = Task(min, max, op);
	}
}


MathTest::~MathTest() {
	delete[] _tasks;
	delete[] _user_answers;
}
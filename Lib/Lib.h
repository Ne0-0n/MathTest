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
			answer = num_1 / num_2;
			break;
		
	}
}

class MathTest;
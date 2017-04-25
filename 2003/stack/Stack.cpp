#include <iostream>
#include <memory.h>
using namespace std;

#define MAX_ELEMENTS 18
int OutOfStackSeq(int queued, int instack);

int memory[MAX_ELEMENTS + 1][MAX_ELEMENTS + 1];

int main(int argc, char* argv[])
{
	int elements;
	cout << "How many elements do you have? ";
	cin >> elements;

	if (elements > MAX_ELEMENTS || elements <= 0) {
		cout << endl << "Must be between 1 to 18." << endl;
		return -1;
	}

	memset(memory, -1, sizeof(memory));

	cout << "There are " << OutOfStackSeq(elements, 0) << " possible ways of out-of-stack sequences." << endl;
	return 0;
}

int OutOfStackSeq(int queued, int instack)
{
	if (memory[queued][instack] >= 0) {
		return memory[queued][instack];
	}

	if (queued == 1 && instack == 0) {
		return 1;
	}
	if (queued == 0 && instack > 0) {
		return 1;
	}
	if (queued == 0 && instack == 0) {
		return 0;
	}

	int ways = 0;
	// The first of the queue goes into the stack.
	if (queued >= 1) {
		ways += OutOfStackSeq(queued - 1, instack + 1);
	}
	// pop out the first of the stack;
	if (instack > 0) {
		ways += OutOfStackSeq(queued, instack - 1);
	}
	memory[queued][instack] = ways;
	return ways;
}

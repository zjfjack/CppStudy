#include <iostream>
#include <string>

struct Vector3
{
	float x, y, z;

	Vector3()
		: x(1), y(2), z(3) {}
};

int main()
{
	// stack
	int value = 5;
	int array[3];
	array[0] = 1;
	array[1] = 2;
	array[2] = 3;
	Vector3 vector;
	// stack things on top of each other
	// Address in memory is vector(12 bytes) cc cc cc cc array cc cc cc cc 05 00 00 00(4 bytes int) cc cc cc cc
	// stack is faster, move the stack pointer and return the address of it, they are close to each other

	// heap is allocating memory and slow, delete is also heavy
	// Go through the free list and ask for memory and bookkeep all of them
	int* hvalue = new int;
	*hvalue = 5;
	int* harray = new int[3];
	harray[0] = 1;
	harray[1] = 2;
	harray[2] = 3;
	Vector3* hvector = new Vector3();

	delete hvalue;
	delete[] harray;
	delete hvector;

	// Address in memory is not closing to each other
}
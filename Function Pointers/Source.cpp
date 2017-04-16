#include <cstdio>
#include <cstdlib>

using namespace std;

void my_int_func(int x) {
	printf("%d\n", x);
}

int int_sorter(const void * first_arg, const void* second_arg) {
	int first = *(int*)first_arg;
	int second = *(int*)second_arg;
	if (first < second) {
		// <
		return -1;
	}
	else if (first == second) {
		// ==
		return 0;
	}
	else {
		// >
		return 1;
	}
}

int main(int argc, char ** argv) {
	// void* - void pointer, allows pointing to everything

	// Declare a function pointer
	// foo is a pointer to a function taking one argument,
	// an integer, and that returns void
	// in other words, we are declaring a function called "*foo"
	// then "foo" is actual pointer to a function
	void(*foo)(int);

	// Another example: *foo should refer to a function
	// that returns a void * and takes an int * 
	// => foo is a pointer to just such a function
	void *(*foo2)(int *);

	// Initialize a function pointer by giviing it the address of a function
	foo = &my_int_func;
	// and call it:
	foo(2);
	// no need to dereference, but still possible
	(*foo)(2);


	int array[10];
	int i;
	// fill array
	for (i = 0; i < 10; i++){
		array[i] = 10 - i;
	}
	// pass our custom int sorter function to qsort()
	qsort(array, 10, sizeof(int), int_sorter);
	// print sorted array
	for (i = 0; i < 10; i++) {
		printf("%d ", array[i]);
	}
	puts("");


	getchar();
	return 0;
}

#include <iostream>
using namespace std;
#include "stack.h"
#include <iostream>
using namespace std;
#include "stack.h"

int  main()
{
	Stack s1;
	s1.reset();
	s1.clean();
	s1.print();

	s1.push(100);
	s1.print();
	s1.push(200);
	s1.push(300);
	s1.print();
	cout << endl << "pop from s1 " << s1.pop();
	s1.print();
	cout << endl << "at the top of s1 " << s1.topOf();
	cout << endl << "pop from s1 " << s1.pop();
	s1.print();
	cout << endl << "pop from s1 " << s1.pop();
	s1.print();

	int numbers[] = { 3,20,51,17 };
	s1.push(numbers,sizeof(4));

	// paraste pieskire
	// te strada kopijas konstruktors
	Stack s2 = s1;
	cout << "&s1="<<&s1 << ", &s2=" << &s2 << endl;
	cout << "s1:";
	s1.print();
	cout << "s2:";
	s2.print();

	s1.push(404);
	cout << "s1:";
	s1.print();
	cout << "s2:";
	s2.print();

	// te nestrada kopijas konstruktors
	// lai novakt kludas jaraksta sava pieskries operacija
	Stack s3;
	s3 = s2;
	cout << "&s2=" << &s2 << ", &s3=" << &s3 << endl;
	cout << "s2:";
	s2.print();
	cout << "s3:";
	s3.print();

	s2.push(666);
	s2.push(1488);
	cout << "s2:";
	s2.print();
	cout << "s3:";
	s3.print();

	getchar();
}



#include <iostream>
using namespace std;
#include "vect.h"

Vect::Vect()
{
	cout << "Vect()" << endl;
	size = 16;
	p = new int[size];
}

Vect::Vect(int n)
{		
	cout << "Vect(int)" << endl;
	if ( n <= 0 ){
		cout <<  "Illegal Vect size: " << n << endl;
		exit(1);
	} 
	size = n;
	p = new int[size];
}

Vect::Vect(const Vect& v)
{
	cout << "Vect(Vect&)" << endl;
	size = v.size;
	p = new int[size];
	for( int i = 0; i < size; ++i) p[i] = v.p[i];
}

Vect::Vect(const int a[], int n)
{	
	cout << "Vect(int[],int)" << endl;
	if ( n <= 0 ){
		cout <<  "Illegal Vect size: " << n << endl;
		exit(1);
	} 
	size = n;
	p = new int[size];
	for( int i = 0; i < size; ++i) p[i] = a[i]; 
}

int& Vect::operator [](int i)
{
	cout << "Vect operator []" << endl;
	if ( i < 0 || i > size-1 ){
		cout <<  "Illegal Vect index: " << i << endl;
getchar();
		exit(2);
	} 
	return ( p[i] );
}

Vect& Vect::operator =(const Vect& v)
{
	cout << "Vect operator =" << endl;
	// kadu izmeru mums vajag?
	int s = (size < v.size) ? size : v.size;
	for( int i = 0; i < s; ++i) p[i] = v.p[i];
	return ( *this );
}

void Vect::print(int n)
{
	int s = ( n < size ) ? n : size;
	for( int i = 0; i < s; ++i) cout << p[i] << ' ';
	cout << endl;
}

void Vect::print()
{
	print(size);
}

Vect& Vect::operator+(int c)
{
	cout << "Vect operator + (int)" << endl;
	for( int i = 0; i < size; ++i) p[i] += c;
	return ( *this );
}

Vect& Vect::operator++()
{
	cout << "Vect operator ++" << endl;
	for (int i = 0; i < size; i++)
      p[i]++;

   return *this;
}
Vect& operator+(int c, Vect& v)
{	
	cout << "Vect operator + (int, Vect&)" << endl;
	v + c;
	return (v);
}

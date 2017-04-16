#include <cstdio>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

/*
A data structure is a group of data elements grouped together under one name.
These data elements, known as members, can have different types and different lengths.
Data structures can be declared in C++ using the following syntax:
	struct type_name {
		member_type1 member_name1;
		member_type2 member_name2;
		member_type3 member_name3;
		.
		.
	} object_names;
*/

struct product {
	int weight;
	double price;
} orange, grape;
// orange and grape are instantiated here

void printProductInfo(const product & p) {
	cout << "price: " << p.price << ", weight: " << p.weight << endl;
}

struct director_t {
	string name;
	int age;
};

struct movies_t {
	string title;
	int year;
	director_t director;
} mine, yours;

void printmovie(movies_t movie);

int main(int argc, char **argv)
{
	product apple, banana;
	product * melon;
	melon = new product();

	apple.weight = 3;
	apple.price = 25.50;
	printProductInfo(apple);

	melon->weight = 7;
	melon->price = 50;
	printProductInfo(*melon);


	string mystr;

	mine.title = "2001 A Space Odyssey";
	mine.year = 1968;
	director_t director;
	director.name = "Stanley Kubrick";
	director.age = 70;
	mine.director = director;

	cout << "Enter title: ";
	getline(cin, yours.title);
	cout << "Enter year: ";
	getline(cin, mystr);
	stringstream(mystr) >> yours.year;

	cout << "My favorite movie is:\n ";
	printmovie(mine);
	cout << "And yours is:\n ";
	printmovie(yours);

	// extract information about director from a movie struct
	director_t spaceOdysseyDirector = (struct director_t)mine.director;


	getchar();
	return 0;
}

void printmovie(movies_t movie)
{
	cout << movie.title;
	cout << " (" << movie.year << "), by " << movie.director.name << endl;
}
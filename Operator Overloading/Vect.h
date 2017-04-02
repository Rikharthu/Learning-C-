class Vect{
private:
	int *p;
	int size;
public:
	Vect();						// create a size 16 vector
	Vect(int n);               	// create a size n vector
	Vect(const Vect& v);          	// create and initialize by vector
	Vect(const int a[], int n);    	// create and initialize by array
	~Vect() { delete p; }               	// inline destructor

	int& operator [](int i);            	// overloaded [] : range checked element of vector
	Vect& operator =(const Vect& v);    	// overloaded =  : assignment of vector
   	
    Vect& operator+(int c);					// overloaded + int
	Vect& operator++();   					//overloaded prefix  ++x
	friend  Vect& operator+(int c, Vect& v);
	int getsize() { return size; }       	// size of vector
	void print(int n);			// print first n elements
	void print();				// print all elements
};

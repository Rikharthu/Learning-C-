#include <iostream>
using namespace std;

#include "Figure.h"
#include "Rectangle.h"
#include "RectangleFilled.h"

int main()
{
	{
		cout << "Begin";
		getchar();    // begin internal block

		RectangleFilled *prf;
		getchar();
		prf = new RectangleFilled;                            
		getchar();

		Rectangle r(1, 1, 10, 20);                                
		getchar();
		cout << "\nArea of rectangle is " << r.area() << endl;   
		getchar();

		prf->setDim(0, 0, 3, 5);
		prf->setColor(15);
		cout << "\nArea of filled rectangle is " << prf->area() << endl;  
		getchar();

		// dynamic objects must be deleted
		delete prf;                                            
		getchar();
		// static objects are deleted automatically
	} cout << "End";         // end of internal block


	getchar();
}

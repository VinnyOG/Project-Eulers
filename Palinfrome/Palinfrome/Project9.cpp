#include <iostream>
#include <string>
using namespace std;

/*
project euler #9
*/

void pytriple(){

	//c cannot be bigger than 1,000 becasue a + b + c = 1000 this is the absolute max
	for (int c = 1; c < 1000; c++){
		int c2 = pow(c, 2);

		for (int a = 1; a < c; a++){
			int a2 = pow(a, 2);
			double b = sqrt(c2 - a2);

			if (fmod(b,2) != 0) continue; //b must be natural number

			//cout << a + b + c << endl;
			if (a + b + c == 1000){
				cout << "Found them! " << a << " " << b << " " << c << endl;
				long product = a * b * c;
				cout << "Sum is " << a + b + c << endl;
				cout << "Product is " << product << endl;
				return;
			}
		}
	}
}
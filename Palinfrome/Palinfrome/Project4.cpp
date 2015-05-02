#include <iostream>
#include <string>

/*
Not the most elegant solution but a solution nonetheless
project euler #4
*/

using namespace std;


int palindrome(int size);

void string_test(){
	string number = to_string(906609);
	bool palindrome = true;
	cout << number << endl;
	auto str = number.begin();
	for (auto rev = number.rbegin(); rev != number.rend(); ++rev, str++){
		cout << (*rev) << "\t" << (*str) << endl;
		if ((*rev) != (*str)) palindrome = false;
	}
	cout << palindrome << endl;
}

void pali(){
	cout << "Largest Palidrome formed by multipying 3 numbers is: " << palindrome(3); //largest of two products
	//palindrome(3);

	//string_test();

	string boo;
	cin >> boo;
}

int palindrome(int size){
	int max_multiple = pow(10, size) - 1, max_palindrome = 0, product = 0;
	//cout << max_multiple << " " << pow(10, size - 1) << endl;
	string number;
	bool palindrome = false;

	for (int i = max_multiple; i > pow(10, size - 1); i--){
		for (int j = max_multiple; j > pow(10, size - 1); j--){
			product = i * j;
			number = to_string(product); //now we have our number

			//look back in reverse of the number
			palindrome = true;
			auto str = number.begin();
			for (auto rev = number.rbegin(); rev != number.rend(); ++rev, str++){
				if ((*rev) != (*str)) palindrome = false;
			}
			if (palindrome){
				//cout << product << "\t" << max_palindrome << endl;
				if (product > max_palindrome) max_palindrome = product;
			}
		}
	}
	cout << max_palindrome << endl;
	return atoi(number.c_str());
}
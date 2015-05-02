#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include "fifty_digit_numbers.h"

using namespace std;

class BigNumber{
private:
	char digits[100];

public:
	BigNumber(){
		for (char& c : digits){
			c = 0;
		}
	}

	void assign(string n){
		for (unsigned int i = 0; i < n.size(); i++){
			digits[99 - i] = n[n.size() - i - 1] - 48;  //we keep them in decimal
		}
	}

	void print(){
		bool zeros = true;
		for (int i = 0; i < 100; i++){
			if (digits[i] != 0) zeros = false;
			if (!zeros) cout << (char) (digits[i] + 48);
		}
	}

	BigNumber& operator += (BigNumber& b){
		for (int i = 99; i > 0; i--){
			digits[i] += b.digits[i];
			digits[i - 1] += digits[i] / 10;
			digits[i] %= 10;
		}
		return *this;
	}
};

vector<BigNumber> numbers;

void project13(){
	stringstream number_stream(the_numbers_list);
	string num;
	for (int i = 0; i < 100; i++){
		number_stream >> num;
		BigNumber number;
		number.assign(num);
		numbers.push_back(number);
	}
	
	BigNumber sum;
	for (int i = 0; i < 100; i++){
		sum += numbers[i];
	}
	sum.print();
}
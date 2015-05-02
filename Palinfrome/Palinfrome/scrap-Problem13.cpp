#include <iostream>
#include <sstream>
#include <vector>
#include <limits>
#include "fifty_digit_numbers.h"
using namespace std;


/*
project euler #13
*/

stringstream bignumber(the_numbers);

//This guy will only hold positive (unsigned) large numbers
class BigNumber{
private:
	//we'll used the signed property to detect addition overflows
	vector<long long> number_segments;

public:

	BigNumber(stringstream s){

	}

	//This is how we add
	BigNumber& operator += (BigNumber& b){
		int segmentsA = this->number_segments.size();
		int segmentsB = b.number_segments.size();
		long long sum_segment;

		bool overflow = false;
		bool local_overflow = false;
		int i = 0;
		for (; i < segmentsA || i < segmentsB; i++){
			sum_segment = this->number_segments[i] + b.number_segments[i];
			local_overflow = sum_segment < 0;
			sum_segment &= 0x7FFFFFFFFFFFFFFF;
			if (overflow) sum_segment++;
			this->number_segments[i] = sum_segment;
			overflow = local_overflow;
		}
		if (i < segmentsA){ //there's more in numberA
			if (overflow) this->number_segments[i]++;
		}
		for (; i < segmentsB; i++){ //we need to move the rest of the segment over
			this->number_segments.push_back(b.number_segments[i]);
			if (overflow) this->number_segments[i]++;
			overflow = false;
		}
		return *this;
	}
};

void scrap_project13(){



	cout << numeric_limits<long long>::max() << " " << numeric_limits<unsigned long long>::max() - numeric_limits<long long>::max() << endl;
}
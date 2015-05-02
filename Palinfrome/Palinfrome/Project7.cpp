#include <iostream>

/*
project euler #7
*/

using namespace std;

//will claim 1 is prime! 
bool is_prime(long test){
	bool prime = true;
	for (long i = 2; i < powf(test, 0.5) + 1 && prime; i++){
		if (test % i == 0){
			//cout << test << " is divisible by " << i << endl;
			prime = false;
		}
	}
	return prime;
}

void ordered_prime(int goal){
	int current = 0;
	long current_prime = 2;
	for (int i = 2; current < goal; i++){
		if (is_prime(i)){
			current++;
			current_prime = i;
			//cout << current << ": " << (current_prime = i) << endl;
		}
	}
	cout << "The " << goal << " prime is: " << current_prime << endl;
}
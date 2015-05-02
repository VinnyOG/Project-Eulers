#include <iostream>
#define upper_limit 2000000
using namespace std;

/*
Project euler #10
*/

//useful function from previous problem
extern bool is_prime(long);

void sum_prime_under_2_million(){
	long long sum = 2;
	for (int i = 3; i < upper_limit; i+=2){    //is_prime claims that 1 is prime :(
		if (is_prime(i)) sum += i;
	}
	cout << "Sum of primes under 2 million is: " << sum << endl;
}
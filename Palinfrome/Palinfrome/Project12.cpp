#include <iostream>
#include <vector>
#define min_divisors 500
using namespace std;

/*
project euler problem #12
just a warning: this takes about half an hour on core m 5y10
*/


int get_divisors(int in){
	int sum = 0;
	for (int i = 1; i <= in; i++){
		if (in % i == 0){
			sum++;
		}
	}
	return sum;
}

void find_triangle(){
	int current_divisors = 0;
	int counting = 1;
	int triangle_number = 0;
	int num_divisors = 0, max_divisors = 0;

	for (int couting = 1; num_divisors <= min_divisors; counting++){
		triangle_number += counting;
		current_divisors = get_divisors(triangle_number);
		if (current_divisors > num_divisors) num_divisors = current_divisors;

		//cout << "Triangle number " << triangle_number << " has " << triangle_divisors.size() << " divisors." << endl;
	}

	counting--; //to compesate for last completion of for loop
	cout << "The first triangle number with more than " << min_divisors << " divisors is " << triangle_number << endl;
}
#include <iostream>

using namespace std;

/*
project euler #6
*/

int sum_of_squares(int lower_bound, int higher_bound){
	int sum = 0;
	for (int i = lower_bound; i <= higher_bound; i++){
		sum += (int) pow(i, 2); //square it!
	}
	return sum;
}

int square_of_sum(int lower_bound, int higher_bound){
	int sum = 0;
	for (int i = lower_bound; i <= higher_bound; i++) sum += i;
	return (int) pow(sum, 2); //square it!
}

void sum_squares(){
	cout << "Difference between sum of squares and square of sums is: " << abs(sum_of_squares(1, 100) - square_of_sum(1, 100)) << endl;
}
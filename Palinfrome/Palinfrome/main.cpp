#include <iostream>

using namespace std;

//These functions already print their results
extern void pali();
extern void sum_squares();
extern void ordered_prime(int p);
extern void series_product();
extern void pytriple();
extern void sum_prime_under_2_million();
extern void find_grid();
extern void find_triangle();
extern void project13();
//extern void collatz();
extern void problem14();

int main(){

	//sum_squares();
	//ordered_prime(10001);
	//pali();  //this one takes a while
	//sum_squares();
	//series_product();
	//pytriple();
	//sum_prime_under_2_million();
	//find_grid();
	//find_triangle();
	//project13();
	//collatz();
	problem14();

	cin.ignore();
}
#include <iostream>
#include <vector>

using namespace std;

long iterate(long n){
	return n % 2 == 0 ? n / 2 : 3 * n + 1;
}

struct chain{
	int length = 1;
	int start_num = 0;
	long long value = 0;
};

void collatz(){
	chain current, longest;
	longest.length = longest.start_num = 0;

	
	cout << (current.value = 837799);
	while (current.value > 1){
		cout << " " << (current.value = iterate(current.value));
		current.length++;
	} cout << " " << current.length;
	cin.ignore();
	

	for (int i = 0; i < 1000000; i++){
		current.length = 1;
		current.start_num =  current.value = i;
		while (current.value > 1){
			current.value = iterate(current.value);
			current.length++;
		}
		if (current.length > longest.length){
			longest = current;
		}
		if (i % 100000 == 0) cout << "Current largest chain starts at " << current.start_num << " with length " << current.length << endl;
	}
	cout << "Largest chain starts at " << longest.start_num << " with length " << longest.length << endl;
}
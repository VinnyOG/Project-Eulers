//Project Euler #14

#include <iostream>
#include <bitset>
#include <string>
#include <Windows.h>
#define number_size 128
#define print_level 1000

using namespace std;

struct chain{
	int length = 0;
	int start_val = 0;
	bitset<number_size> starting_number;
	bitset<number_size> number;
} current, longest;

bitset<number_size> temp;

//time for some brute force!
void problem14(){
	current.starting_number[1] = 1; //start at 2
	bool carry = false, and = false, xor = false;
	size_t max_used_bits = 0;

	//i and chain.number are independent but must be same value
	for (int i = 2; i < 1000000; i++){
		if(i % print_level == 0) cout << "Working on block: " << i << endl;
		wstring title_text = L"Current Number: " + to_wstring(i);
		//SetConsoleTitle(title_text.c_str());
		current.length = 1;
		current.start_val = i;
		current.number = current.starting_number;
		while (!(current.number.count() == 1 && current.number[0] == 1)){

			//if (i % print_level == 0)  cout << current.number.to_string() << endl;

			//step up
			if (current.number[0] == 1){ //if it is odd (then multiply by 3 and add 1)
				temp = current.number;
				current.number <<= 1; //times 2

				//add temp that to make it times 3
				for (size_t j = 0; j < number_size; j++){
					and = current.number[j] & temp[j];
					xor = current.number[j] ^ temp[j];
					if (xor){ //1 and 0
						if (carry){ //1 and 1 becomes 0
							current.number[j] = 0;
							//carry stays true
						}
						else{
							current.number[j] = 1; //just 1+0 with no carry
							carry = false;
						}
					}
					else if (and){ //1 and 1
						//either way carry stays true
						if (carry){
							current.number[j] = 1;
						}
						else{
							current.number[j] = 0;
							carry = true;
						}
					}
					else { //0 and 0
						if (carry){
							current.number[j] = 1;
							carry = false;
						}
						//otherwise we have 0 + 0 + 0 = 0
						//no need to set since current bit was already found to be 0
					}
					
				}

				//increment
				for (size_t j = 0; j < number_size; j++){
					if (current.number[j] == 0){
						current.number[j] = 1;
						break;
					}
					current.number[j] = 0;  //move on until 0 is found
				}
			}
			else{
				current.number >>= 1; //divide by 2
			}//end itteration

			//see how many bits we're using out of curiosity (and to make sure 128 is enough)
			size_t num_bits;
			for (num_bits = number_size - 1; num_bits > 0; num_bits--){
				if (current.number[num_bits] == 1){
					break;
				}
			}
			if (num_bits > max_used_bits){
				max_used_bits = num_bits;
			}

			current.length++;
		}

		if (current.length > longest.length){
			longest = current;
			cout << "New longest chain (starting at " << longest.start_val << " using " << max_used_bits << " bits) found! Size: " << longest.length << endl;
		}

		//if (i % print_level == 0) cout << "Chain (starting at " << current.start_val << " ) finished! Size: " << current.length << endl << endl;

		//increment starting number
		for (size_t j = 0; j < number_size; j++){
			if (current.starting_number[j] == 0){
				current.starting_number[j] = 1;
				break;
			}
			current.starting_number[j] = 0;  //move on until 0 is found
		}

	}


}
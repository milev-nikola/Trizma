#include <string>
#include <iostream>
#include <vector>

// Function which computes the sequence 
std::string NumbersToSequence(std::string input)
{
	std::string output = "";

	//Buffer for storing temporary data
	std::string buff = "";
	//Flag for upper case letters
	bool upper = false;
	//Counter for "1 brackets"
	unsigned counter = 0;
	//Current letter
	char current = NULL;
	//Letter to put in final sequence
	char letter;

	//Numpad representation
	std::vector<std::string> str = { 
		"2","22","222", 
		"3","33","333",
		"4","44","444", 
		"5","55","555",
		"6","66","666",
		"7","77","777","7777",
		"8","88","888",
		"9","99","999","9999"
	};



	for (std::size_t i = 0; i < input.length(); i++)
	{
		// Checking for space 
		if (input[i] == ' ')
			++i;
		// Checking for zeroes
		else if (input[i] == '0') {
			output += ' ';
			++i;
		}
		// Does uppercase letters sequence begins?
		else if (input[i] != '1') {
			//If no then no worries, split same cyphers sequences and proceed
			current = input[i];
			while (input[i] == current) {
				buff += current;
				i++;
			}

			size_t delimiter = std::distance(str.begin(), std::find(str.begin(), str.end(), buff));

			//If uppercase letter's sequence has begun, use upercase letter 'A' for resolving characters, otherwise use lowercase 'a' 
			if (upper)	letter = 'A' + delimiter;
			else letter = 'a' + delimiter;

			output += letter;
		}
		else {
			++i;
			++counter;
			//If counter's value is odd that means that uppercase letters sequence has begun, if it is even sequnce ends
			if (counter % 2 == 0) upper = false;
			else upper = true;
		}
		buff = "";
	}

	// Output sequence 
	return output;
}

 //main
int main()
{
	std::string input = "44 33 555 555 666 0 9 666 777 555 3 0 44 33 555 555 666 0 9 666 777 555 3 0 44 33 555 555 666 0 9 666 777 555 3";
	std::cout << NumbersToSequence(input) << std::endl;

	input = "1 222 1 2 777";
	std::cout << NumbersToSequence(input) << std::endl;

	input = "1 66 222 777 1";
	std::cout << NumbersToSequence(input) << std::endl;

	input = "1 9 1 33 555 222 666 6 33 0 8 666 0 1 66 222 777 1";
	std::cout << NumbersToSequence(input) << std::endl;

	


	return 0;
}
#include <string>
#include <iostream>

std::string num_message;
int number;
int repeat;

std::string GenerateUpperLetters(std::string upperLetters) {
	if (upperLetters.length() == 0) return "";
	return '1' + upperLetters + '1';
}

// Checks if current letter is 's' or 'z' (repeat is realised with usage of mod(3); in this case we need 4 repetitons
void checkLetters(char c) {
	if (c == 's' || c == 'S') {
		number = 7;
		repeat = 4;
	}
	else if (c == 'z' || c == 'Z') {
		number = 9;
		repeat = 4;
	}
	else if (c == ' ') {
		number = 0;
		repeat = 1;
	}
}

std::string SentenceToNumber(std::string message) {
	std::string upperLetters;
	char numberChar, aChar;
	std::string numRepresentation = "";

	for (int i = 0; i < message.length(); ++i) {
		// Checks if given letter is uppercase
		if (message[i] >= 'A' && message[i] <= 'Z') {
			aChar = 'A';
		}
		else {
			aChar = 'a';
		}

		bool check = false;
		// For letters that come after letter 's', we decrease value by 1 because keypad '7' has 4 letters
		if (message[i] > 's' || (message[i] > 'S' && message[i] <= 'Z')) {
			message[i] -= 1;
			check = true;
		}

		number = (message[i] - aChar) / 3 + 2;
		repeat = (message[i] - aChar) % 3 + 1;

		if (!check) {
			checkLetters(message[i]);
		}
		numberChar = std::to_string(number)[0];

		// If given letter is upercase we add it to uppercase letter's buffer,
		// otherwise we free upperLetters buffer and generate lowercase letters
		if (aChar == 'A') {
			for (int j = 0; j < repeat; ++j) {
				upperLetters += numberChar;
			}
		}
		else {
			numRepresentation += GenerateUpperLetters(upperLetters);
			for (int j = 0; j < repeat; ++j) {
				numRepresentation += numberChar;
			}
			upperLetters = "";
		}

		if (i == message.length() - 1) {
			numRepresentation += GenerateUpperLetters(upperLetters);
		}

		

	}
	return numRepresentation;
}



int main() {
	std::cout << SentenceToNumber("Welcome to NCR") << std::endl;
	return 0;
}

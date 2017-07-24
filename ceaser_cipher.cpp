// Author: etratipza@gmail.com
// Date: 7-20-2017
//
// A simple ceaser cipher program that
// works on alpha-numeric values.
#include <iostream>
#include <cstring>
#include <cctype>



char isUpperAlpha( char letter, int shift_val ) {
	int temp =  letter - 'A';
	
	int new_val = (temp + shift_val) % 26; 

	if ( new_val < 0 )
		new_val += 26;

	return (char) new_val + 'A';
}

char isLowerAlpha( char letter, int shift_val ) {
	int temp =  letter - 'a';
	
	int new_val = (temp + shift_val) % 26; 

	if ( new_val < 0 )
		new_val += 26;

	return (char) new_val + 'a';
}

char isDigit( char letter, int shift_val ) {
	int temp =  letter - '0';
	
	int new_val = (temp + shift_val) % 10; 

	if ( new_val < 0 )
		new_val += 10;

	return (char) new_val + '0';
}

char check_letter(char letter, int shift_val) {
	
	// Shift Alpha-numeric values
	if (letter >= 'A' && letter <= 'Z')	{
		return isUpperAlpha( letter, shift_val );
	}
	else if (letter >= 'a' && letter <= 'z') {
		return isLowerAlpha( letter, shift_val );
	}
	else if (letter >= '0' && letter <= '9') {
		return isDigit( letter, shift_val );
	}
		
	// If the character is not alpa-numeric return character
	return letter;



	//return (char) ((( ( (int) letter - 97) + 26 + (ciph%26) -1) % 26 + 1) + 97); 
}

bool is_valid_num(char* input) {
	char * start = input;
	
	if ( *input == '-' ) { input++; }

	while ( *input != '\0' ) {
		if ( isdigit( *input ) ) {
			input++;
		}
		else {
			std::cout << "Did not include a valid integer (-1000000000, 1000000000)" << std::endl;
			return false;
		}
	}
	
	int temp = atoi(start);
	if (temp < -1000000000 || temp > 1000000000) { return false; }
	
	return true;
}

void cipher(char* text) {

	char * colon = nullptr;
	colon = strchr(text, ':');
	
	// Parse and lex data
	// check if text included a colon
	if ( colon == nullptr ) {
		std::cout << "Invalid input, use:\n(int):(string)" << std::endl;
		return;
	}
	colon++;
	*(colon - 1) = '\0';
	
	// check if the input included a valid int
	if ( !is_valid_num(text) ) {
		std::cout << "Did not include a valid integer (-1000000000, 1000000000)" << std::endl;
		return;
	}
	int shift_val = atoi(text);

	// shift character values	
	while ( *colon != '\0') {
		std::cout << check_letter( *colon, shift_val );
		colon++;
	}
	
	std::cout << "shift value: " << shift_val << std::endl;
}

int main() {
	
	char some_text[] = "-1:This is some text haha 123!";

	cipher( some_text );	

	std::cout << "Done" << std::endl;
	return 0;
}

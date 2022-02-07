#include <iostream>
#include <cmath> // needed for pow()
#include <ios> // needed for stream size
#include <limits> // needed for numeric limits
#include <vector> // needed for vectors

// FUNCTIONS

float CalculateTorus(float r, float R)
{
	const float pi = 3.14159; // this program doesn't need to be precise, so this suffices!
	float volume; // declare volume
	// this is the cheap hack to make the tire a torus, as explained in the README.md file
	float adjusted_R = R + r;
	volume = pi * pow( r, 2 ) * 2 * pi * adjusted_R;
	return volume;
}

void ClearStreamBuffer()
{
	// clears the stream buffer before the new line
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// MAINLINE LOGIC
int main(int argc, char **argv)
{
	// bool to indicate if data entry is over
	bool finished=false;
	// char for user Y/N answer
	char user_answer;
	// int for ISO tire/wheel diameter
	int iso_diameter;
	// int for ISO tire width
	int iso_width;
	// there are always two data points per tire, but an unknown number of tires
	// thus we need a vector of tire data arrays with two spots
	std::vector<int[2]> tires;
	

	// print welcome message
	std::cout <<
		"COMPARE TIRE VOLUME\n"
		"-------------------\n"
		"You will need the ISO rim diameter and the ISO tire width.\n"
		"This should be printed on the tire, e.g. '622x32'\n"
		"Are you ready to enter your first tire? (Y/N):\t";

	//std::cin.read(tolower(user_answer), 1);
	std::cin >> user_answer; // read user answer
	ClearStreamBuffer(); // clear the buffer
	
	// debug
	std::cout << "User answer is: " << user_answer << std::endl;
	// end debug

	if (tolower(user_answer) != 'y') // evaluate the user answer
		finished=true;
	
	// repeat the data entry loop until the user is finished
	while (finished == false) 
	{
		std::cout << "\nEnter ISO rim diameter:\t\t";
		std::cin >> iso_diameter;
		ClearStreamBuffer();
		
		// debug
		std::cout << "got: " << iso_diameter;
		// end debug

		std::cout << "\nEnter ISO tire width:\t\t";
		std::cin >> iso_width;
		ClearStreamBuffer();

		// debug
		std::cout << "got: " << iso_width;
		// end debug
		
		std::cout << "\nAre you finished? (Y/N):\t";
		std::cin >> user_answer;
		ClearStreamBuffer();
	
		if (tolower(user_answer) == 'y') // evaluate the user answer
			finished=true;
	}

	return 0;
}

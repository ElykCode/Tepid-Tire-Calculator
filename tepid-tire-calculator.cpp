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
	// there are always two data points per tire, and two tires
	int tires[2][2];

	int loop_count = 0;

	// print welcome message
	std::cout <<
		"COMPARE VOLUME OF TWO TIRES\n"
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
		exit(1);
	
	// get data for two tires
	for (int i=0;i<2;i++)
	{
		std::cout << "\nEnter ISO rim diameter for tire " << i+1 << ":\t";
		std::cin >> iso_diameter;
		ClearStreamBuffer();

		// add diameter to the array
		tires[i][0]=iso_diameter;

		// debug
		//std::cout << "got: " << iso_diameter;
		// end debug

		std::cout << "\nEnter ISO width for tire " << i+1 << ":\t\t";
		std::cin >> iso_width;
		ClearStreamBuffer();

		// store width in the array for later use
		tires[i][1]=iso_width;

		// debug
		//std::cout << "got: " << iso_width;
		// end debug
	}

	// debug
	for (int i=0;i<2;i++)
	{
		std::cout << "Tire " << i+1 << ": " << tires[i][0] << " x " << tires[i][1] << std::endl;
	}
	// end debug


	return 0;
}

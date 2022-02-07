#include <iostream>
#include <cmath> // needed for pow()

// FUNCTIONS

float CalculateTorus(float r, float R)
{
	const float pi = 3.14159; // this program doesn't need to be precise, so this suffices!
	float volume; // declare volume
	// this is the cheap hack to make the tire a torus, as explained in the README.md file
	float adjusted_R = R + r
	volume = pi * pow( r, 2 ) * 2 * pi * adjusted_R;
	return volume;
}

// MAINLINE LOGIC
int main(int argc, char **argv)
{
	return 0;
}

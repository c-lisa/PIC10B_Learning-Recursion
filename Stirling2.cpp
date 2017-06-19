/** @file Stirling2.cpp
@brief Contains the class definitions for the Stirling2 class.
@author Lisa Chiang
@date February 17, 2015

The definitions for the constructors, recursive function, and outputting function for Stirling2 are here.
*/

#include<iostream>
#include "Stirling2.h"
/**@brief Stirling2 Default Constructor

Sets x = 0.
Sets y = 0.

@param No parameters.
@return No returns.
*/
Stirling2::Stirling2()
{
	x = 0;
	y = 0;
}
/**@brief Stirling2 Constructor

Sets x and y equal to user-inputted value.

@param m_input is set to private variable x and y.
@return No returns.
*/
Stirling2::Stirling2(int m_input)
{
	x = m_input;
	y = m_input;
}
/**@brief Making Stirling2 Recursive Function

Checks base cases of Stirling2. Then recursively returns the function until a base case is reached.

@param k is the user-inputted int that is used to calculate the Stirling2.
@param n is the user-inputted int that is used to calculate the Stirling2.
@return int that is the solution to the Stirling2 formula.
*/
int Stirling2::make_Stirling2(int k, int n)
{
	if (k < 0 || n < 0)
	{
		return 0;
	}
	else if (k == 0 && n > 0)
	{
		return 0;
	}
	else if (k > 0 && n == 0)
	{
		return 0;
	}
	else if (k > n)
	{
		return 0;
	}
	else if (k == n)
	{
		return 1;
	}

	int one = k; 

	return (one*(make_Stirling2(k, n - 1)) + (make_Stirling2(k - 1, n - 1)));
}
/**@brief Writing Stirling2 to a File

Creates a file named Stirling2.txt that the results of the make_Stirling2 function is inputted to.

@param m is the user-inputted number that gets sent to the make_Stirling2 function.
@return Returns nothing.
*/
void Stirling2::sendtofile(int m)
{
	std::ofstream outputData("Stirling2.txt");

	std::cout << "Creating Stirling2.txt file ... ";

	for (size_t i = 1; i <= m; i++) //row
	{
		for (size_t l = 1; l <= m; l++) //column
		{
			outputData << make_Stirling2(i, l) << " ";
		}
		outputData << std::endl;
	}
	outputData.close();

	std::cout << "Done." << std::endl;
}

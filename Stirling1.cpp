/** @file Stirling1.cpp
@brief Contains the class definitions for the Stirling1 class.
@author Lisa Chiang
@date February 17, 2015

The definitions for the constructors, recursive function, and outputting function for Stirling1 are here.
*/

#include<iostream>
#include "Stirling1.h"
/**@brief Stirling1 Default Constructor

Sets x = 0.
Sets y = 0.

@param No parameters.
@return No returns.
*/
Stirling1::Stirling1()
{
	x = 0;
	y = 0; 
}
/**@brief Stirling1 Constructor

Sets x and y equal to user-inputted value.

@param m_input is set to private variable x and y.
@return No returns.
*/
Stirling1::Stirling1(int m_input)
{
	x = m_input;
	y = m_input; 
}
/**@brief Making Stirling1 Recursive Function

Checks base cases of Stirling1. Then recursively returns the function until a base case is reached.

@param k is the user-inputted int that is used to calculate the Stirling1.
@param n is the user-inputted int that is used to calculate the Stirling1.
@return int that is the solution to the Stirling1 formula.
*/
int Stirling1::make_Stirling1(int k, int n)
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
	
	int one = -(n - 1); 

	return (one*(make_Stirling1(k, n - 1)) + (make_Stirling1(k-1,n-1))); 
}
/**@brief Writing Stirling1 to a File

Creates a file named Stirling1.txt that the results of the make_Stirling1 function is inputted to.

@param m is the user-inputted number that gets sent to the make_Stirling1 function.
@return Returns nothing.
*/
void Stirling1::sendtofile(int m)
{
	std::ofstream outputData("Stirling1.txt");

	std::cout << "Creating Stirling1.txt file ... ";

	for (size_t i = 1; i <= m; i++) //row
	{
		for (size_t l = 1; l <= m; l++) //column
		{
			outputData << make_Stirling1(i, l) << " ";
		}
		outputData << std::endl;
	}
	outputData.close();

	std::cout << "Done." << std::endl;
}

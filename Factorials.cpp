/** @file Factorials.cpp
@brief Contains the class definitions for the Factorials class.
@author Lisa Chiang
@date February 17, 2015

The definitions for the constructors, recursive function, and outputting function for Factorials are here.
*/

#include<iostream>
#include "Factorials.h"
#include "Integer.h"

/**@brief Factorials Default Constructor

Sets n = 0.

@param No parameters.
@return No returns.
*/
Factorials::Factorials()
{
	n = 0;
	//n2 = 0; 
}
/**@brief Factorials Constructor

Sets n equal to user-inputted value.

@param n_input is set to private variable n . 
@return No returns.
*/
Factorials::Factorials(int n_input)
{
	n = n_input;
	//n2 = n; 
}
/**@brief Solving Factorials Recursive Function 

Checks base cases of Factorials. Then creates the n case and n-1 case using the user-inputted 
int. It has been set to a double to increase the capacity for bigger numbers. Then it uses recursion
until the problem is solved. 

@param n_input is the user-inputted double that is used in calculating the factorial. 
@param init_weight is set to private variable weight.
@return double that is the solution to the factorial of given n_input. 
*/
double Factorials::solving_factorial(double n_input)
{
	///base case(s)
	if (n_input == 0)
	{
		return 1; 
	}

	/*Integer one_first = 1; 

	Integer one(n_input); 
	Integer two = solving_factorial(one - one_first); 

	Integer A = one*two; 

	A.print_as_int(); */

	double one = n_input; 
	double two = solving_factorial(one - 1); 
	
	return one*two; 
}
/**@brief Writing Factorial to a File 

Creates a file named Factorials.txt that the results of the solving_factorial function is inputted to. 

@param m is the user-inputted number that gets sent to the solving_factorial function. 
@return Returns nothing.
*/
void Factorials::sendtofile(int m)
{
	//opens the file we want to write to
	std::ofstream outputData("Factorials.txt");

	std::cout << "Creating Factorials.txt file ... ";

	//writes the results of each integer leading up to m
	for (size_t i = 1; i <= m; i++)
	{
		outputData << solving_factorial(i) << std::endl; 
	}

	//closes the file we wrote to
	outputData.close();

	std::cout << "Done." << std::endl;
}

/*
int m (a, b) 
remainder when a/b 
m(7/3)

n = 7 
n-1 = 6? 
Ex. 7%6 = 1 //you keep minusing 6 until you get that 

int magic (int a, int b)
{
	if (a < b) 
	{
		return a;
	}

	return (a-b, b); 
}

*/


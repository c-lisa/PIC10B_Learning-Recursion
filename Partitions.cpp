/** @file Partitions.cpp
@brief Contains the class definitions for the Partitions class.
@author Lisa Chiang
@date February 17, 2015

The definitions for the constructors, recursive function, and outputting function for Partitions are here.
*/

#include<iostream>
#include "Partitions.h"

/**@brief Partitions Default Constructor

Sets x = 0.
Sets y = 0. 

@param No parameters.
@return No returns.
*/
Partitions::Partitions()
{
	x = 0; 
	y = 0; 
}
/**@brief Partitions Constructor

Sets x and y equal to user-inputted value.

@param m_input is set to private variable x and y.
@return No returns.
*/
Partitions::Partitions(int m_input)
{
	x = m_input; 
	y = m_input; 
}
/**@brief Making Partitions Recursive Function

Checks base cases of Partitions. Then recursively returns the function until a base case is reached.

@param k is the user-inputted int that is used to calculate the partition. 
@param n is the user-inputted int that is used to calculate the partition. 
@return int that is the solution to the partitions formula.
*/
int Partitions::make_partition(int k, int n)
{
	//base cases
	if (k < 0 || n < 0)
	{
		return 0; 
	}
	else if (k == 0 && n > 0)
	{
		return 0; 
	}
	else if (k >= 0 && n == 0)
	{
		return 1; 
	}
	else if (k > n)
	{
		return make_partition(n, n); 
	}

	return ((make_partition(k, n - k)) + (make_partition(k - 1, n))); 
}
/**@brief Writing Partition to a File

Creates a file named Partitions.txt that the results of the make_partition function is inputted to.

@param m is the user-inputted number that gets sent to the make_partition function.
@return Returns nothing.
*/
void Partitions::sendtofile(int m)
{
	std::ofstream outputData("Partition.txt"); 
	
	std::cout << "Creating Partition.txt file ... "; 

	for (size_t i = 1; i <= m; i++) //row
	{
		for (size_t l = 1; l <= m; l++) //column
		{
			outputData << make_partition(i, l) << " ";
		}
		outputData << std::endl; 
	}
	outputData.close(); 

	std::cout << "Done." << std::endl; 
}


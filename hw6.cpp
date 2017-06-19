/** @file main.cpp
@brief Creates different text files that return solutions to different recursive problems.
@author Lisa Chiang
@date February 17, 2017

Allows user to input a number that will be used in calculating the solutions to a Partitions formula, 
Stirling1 formula, Stirling2 formula, and Factorials formula. The solutions are reformatted
into a text file so that the user will find the solutions in 4 separate text files. 
*/

#include <iostream>
#include <vector>
#include <fstream>
#include "Partitions.h"
#include "Stirling1.h"
#include "Stirling2.h"
#include "Integer.h"
#include "Factorials.h"

int main()
{
	int m; 
	
	std::cout << "Welcome!  Please input a number m: "; 
	std::cin >> m; 
	std::cout << std::endl << std::endl; 

	//Calculating the Partitions and sending it to the file 
	Partitions A = m; 
	A.sendtofile(m); 

	//Calculating the Stirling1 and sending it to the file 
	Stirling1 B = m; 
	B.sendtofile(m); 

	//Calculating the Stirling2 and sending it to the file 
	Stirling2 C = m;
	C.sendtofile(m);

	//Calculating the Factorials and sending it to the file 
	Factorials D = m; 
	D.sendtofile(m); 
	
	return 0; 
}
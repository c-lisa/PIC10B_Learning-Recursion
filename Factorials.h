/** @file Factorials.h
@brief Contains the class declarations for the Factorials class.
@author Lisa Chiang
@date February 17, 2015

Factorials allows the user to create a table of calculations of factorials. 
*/

#ifndef Factorials_h
#define Factorials_h

#include "Integer.h"
#include <iostream>
#include <fstream>

class Factorials {
public:
	Factorials();
	Factorials(int n_input);
	double solving_factorial(double n_input); //the magical function that solves a single factorial
	void sendtofile(int m); //outputting the results to the text file 

private:
	int n;
	//Integer n2; 
};

#endif

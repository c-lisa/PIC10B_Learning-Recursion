/** @file Stirling1.h
@brief Contains the class declarations for the Stirling1 class.
@author Lisa Chiang
@date February 17, 2015

Stirling1 allows the user to create a table of calculations of Stirling1.
*/

#ifndef Stirling1_h
#define Stirling1_h

#include <fstream>
#include <iostream>

class Stirling1 {
public:
	Stirling1();
	Stirling1(int m_input);
	int make_Stirling1(int k, int n); //the magical function that solves a Stirling1 funtion
	void sendtofile(int m); //outputting the results to the text file

private:
	int x, y;

};

#endif

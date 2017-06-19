/** @file Stirling2.h
@brief Contains the class declarations for the Stirling2 class.
@author Lisa Chiang
@date February 17, 2015

Stirling2 allows the user to create a table of calculations of Stirling2.
*/

#ifndef Stirling2_h
#define Stirling2_h

#include <fstream>
#include <iostream>

class Stirling2 {
public:
	Stirling2();
	Stirling2(int m_input);
	int make_Stirling2(int k, int n); //the magical function that solves a Stirling2 funtion
	void sendtofile(int m); //outputting the results to the text file

private:
	int x, y;
};

#endif
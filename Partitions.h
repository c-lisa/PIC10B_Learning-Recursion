/** @file Partitions.h
@brief Contains the class declarations for the Partitions class.
@author Lisa Chiang
@date February 17, 2015

Partitions allows the user to create a table of calculations of Partitions.
*/

#ifndef Partitions_h
#define Partitions_h

#include <fstream>
#include <iostream>

class Partitions {
public:
	Partitions();
	Partitions(int m_input);
	int make_partition(int k, int n); //the magical function that solves a partitions funtion
	void sendtofile(int m); //outputting the results to the text file

private:
	int x, y;  
};

#endif
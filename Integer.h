#ifndef Integer_h
#define Integer_h

#include <vector>

/**@class Integer
@brief Class to convert, manipulate, and compare unsigned integers and vectors of bits.

This class allows the user to maniuplate unsigned integers and vectors that contain
bits stored as boolean variables. There are functions that allow the user to convert
from one to another and also manipulate both types of variables using arithmetic
functions, comparisons, etc. between Integers.
*/
class Integer {
public:
	//Constructors
	Integer();
	Integer(unsigned int a);

	//Mutators
	void print_as_bits(); //uses testnumberbits and inttoboolbit 	
	int testnumberbits(unsigned int number); //takes number and gives number of bits
	void inttoboolbit(unsigned int number, std::vector<bool> &bits); //uses testnumberbits to convert numbers into boolean bits
	void n_intoboolbit(unsigned int number, std::vector<bool> &bits); //uses testnumberbits to convert NEGATIVE numbers into boolean  bits

																	  //Overloading operators
	Integer& operator += (const Integer& rhs); //lhs = lhs + rhs
	Integer& operator -= (const Integer& rhs); //lhs = lhs - rhs
	Integer& operator *= (const Integer&rhs); //lhs = lhs*rhs
	Integer& operator &= (const Integer&rhs); //andequals
	Integer& operator |= (const Integer&rhs); //orequals
	Integer& operator ^= (const Integer&rhs); //XOR
	Integer& operator <<= (int number); //bitshift left
	Integer& operator >>= (int number); //bitshift right

	Integer& operator ++ (); //++a
	Integer operator++ (int unused); //a++
	Integer& operator -- (); //--a
	Integer operator-- (int unused); //a--

	Integer operator+ () const; //flipping to positive
	Integer operator- () const; //flipping to negative 
	Integer operator ~ () const; //negation

								 //Overloading mod operators
	bool operator> (Integer rhs);
	bool operator< (Integer rhs);
	bool Integer::operator== (Integer rhs);
	bool Integer::operator<= (Integer rhs);
	bool Integer::operator>= (Integer rhs);
	bool Integer::operator!= (Integer rhs);

	//Accessors
	unsigned int getx() const; //accesses x for Integers
	bool getsign() const; //accesses sign for Integers
	void print_as_int() const; //prints the result as an integer

private:
	std::vector<bool> bit;
	bool sign;
	unsigned int x;
};

//Non-Member Function declarations
Integer operator+(Integer lhs, const Integer& rhs); //adds any two Intgers
Integer operator*(Integer lhs, const Integer& rhs); //multiplies any two Integers
Integer operator-(Integer lhs, const Integer& rhs); //subracts any two Integers
Integer operator& (Integer lhs, const Integer& rhs); //copies a bit to the result if it exists in both operands
Integer operator| (Integer lhs, const Integer& rhs); //copies a bit if it exists in either operand
Integer operator^ (Integer lhs, const Integer& rhs); //copies the bit if it is set in one operand but not both
Integer operator<< (Integer lhs, int number); //left operands value is moved left by the number of bits specified by the right operand
Integer operator >> (Integer lhs, int number); //left operands value is moved right by the number of bits specified by the right operand
unsigned int backtoint(std::vector<int> &binaryint, bool signedbit); //turns Integers back to ints

#endif
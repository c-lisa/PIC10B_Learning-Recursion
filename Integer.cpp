#include "Integer.h"
#include <vector>
#include <iostream>

//Integers::Constructors
/**@brief Default Constructor

Creates a 0 vector by setting private variable x to 0.

@param No parameters.
@return Does not return anything.
*/
Integer::Integer()
{
	x = 0;
}
/**@brief Constructor

Sets private variable x to a.

@param a is the value that x is set to.
@return Does not return anything.
*/
Integer::Integer(unsigned int a)
{
	x = a;
	inttoboolbit(x, bit); 
}

//Integers::Mutators
/**@brief Prints result as binary bits.

Uses functions testnumberbits and intotoboolbit to convert
integers into binary bits (0 or 1) and outputs them in the
following format: (#,#,#,...#)_2.

@param No parameters.
@return Does not return anything.
*/
void Integer::print_as_bits()
{
	//Tests for number of bits that will be used
	int size = testnumberbits(x);
	//Converts the private variable x into a vector of boolean variables
	inttoboolbit(x, bit);

	//Checking if number is negative or positive
	if (sign)
	{
		std::cout << "-";
	}
	else
	{
		std::cout << " ";
	}

	//Formatting
	std::cout << "(";

	//Converts boolean variables to binary numbers
	for (int i = 0; i < size; i++)
	{
		//If false, output 0
		if (!bit[i])
		{
			std::cout << "0";
		}
		//If true, output 1
		else if (bit[i])
		{
			std::cout << "1";
		}
	}
	//Formatting
	std::cout << ")_2";
}
/**@brief Testing Number of Bits

Performs basic arithmetic using powers of 2 in order to calculate how many
bits a given number will require. This is used to create an ending condition
for for loops in other functions as well as initializing and resizing vectors.

@param number is the integer that will be used to calculate the number of bits needed.
@return Returns an integer that is the number of bits.
*/
int Integer::testnumberbits(unsigned int number)
{
	//Counter for number of bits that will be returned
	int bitnumber = 0;

	int b = getx();

	//Turning number positive to count bits
	if (b < 0)
	{
		b *= -1;
	}

	//Making sure the given number is not 0 
	if (b != 0)
	{
		//Keep running for loop until pow(2,a) is just less than given number
		for (int a = 0; a < b; a++)
		{
			if (pow(2, a) < b || pow(2, a) == b)
			{
				bitnumber++;
			}
		}
	}
	//If the number is equal to 0, allocate one more bit space
	else if (b == 0)
	{
		bitnumber = 1;
	}

	return bitnumber;
}
/**@brief Converting integers into boolean values in vector.

Uses testnumberbits function to convert integers into boolean values. These
boolean values are pushed into the vector linked to the private variable. Also
accounts for positive or negative number by changing private variable sign.

@param number is the number that will be converted into boolean values.
@param bits is the vector that contains the boolean values.
@return Does not return anything.
*/
void Integer::inttoboolbit(unsigned int number, std::vector<bool> &bits)
{
	//Resizes variable in case values already exist in vector, thus skewing summation and multiplication. 
	bit.resize(0);

	//Creating dummy variables to prevent private variables from being changed. 
	int a = testnumberbits(number); //size
	int b = number; //number given

					//Testing if number is positive or negative
	if (b >= 0)
	{
		sign = false;
	}
	else if (b < 0)
	{
		sign = true;
		b *= -1;
	}

	//Enter loop if the number (b) given is greater than 0. 
	while (b > 0)
	{
		//If the pow(2,numberbits) is less than or equal to the given number, continue here. 
		if (pow(2, (a - 1)) <= b)
		{
			//Push back true. 
			bits.push_back(true);
			//Subtract power of 0 from given number (b). 
			b -= pow(2, (a - 1));
			//Decrease number of bits left to give values to. 
			a--;
		}
		//If pow(2,numberbits) is not less than or equal to given number, continue here.
		else
		{
			//Push back false. 
			bits.push_back(false);
			//Decrease number of bits left to give values to. 
			a--;
		}
	}
	//If the number of bits left is still greater than 0
	if (a > 0)
	{
		//For every bit left, push back false. 
		for (int i = 0; i < a; i++)
		{
			bits.push_back(false);
		}
	}
}
/**@brief Converting negative integers into boolean values in vector.

Uses testnumberbits function to convert integers into boolean values. These
boolean values are pushed into the vector linked to the private variable. Also
accounts for positive or negative number by changing private variable sign.

@param number is the number that will be converted into boolean values.
@param bits is the vector that contains the boolean values.
@return Does not return anything.
*/
void Integer::n_intoboolbit(unsigned int number, std::vector<bool> &bits)
{
	//Resizes variable in case values already exist in vector, thus skewing summation and multiplication. 
	bit.resize(0);
	//Number is assumed to be negative
	sign = true;

	//Creating dummy variables to prevent private variables from being changed. 
	int a = testnumberbits(number); //size
	int b = number;

	//Enter loop if the number (b) given is greater than 0. 
	while (b > 0)
	{
		//If the pow(2,numberbits) is less than or equal to the given number, continue here. 
		if (pow(2, (a - 1)) <= b)
		{
			//Push back true. 
			bits.push_back(true);
			//Subtract power of 0 from given number (b). 
			b -= pow(2, (a - 1));
			//Decrease number of bits left to give values to. 
			a--;
		}
		//If pow(2,numberbits) is not less than or equal to given number, continue here.
		else
		{
			//Push back false. 
			bits.push_back(false);
			//Decrease number of bits left to give values to. 
			a--;
		}
	}
	//If the number of bits left is still greater than 0
	if (a > 0)
	{
		//For every bit left, push back false. 
		for (int i = 0; i < a; i++)
		{
			bits.push_back(false);
		}
	}

}
/**@brief Converts binary integers to unsigned integers

Performs calculations on a vector of binary integers (0 or 1) and converts sum of
calcutions into an unsigned integer.

@param binaryint is a vector of binary integers that will be converted into an unsigned integer.
@return Returns an unsigned integer that is equal to value of the binary integers.
*/
unsigned int backtoint(std::vector<int> &binaryint, bool signedbit)
{
	//Creates dummy variable for size of integer - 1
	int a = binaryint.size() - 1;
	//Initializes sum to 0
	int sum = 0;
	//Runs for loop from vector[size] to vector[0]
	for (int i = a; i >= 0; i--)
	{
		if (binaryint[i] == 1)
		{
			//sum = sum + pow(2,(size-currentiteration)
			sum += pow(2, (a - i));
		}
		else if (binaryint[i] == 0)
		{
			sum += 0;
		}
	}

	if (signedbit)
	{
		return sum*(-1);
	}
	else if (!signedbit)
	{
		return sum;
	}
}

/**@brief Overloading the += operator

Overloads the += operator using the + operator so that Integers
can be added using += symbol. The implicit (lhs) is now equal to lhs + rhs.

@param rhs is the Integer that will be added to implicit Integer (lhs).
@return Returns an Inteer that is equal to the new value of lhs.
*/
Integer&  Integer::operator += (const Integer& rhs)
{
	x = ((*this + rhs)).getx();
	return (*this + rhs);
}
/**@brief Overloading the -= operator

Overloads the -= operator using the - operator so that Integers
can be added using -= symbol. The implicit (lhs) is now equal to lhs - rhs.

@param rhs is the Integer that will be subtracted from implicit Integer (lhs).
@return Returns an Integer that is equal to the new value of lhs.
*/
Integer&  Integer::operator -= (const Integer& rhs)
{
	x = ((*this - rhs)).getx();
	return ((*this - rhs));
}
/**@brief Overloading the *= operator

Overloads the *= operator using the * operator so that Integers
can be added using *= symbol. The implicit (lhs) is now equal to lhs * rhs.

@param rhs is the Integer that will be multiplied to implicit Integer (lhs).
@return Returns an Integer that is equal to the new value of lhs.
*/
Integer&  Integer::operator *= (const Integer&rhs)
{
	x = ((*this * rhs)).getx();
	return ((*this * rhs));
}
/**@brief Overloading the &= operator

Overloads the &= operator using the & operator. A bit is copied to the
returned Integer if if it exists in both operands.

@param rhs is the Integer that will be compared to implicit Integer (lhs).
@return Returns an Integer that consists of bits that exist in both operands.
*/
Integer& Integer::operator &= (const Integer&rhs)
{
	x = (*this & rhs).getx();
	return (*this & rhs);
}
/**@brief Overloading the |= operator

Overloads the |= operator using the | operator. A bit is copied to the
returned Integer if if it exists in either operand.

@param rhs is the Integer that will be compared to implicit Integer (lhs).
@return Returns an Integer that consists of bits that exist in either operand.
*/
Integer& Integer::operator |= (const Integer&rhs)
{
	x = (*this | rhs).getx();
	return (*this | rhs);
}
/**@brief Overloading the ^= operator

Overloads the ^= operator using the ^ operator. A bit is copied to the
returned Integer if it exists in one operand but not the other.

@param rhs is the Integer that will be compared to implicit Integer (lhs).
@return Returns an Integer that consists of bits that exist in one operand but not the other.
*/
Integer& Integer::operator ^= (const Integer&rhs)
{
	x = (*this ^ rhs).getx();
	return (*this ^ rhs);
}
/**@brief Overloading the <<= operator

Overloads the <<= operator using the << operator. Left operand's value is moved
left by the number of bits specified by right hand.

@param number is how many bits the implicit (lhs) is shifted over.
@return Returns an Integer that has been shifted by number.
*/
Integer& Integer::operator <<= (int number)
{
	x = (*this << number).getx();
	return (*this << number);
}
/**@brief Overloading the >>= operator

Overloads the >>= operator using the >> operator. Left operand's value is moved
right by the number of bits specified by right hand.

@param number is how many bits the implicit (lhs) is shifted over.
@return Returns an Integer that has been shifted by number.
*/
Integer& Integer::operator >>= (int number)
{
	x = (*this >> number).getx();
	return (*this >> number);
}

/**@brief Prefix-incrementing x

Overloads the x++ operator using the += operator so that Integers
can be incremented by 1 and then returned.

@param No parameters.
@return Returns an integer that has been incremented by 1.
*/
Integer& Integer::operator ++ ()
{
	x += 1;
	return *this;
}
/**@brief Post-fix incrementing x

Overloads the ++x operator using the ++ operator so that Integers can be
returned and then incremented by 1.

@param No parameters.
@return Returns given integer.
*/
Integer Integer::operator++ (int unused)
{
	Integer clone(*this); //making copy
	++(*this);
	return clone;
}
/**@brief Prefix-deccrementing x

Overloads the x-- operator using the -= operator so that Integers
can be decremented by 1 and then returned.

@param No parameters.
@return Returns an integer that has been decremented by 1.
*/
Integer& Integer::operator -- ()
{
	x -= 1;
	return *this;
}
/**@brief Post-fix decrementing x

Overloads the --x operator using the -- operator so that Integers can be
returned and then decremented by 1.

@param No parameters.
@return Returns given integer.
*/
Integer Integer::operator-- (int unused)
{
	Integer clone(*this); //making copy
	--(*this);
	return clone;
}

//Overloading operators
/**@brief Overloading the + unary operator

Overloads the + unary operator so that Integers can be flipped. A positive Integer will
still be positive but a negative Integer will be negative.

@param No parameters
@return Returns an Integer that is equal to (1)*(lhs).
*/
Integer Integer::operator+ () const
{
	Integer returnthis = *this;

	returnthis.sign = false;

	return returnthis;
}
/**@brief Overloading the - unary operator

Overloads the - unary operator so that Integers can be flipped. A positive Integer will
still be negative but a negative Integer will be positive.

@param No parameters
@return Returns an Integer that is equal to (-1)*(lhs).
*/
Integer Integer::operator- () const
{
	Integer returnthis = *this;

	bool sign2;
	if (returnthis.sign)
	{
		sign2 = false;
	}
	else
	{
		sign2 = true;
	}

	std::vector <int> second;

	for (int i = 0; i < returnthis.bit.size(); i++)
	{
		if (returnthis.bit[i])
		{
			second.push_back(1);
		}
		else
			second.push_back(0);
	}

	Integer returnthis2 = backtoint(second, sign2);
	returnthis2.sign = sign2;

	return returnthis2;
}
/**@brief Overloading the ~ unary operator

Overloads the ~ unary operator so that all the bits of the
Integer are flipped.

@param No parameters
@return Returns an Integer that has flipped bits.
*/
Integer Integer::operator ~ () const
{
	Integer returnthis = *this;

	std::vector <bool> temp;
	std::vector <bool> temp2;
	//Temp is filled with bit members
	for (int i = 0; i < returnthis.bit.size(); i++)
	{
		temp.push_back(returnthis.bit[i]);
	}

	//Need to flip bits
	for (int i = 0; i < temp.size(); i++)
	{
		if (temp[i])
		{
			temp2.push_back(false);
		}
		else
		{
			temp2.push_back(true);
		}
	}

	//Erase zeroes in front
	while (temp2[0] == false)
	{
		temp2.erase(temp2.begin());
	}

	bool newsign;

	//Flipping sign
	if (returnthis.sign)
	{
		newsign = false;
	}
	else
	{
		newsign = true;
	}

	std::vector<int> convert;
	for (int i = 0; i < temp2.size(); i++)
	{
		if (temp2[i])
		{
			convert.push_back(1);
		}
		else
		{
			convert.push_back(0);
		}
	}

	returnthis = backtoint(convert, newsign);

	returnthis.sign = newsign;

	return returnthis;
}

//Integers::Accessors
/**@brief Accessor for x

Accesses unsigned integer x for Integer class.

@param There are no parameters.
@return Returns private variable x.
*/
unsigned int Integer::getx() const
{
	return x;
}
/**@brief Printing the Integer

Prints private variable x (unsigned integer)

@param No parameters.
@return Does not return anything.
*/
void Integer::print_as_int() const
{
	std::cout << x;
}
/**@brief Accessing the sign

Returns false (0 = positive) or true (1 = negative) for Integer.

@param No parameters.
@return Returns a bool.
*/
bool Integer::getsign() const
{
	return sign;
}

//Integers::Overloading mod operators
/**@brief Overloading > operator

Determines whether implicit Integer (lhs) is greater than given Integer (rhs) by
checking for equal number of bits and by converting both Integers into vectors of
boolean values and checking for differences between the two vectors.

@param rhs is the given Integer that will be compared against implicit Integer (lhs).
@return Returns true if implicit Integer is greater than given Integer and otherwise false.
*/
bool Integer::operator> (Integer rhs) //lhs > rhs
{
	//If lhs is positive and rhs is negative; lhs > rhs TRUE
	if ((!getsign()) && rhs.getsign())
	{
		return true;
	}
	//If rhs is positive and lhs is negative; rhs > lhs FALSE
	else if (!rhs.getsign() && getsign())
	{
		return false;
	}
	//If both are positive 
	else if ((!getsign()) && (!rhs.getsign()))
	{
		//Checks if number of bits are the same
		//If lhs has more bits than rhs, return true
		if (testnumberbits(getx()) > (rhs.bit.size()))
		{
			return true;
		}
		//If rhs has more bits than lhs, return false
		else if (testnumberbits(getx()) < (rhs.bit.size()))
		{
			return false;
		}
		//If rhs and lhs have same amount of bits
		else
		{
			std::vector <bool> lhs1;
			std::vector <bool> rhs2;

			//Convert both Integers into vector of boolean values
			inttoboolbit(getx(), lhs1);
			inttoboolbit(rhs.getx(), rhs2);

			//Find size of both vectors
			int size = lhs1.size();

			//Continue in loop to check entire size of vector
			for (int i = 0; i < size; i++)
			{
				//If value in vector of lhs is 1 and value in vector of rhs is 0, lhs > rhs, return true. 
				if (lhs1[i] && !rhs2[i])
				{
					return true;
				}
				//If value in vector of lhs is 0 and value in vector of rhs is 1, lhs < rhs, return false. 
				else if (!lhs1[i] && rhs2[i])
				{
					return false;
				}
				else return false;
			}
		}
	}
	//If both are negative
	else if ((getsign()) && (rhs.getsign()))
	{
		//Checks if number of bits are the same
		//If lhs has more bits than rhs, return true
		if (testnumberbits(getx()) > (rhs.bit.size()))
		{
			return false;
		}
		//If rhs has more bits than lhs, return false
		else if (testnumberbits(getx()) < (rhs.bit.size()))
		{
			return true;
		}
		//If rhs and lhs have same amount of bits
		else
		{
			std::vector <bool> lhs2;
			std::vector <bool> rhs3;

			//Convert both Integers into vector of boolean values
			inttoboolbit(getx()*-1, lhs2);
			inttoboolbit(rhs.getx()*-1, rhs3);

			//Find size of both vectors
			int size = lhs2.size();

			sign = true;

			//Continue in loop to check entire size of vector
			for (int i = 0; i < size; i++)
			{
				//If value in vector of lhs is 1 and value in vector of rhs is 0, lhs > rhs, return true. 
				if (lhs2[i] && !rhs3[i])
				{
					return false;
				}
				//If value in vector of lhs is 0 and value in vector of rhs is 1, lhs < rhs, return false. 
				else if (!lhs2[i] && rhs3[i])
				{
					return true;
				}
				else
				{
					return false;
				}
			}

		}

	}
	else return false;
}
/**@brief Overloading < operator

Determines whether implicit Integer (lhs) is greater than given Integer (rhs) by
checking for equal number of bits and by converting both Integers into vectors of
boolean values and checking for differences between the two vectors.

@param rhs is the given Integer that will be compared against implicit Integer (lhs).
@return Returns true if implicit Integer is less than given Integer and otherwise false.
*/
bool Integer::operator< (Integer rhs)
{
	//If lhs is positive and rhs is negative; lhs > rhs TRUE
	if (!getsign() && rhs.getsign())
	{
		return false;
	}
	//If rhs is positive and lhs is negative; rhs > lhs FALSE
	else if (!rhs.getsign() && getsign())
	{
		return true;
	}
	//If both are positive 
	else if ((!getsign()) && (!rhs.getsign()))
	{
		//Checks if number of bits are the same
		//If lhs has more bits than rhs, return true
		if (testnumberbits(getx()) > (rhs.bit.size()))
		{
			return false;
		}
		//If rhs has more bits than lhs, return false
		else if (testnumberbits(getx()) < (rhs.bit.size()))
		{
			return true;
		}
		//If rhs and lhs have same amount of bits
		else
		{
			std::vector <bool> lhs1;
			std::vector <bool> rhs2;

			//Convert both Integers into vector of boolean values
			inttoboolbit(getx(), lhs1);
			inttoboolbit(rhs.getx(), rhs2);

			//Find size of both vectors
			int size = lhs1.size();

			//Continue in loop to check entire size of vector
			for (int i = 0; i < size; i++)
			{
				//If value in vector of lhs is 1 and value in vector of rhs is 0, lhs > rhs, return true. 
				if (lhs1[i] && !rhs2[i])
				{
					return false;
				}
				//If value in vector of lhs is 0 and value in vector of rhs is 1, lhs < rhs, return false. 
				else if (!lhs1[i] && rhs2[i])
				{
					return true;
				}
				else return false;
			}
		}
	}
	//If both are negative
	else if ((getsign()) && (rhs.getsign()))
	{
		//Checks if number of bits are the same
		//If lhs has more bits than rhs, return true
		if (testnumberbits(getx()) > (rhs.bit.size()))
		{
			return true;
		}
		//If rhs has more bits than lhs, return false
		else if (testnumberbits(getx()) < (rhs.bit.size()))
		{
			return false;
		}
		//If rhs and lhs have same amount of bits
		else
		{
			std::vector <bool> lhs1;
			std::vector <bool> rhs2;

			unsigned int a, b;
			a = getx()*(-1);
			b = rhs.getx()*(-1);

			//Convert both Integers into vector of boolean values
			inttoboolbit(a, lhs1);
			inttoboolbit(b, rhs2);

			sign = true;

			//Find size of both vectors
			int size = lhs1.size();

			//Continue in loop to check entire size of vector
			for (int i = 0; i < size; i++)
			{
				//If value in vector of lhs is 1 and value in vector of rhs is 0, lhs > rhs, return true. 
				if (lhs1[i] && !rhs2[i])
				{
					return true;
				}
				//If value in vector of lhs is 0 and value in vector of rhs is 1, lhs < rhs, return false. 
				else if (!lhs1[i] && rhs2[i])
				{

					return false;
				}
				else return false;
			}
		}

	}
	else return false;
}
/**@brief Overloading == operator

Determines whether implicit Integer (lhs) is equal to given Integer (rhs) by checking if
both Integers are not greater than or less than each other.

@param rhs is the given Integer that will be compared against implicit Integer (lhs).
@return Returns true if implicit Integer is equal to given Integer and otherwise false.
*/
bool Integer::operator== (Integer rhs)
{
	//If lhs is not greater than rhs and lhs is not less than rhs, lhs and rhs must be equal
	if (!(*this > rhs) && !(*this < rhs))
	{
		return true;
	}
	//Otherwise, return false
	return false;
}
/**@brief Overloading <= operator

Determines whether implicit Integer (lhs) is less than or equal to given Integer (rhs)
by checking if the implicit Integer is equal to or less than given Integer.

@param rhs is the given Integer that will be compared against implicit Integer (lhs).
@return Returns true if implicit Integer is equal or less than given Integer and otherwise false.
*/
bool Integer::operator<= (Integer rhs)
{
	//If lhs is equal to or less than rhs, lhs is <= rhs
	if ((*this == rhs) || (*this < rhs))
		return true;
	//Otherwise, return false
	else return false;
}
/**@brief Overloading >= operator

Determines whether implicit Integer (lhs) is greater than or equal to given Integer (rhs)
by checking if the implicit Integer is equal to or greater than given Integer.

@param rhs is the given Integer that will be compared against implicit Integer (lhs).
@return Returns true if implicit Integer is equal or greater than given Integer and otherwise false.
*/
bool Integer::operator>= (Integer rhs)
{
	//If lhs is equal to or greater than rhs, return true
	if ((*this == rhs) || (*this > rhs))
		return true;
	//Otherwise, return false
	else return false;
}
/**@brief Overloading != operator

Determines whether implicit Integer (lhs) is not equal to given Integer (rhs)
by checking if the implicit Integer is greater than or less than the given Integer.

@param rhs is the given Integer that will be compared against implicit Integer (lhs).
@return Returns true if implicit Integer is not equal to the given Integer and otherwise false.
*/
bool Integer::operator!= (Integer rhs)
{
	//If lhs is not greater than rhs and not less than rhs, return false
	if (!(*this > rhs) && !(*this < rhs))
	{
		return false;
	}
	//Otherwise, return false
	return true;
}

//Non-Integer-class Functions
/**@brief Adding Integers

Converts Integers into boolean values and stores values in vectors. Vectors are
adjusted so that they contain the same number of bits. Boolean values are then
converted into binary numbers (0 or 1). Binary numbers are stored in another vector
and are added to form a final vector, which is reversed and converted back to an
Integer and returned.

@param lhs is one of the Integers that will be added.
@param rhs is the other Integer that will be added.
@return Returns an Integer that is the sum of lhs and rhs.
*/
Integer operator+ (Integer lhs, const Integer& rhs)
{
	int x = lhs.getx();
	int y = rhs.getx();
	std::vector<bool>lhsvector;
	Integer rhs2 = rhs; //creating copy of rhs since it cannot be changed
	std::vector<bool>rhsvector;

	//Turning number positive to count bits
	//Converting the two Integers into boolean values and storing them in vectors
	if (x < 0)
	{
		x *= -1;
		lhs.n_intoboolbit(x, lhsvector);
	}
	else if (x >= 0)
	{
		lhs.inttoboolbit(x, lhsvector);
	}


	if (y < 0)
	{
		y *= -1;
		rhs2.n_intoboolbit(y, rhsvector);
	}
	else if (y >= 0)
	{
		rhs2.inttoboolbit(y, rhsvector);
	}


	//Creating dummy variables for the sizes of the vectors
	int a = lhsvector.size();
	int b = rhsvector.size();

	//Adjusting sizes of vectors to be equal 
	//If size of lhs vector is bigger
	if (a > b)
	{
		//Add zeroes in front of rhs vector
		int addzeroes = a - b;
		for (int i = 0; i < addzeroes; i++)
		{
			rhsvector.insert(rhsvector.begin(), 0);

		}
	}

	//If size of rhs vector is bigger
	if (b > a)
	{
		//Add zeroes in front of lhs vector
		int addzeroes = b - a;
		for (int i = 0; i < addzeroes; i++)
		{
			lhsvector.insert(lhsvector.begin(), 0);
		}
	}

	//Creating vectors with binary code (0 or 1)
	std::vector<int>lhsbinary;
	std::vector<int>rhsbinary;

	//Changing rhsvector and lhsvector into binaries
	if (lhs.getsign())
	{
		std::vector<int> temp;

		//Need to flip bits
		for (int i = 0; i < (lhsvector.size()); i++)
		{
			if (lhsvector[i] == true)
			{
				temp.push_back(0);
			}
			else if (lhsvector[i] == false)
			{
				temp.push_back(1);
			}
		}

		//Add one
		std::vector<int>add_one;
		//Pushing back zeroes into add one
		for (int i = 0; i < (temp.size() - 1); i++)
		{
			add_one.push_back(0);
		}
		//Adding one at very end 
		add_one.push_back(1);

		//Creating carryover vector
		std::vector<int>carryover((add_one.size() + 1));
		//Filling carryover with zeroes to initialize
		for (int i = 0; i < carryover.size(); i++)
		{
			carryover[i] = 0;
		}

		//"Final" vector that will be reversed into bit vector
		std::vector<int>final;

		//Adding the three vectors (temp, add_one, carryover)
		for (int i = (add_one.size() - 1); i >= 0; i--)
		{
			//Temporary sum of three vectors at iteration i
			int sum = add_one[i] + temp[i] + carryover[i + 1];
			//If not last iteration of loop
			if (i != 0)
			{
				if (sum == 0)
				{
					final.push_back(0);
				}
				else if (sum == 1)
				{
					final.push_back(1);
				}
				else if (sum == 2)
				{
					final.push_back(0);
					carryover[i] = 1; //carryover one before because carryover has one extra space
				}
				else if (sum == 3)
				{
					final.push_back(1);
					carryover[i] = 1;  //carryover one before because carryover has one extra space
				}
			}
			//If last iteration of loop, have to take into account extra carryover
			else if (i == 0)
			{
				if (sum == 0)
				{
					final.push_back(0);
				}
				else if (sum == 1)
				{
					final.push_back(1);
				}
				else if (sum == 2)
				{
					final.push_back(0);
					final.push_back(1);
				}
				else if (sum == 3)
				{
					final.push_back(1);
					final.push_back(1);
				}
			}
		}

		//Reverse order of final vector and copy to bits
		for (int i = (final.size() - 1); i >= 0; i--)
		{
			lhsbinary.push_back(final[i]);
		}
	}
	else if (!lhs.getsign())
	{
		for (int i = 0; i < lhsvector.size(); i++) //number = 4
		{
			//If false, pushback 0
			if (!lhsvector[i])
			{
				lhsbinary.push_back(0);
			}
			//If truee, pushback 1
			else if (lhsvector[i])
			{
				lhsbinary.push_back(1);
			}
		}
	}

	if (rhs2.getsign())
	{
		std::vector<int> temp;

		//Need to flip bits
		for (int i = 0; i < (rhsvector.size()); i++)
		{
			if (rhsvector[i] == true)
			{
				temp.push_back(0);
			}
			else if (rhsvector[i] == false)
			{
				temp.push_back(1);
			}
		}

		//Add one
		std::vector<int>add_one;
		//Pushing back zeroes into add one
		for (int i = 0; i < (temp.size() - 1); i++)
		{
			add_one.push_back(0);
		}
		//Adding one at very end 
		add_one.push_back(1);

		//Creating carryover vector
		std::vector<int>carryover((add_one.size() + 1));
		//Filling carryover with zeroes to initialize
		for (int i = 0; i < carryover.size(); i++)
		{
			carryover[i] = 0;
		}

		//"Final" vector that will be reversed into bit vector
		std::vector<int>final;

		//Adding the three vectors (temp, add_one, carryover)
		for (int i = (add_one.size() - 1); i >= 0; i--)
		{
			//Temporary sum of three vectors at iteration i
			int sum = add_one[i] + temp[i] + carryover[i + 1];
			//If not last iteration of loop
			if (i != 0)
			{
				if (sum == 0)
				{
					final.push_back(0);
				}
				else if (sum == 1)
				{
					final.push_back(1);
				}
				else if (sum == 2)
				{
					final.push_back(0);
					carryover[i] = 1; //carryover one before because carryover has one extra space
				}
				else if (sum == 3)
				{
					final.push_back(1);
					carryover[i] = 1;  //carryover one before because carryover has one extra space
				}
			}
			//If last iteration of loop, have to take into account extra carryover
			else if (i == 0)
			{
				if (sum == 0)
				{
					final.push_back(0);
				}
				else if (sum == 1)
				{
					final.push_back(1);
				}
				else if (sum == 2)
				{
					final.push_back(0);
					final.push_back(1);
				}
				else if (sum == 3)
				{
					final.push_back(1);
					final.push_back(1);
				}
			}
		}

		//Reverse order of final vector and copy to bits
		for (int i = (final.size() - 1); i >= 0; i--)
		{
			rhsbinary.push_back(final[i]);
		}
	}
	else if (!rhs2.getsign())
	{
		for (int i = 0; i < rhsvector.size(); i++) //number = 4
		{
			//If false, pushback 0
			if (!rhsvector[i])
			{
				rhsbinary.push_back(0);
			}
			//If truee, pushback 1
			else if (rhsvector[i])
			{
				rhsbinary.push_back(1);
			}
		}
	}

	/*

	for (int i = 0; i < lhsbinary.size(); i++)
	{
	std::cout << lhsbinary[i];
	}
	std::cout << std::endl;

	for (int i = 0; i < rhsbinary.size(); i++)
	{
	std::cout << rhsbinary[i];
	}
	std::cout << std::endl;

	*/

	//Creating carryover vector
	std::vector<int>carryover(lhsvector.size() + 1);
	//Filling carryover with zeroes to initialize
	for (int i = 0; i < carryover.size(); i++)
	{
		carryover[i] = 0;
	}

	//Creating vector that will be sum of lhsbinary, rhsbinary, carryover
	std::vector<int>sumof3;

	//Adding the three vectors (lhsbinary, rhsbinary, carryover)
	for (int i = (lhsbinary.size() - 1); i >= 0; i--)
	{
		//Temporary sum of three vectors at iteration i
		int sum = lhsbinary[i] + rhsbinary[i] + carryover[i + 1];
		//If not last iteration of loop
		if (i != 0)
		{
			if (sum == 0)
			{
				sumof3.push_back(0);
			}
			else if (sum == 1)
			{
				sumof3.push_back(1);
			}
			else if (sum == 2)
			{
				sumof3.push_back(0);
				carryover[i] = 1; //carryover one before because carryover has one extra space
			}
			else if (sum == 3)
			{
				sumof3.push_back(1);
				carryover[i] = 1;  //carryover one before because carryover has one extra space
			}
		}
		//If last iteration of loop, have to take into account extra carryover
		else if (i == 0)
		{
			if ((!lhs.getsign()) && (!rhs2.getsign()))
			{
				if (sum == 0)
				{
					sumof3.push_back(0);
				}
				else if (sum == 1)
				{
					sumof3.push_back(1);
				}
				else if (sum == 2)
				{
					sumof3.push_back(0);
					sumof3.push_back(1);
				}
				else if (sum == 3)
				{
					sumof3.push_back(1);
					sumof3.push_back(1);
				}
			}
			else if ((lhs.getsign()) && (rhs2.getsign()))
			{
				if (sum == 0)
				{
					sumof3.push_back(0);
				}
				else if (sum == 1)
				{
					sumof3.push_back(1);
				}
				else if (sum == 2)
				{
					sumof3.push_back(0);
					sumof3.push_back(1);
				}
				else if (sum == 3)
				{
					sumof3.push_back(1);
					sumof3.push_back(1);
				}
			}
			else
			{
				if (sum == 0)
				{
					sumof3.push_back(0);
				}
				else if (sum == 1)
				{
					sumof3.push_back(1);
				}
				else if (sum == 2)
				{
					sumof3.push_back(0);
					//sumof3.push_back(1);
				}
				else if (sum == 3)
				{
					sumof3.push_back(1);
					//sumof3.push_back(1);
				}
			}
		}
	}

	//Reverse order of sumof3 vector and copy to final
	std::vector<int>final;
	for (int i = (sumof3.size() - 1); i >= 0; i--)
	{
		final.push_back(sumof3[i]);
	}

	//if lhs is negative && lhs > rhs2, then flip
	//if lhs and rhs2 are positive
	if ((!lhs.getsign()) && (!rhs2.getsign()))
	{
		bool sign = false;
		return backtoint(final, sign);
	}
	//if lhs and rhs2 are negative
	else if ((lhs.getsign()) && (rhs2.getsign()))
	{
		std::vector<int>reallyfinal;

		//flip bits and add 1
		std::vector<int> temp;

		//std::cout << "Hello";

		//Need to flip bits
		for (int i = 0; i < (final.size()); i++)
		{
			if (final[i] == 1)
			{
				temp.push_back(0);
			}
			else if (final[i] == 0)
			{
				temp.push_back(1);
			}
		}

		//std::cout << "Hello2";

		//Add one
		std::vector<int>add_one;
		//Pushing back zeroes into add one
		for (int i = 0; i < (temp.size() - 1); i++)
		{
			add_one.push_back(0);
		}
		//Adding one at very end 
		add_one.push_back(1);

		//std::cout << "Hello3";

		//Creating carryover vector
		std::vector<int>carryover((add_one.size() + 1));
		//Filling carryover with zeroes to initialize
		for (int i = 0; i < carryover.size(); i++)
		{
			carryover[i] = 0;
		}
		//std::cout << "Hello4";

		//"r_final" vector that will be reversed into reallyfinal vector
		std::vector<int>r_final;

		//Adding the three vectors (temp, add_one, carryover)
		for (int i = (add_one.size() - 1); i >= 0; i--)
		{
			//Temporary sum of three vectors at iteration i
			int sum = add_one[i] + temp[i] + carryover[i + 1];
			//If not last iteration of loop
			if (i != 0)
			{
				if (sum == 0)
				{
					r_final.push_back(0);
				}
				else if (sum == 1)
				{
					r_final.push_back(1);
				}
				else if (sum == 2)
				{
					r_final.push_back(0);
					carryover[i] = 1; //carryover one before because carryover has one extra space
				}
				else if (sum == 3)
				{
					r_final.push_back(1);
					carryover[i] = 1;  //carryover one before because carryover has one extra space
				}
			}
			//If last iteration of loop, have to take into account extra carryover
			else if (i == 0)
			{
				if (sum == 0)
				{
					r_final.push_back(0);
				}
				else if (sum == 1)
				{
					r_final.push_back(1);
				}
				else if (sum == 2)
				{
					r_final.push_back(0);
					r_final.push_back(1);
				}
				else if (sum == 3)
				{
					r_final.push_back(1);
					r_final.push_back(1);
				}
			}
		}
		//std::cout << "Hello5";

		r_final.push_back(1);

		//Reverse order of final vector and copy to bits
		for (int i = (r_final.size() - 1); i >= 0; i--)
		{
			reallyfinal.push_back(r_final[i]);
		}

		bool sign = true;
		//convert back to unsigned integer
		return backtoint(reallyfinal, sign);
	}

	//if lhs is positive and rhs2 is negative
	else if ((!lhs.getsign()) && (rhs2.getsign()))
	{
		if (x > y) //if +lhs > -rhs
		{
			bool sign = false;
			return backtoint(final, sign);
		}
		else if (y > x) //if negative is greater than positive
		{
			std::vector<int>reallyfinal;

			//flip bits and add 1
			std::vector<int> temp;

			//Need to flip bits
			for (int i = 0; i < (final.size()); i++)
			{
				if (final[i] == 1)
				{
					temp.push_back(0);
				}
				else if (final[i] == 0)
				{
					temp.push_back(1);
				}
			}
			//std::cout << "Hello1";

			//Add one
			std::vector<int>add_one;
			//Pushing back zeroes into add one
			for (int i = 0; i < (temp.size() - 1); i++)
			{
				add_one.push_back(0);
			}
			//Adding one at very end 
			add_one.push_back(1);

			//std::cout << "Hello2";

			//Creating carryover vector
			std::vector<int>carryover((add_one.size() + 1));
			//Filling carryover with zeroes to initialize
			for (int i = 0; i < carryover.size(); i++)
			{
				carryover[i] = 0;
			}


			//std::cout << "Hello3";


			//"r_final" vector that will be reversed into reallyfinal vector
			std::vector<int>r_final;

			//Adding the three vectors (temp, add_one, carryover)
			for (int i = (add_one.size() - 1); i >= 0; i--)
			{
				//Temporary sum of three vectors at iteration i
				int sum = add_one[i] + temp[i] + carryover[i + 1];
				//If not last iteration of loop
				if (i != 0)
				{
					if (sum == 0)
					{
						r_final.push_back(0);
					}
					else if (sum == 1)
					{
						r_final.push_back(1);
					}
					else if (sum == 2)
					{
						r_final.push_back(0);
						carryover[i] = 1; //carryover one before because carryover has one extra space
					}
					else if (sum == 3)
					{
						r_final.push_back(1);
						carryover[i] = 1;  //carryover one before because carryover has one extra space
					}
				}
				//If last iteration of loop, have to take into account extra carryover
				else if (i == 0)
				{
					if (sum == 0)
					{
						r_final.push_back(0);
					}
					else if (sum == 1)
					{
						r_final.push_back(1);
					}
					else if (sum == 2)
					{
						r_final.push_back(0);
						r_final.push_back(1);
					}
					else if (sum == 3)
					{
						r_final.push_back(1);
						r_final.push_back(1);
					}
				}
			}

			//std::cout << "Hello1";

			//Reverse order of final vector and copy to bits
			for (int i = (r_final.size() - 1); i >= 0; i--)
			{
				reallyfinal.push_back(r_final[i]);
			}

			bool sign = true;
			//convert back to unsigned integer
			return backtoint(reallyfinal, sign);
		}
		else
		{
			return 0;
		}
	}
	//if rhs2 is positive and lhs is negative
	else if ((lhs.getsign()) && (!rhs2.getsign()))
	{
		if (x > y) //if lhs > rhs
		{
			std::vector<int>reallyfinal;

			//flip bits and add 1
			std::vector<int> temp;

			//Need to flip bits
			for (int i = 0; i < (final.size()); i++)
			{
				if (final[i] == 1)
				{
					temp.push_back(0);
				}
				else if (final[i] == 0)
				{
					temp.push_back(1);
				}
			}

			//Add one
			std::vector<int>add_one;
			//Pushing back zeroes into add one
			for (int i = 0; i < (temp.size() - 1); i++)
			{
				add_one.push_back(0);
			}
			//Adding one at very end 
			add_one.push_back(1);

			//Creating carryover vector
			std::vector<int>carryover((add_one.size() + 1));
			//Filling carryover with zeroes to initialize
			for (int i = 0; i < carryover.size(); i++)
			{
				carryover[i] = 0;
			}

			//"r_final" vector that will be reversed into reallyfinal vector
			std::vector<int>r_final;

			//Adding the three vectors (temp, add_one, carryover)
			for (int i = (add_one.size() - 1); i >= 0; i--)
			{
				//Temporary sum of three vectors at iteration i
				int sum = add_one[i] + temp[i] + carryover[i + 1];
				//If not last iteration of loop
				if (i != 0)
				{
					if (sum == 0)
					{
						r_final.push_back(0);
					}
					else if (sum == 1)
					{
						r_final.push_back(1);
					}
					else if (sum == 2)
					{
						r_final.push_back(0);
						carryover[i] = 1; //carryover one before because carryover has one extra space
					}
					else if (sum == 3)
					{
						r_final.push_back(1);
						carryover[i] = 1;  //carryover one before because carryover has one extra space
					}
				}
				//If last iteration of loop, have to take into account extra carryover
				else if (i == 0)
				{
					if (sum == 0)
					{
						r_final.push_back(0);
					}
					else if (sum == 1)
					{
						r_final.push_back(1);
					}
					else if (sum == 2)
					{
						r_final.push_back(0);
						r_final.push_back(1);
					}
					else if (sum == 3)
					{
						r_final.push_back(1);
						r_final.push_back(1);
					}
				}
			}

			//Reverse order of final vector and copy to bits
			for (int i = (r_final.size() - 1); i >= 0; i--)
			{
				reallyfinal.push_back(r_final[i]);
			}

			bool sign = true;
			//convert back to unsigned integer
			return backtoint(reallyfinal, sign);
		}
		else if (y > x)
		{
			bool sign = false;
			return backtoint(final, sign);
		}
		else
		{
			return 0;
		}
	}
}
/**@brief Multiplying Integers

Converts Integers into boolean values and stores values in vectors. Vectors are
adjusted so that they contain the same number of bits. Boolean values are then
converted into binary numbers (0 or 1). Binary numbers are stored in another vector
and are multiplied to form a final vector, which is reversed and converted back to an
Integer and returned.

@param lhs is one of the Integers that will be multiplied.
@param rhs is the other Integer that will be multiplied.
@return Returns an Integer that is the product of lhs and rhs.
*/
Integer operator* (Integer lhs, const Integer& rhs)
{
	//Converting the two Integers into boolean values and storing them in vectors
	std::vector<bool>lhsvector;
	lhs.inttoboolbit(lhs.getx(), lhsvector);
	Integer rhs2 = rhs; //creating copy of rhs since it cannot be changed
	std::vector<bool>rhsvector;
	rhs2.inttoboolbit(rhs2.getx(), rhsvector);

	//Creating dummy variables for the sizes of the vectors
	int a = lhs.testnumberbits(lhs.getx());
	int b = rhs2.testnumberbits(rhs2.getx());

	//Adjusting sizes of vectors to be equal 
	//If size of lhs vector is bigger
	if (a > b)
	{
		//Add zeroes in front of rhs vector
		int addzeroes = a - b;
		for (int i = 0; i < addzeroes; i++)
		{
			rhsvector.insert(rhsvector.begin(), 0);

		}
	}
	//If size of rhs vector is bigger
	else
	{
		//Add zeroes in front of lhs vector
		int addzeroes = b - a;
		for (int i = 0; i < addzeroes; i++)
		{
			lhsvector.insert(lhsvector.begin(), 0);
		}
	}

	//Creating vectors with binary code (0 or 1)
	std::vector<int>lhsbinary;
	std::vector<int>rhsbinary;

	//Changing rhsvector and lhsvector into binaries
	for (int i = 0; i < lhsvector.size(); i++) //number = 4
	{
		//If false, pushback 0
		if (!lhsvector[i])
		{
			lhsbinary.push_back(0);
		}
		//If truee, pushback 1
		else if (lhsvector[i])
		{
			lhsbinary.push_back(1);
		}
	}
	for (int i = 0; i < rhsvector.size(); i++) //number = 4
	{
		//If false, pushback 0
		if (!rhsvector[i])
		{
			rhsbinary.push_back(0);
		}
		//If truee, pushback 1
		else if (rhsvector[i])
		{
			rhsbinary.push_back(1);
		}
	}

	//Creating variable for size of vectors
	int size = lhsvector.size() - 1;
	//Creating variable for sum of lines of products
	unsigned int sum = 0;
	//Counter for how many lines of multiplication done
	int counter = 0;

	for (int j = size; j >= 0; j--)
	{
		//Temporary vector that can have products pushed into it
		std::vector<int>temp;
		//If value of number is equal to 1
		if (rhsvector[j] == 1)
		{
			//Pushback the entire other number (because 1*that number = that number)
			for (int i = 0; i <= size; i++)
			{
				temp.push_back(lhsvector[i]);
			}
			//If the counter is not 0, then push back zeroes to account for line of addition
			for (int k = 0; k < counter; k++)
			{
				temp.push_back(0);
			}
		}
		//Sum = sum + conversion of temp vector into integer
		sum += backtoint(temp, true);
		//Increase counter to indicate line of addition
		counter++;
	}

	return sum;
}
/**@brief Subtracting Integers

Converts Integers into boolean values and stores values in vectors. Vectors are
adjusted so that they contain the same number of bits. Boolean values are then
converted into binary numbers (0 or 1). Binary numbers are stored in another vector
and are subtracted to form a final vector, which is reversed and converted back to an
Integer and returned.

@param lhs is one of the Integers that will be subtracted.
@param rhs is the other Integer that will be subtracted.
@return Returns an Integer that is the sum of lhs and rhs.
*/
Integer operator- (Integer lhs, const Integer& rhs)

{
	if (lhs.getx() == rhs.getx())
	{
		return 0;
	}
	Integer y = rhs.getx()*(-1);
	return (lhs + y);
}
/**@brief Binary AND Operator

Binary AND Operator copies a bit to the result if it exists in both operands.

@param lhs is one of the Integers that will be compared.
@param rhs is the other Integer that will be compared.
@return Returns an Integer that contains copies of bits if the result exists in both operands.
*/
Integer operator& (Integer lhs, const Integer& rhs) //copies a bit to the result if it exists in both operands
{
	std::vector<int> andequals;

	Integer rhs2 = rhs; //creating copy of rhs since it cannot be changed

						//Got value of x for lhs and rhs
	int x = lhs.getx();
	int y = rhs2.getx();

	//Created vectors to store the bit form of x
	std::vector<bool>lhsvector;
	std::vector<bool>rhsvector;

	//Turning number positive to count bits
	//Converting the two Integers into boolean values and storing them in vectors
	if (x < 0)
	{
		lhs.inttoboolbit(x, lhsvector);
	}
	else if (x >= 0)
	{
		lhs.inttoboolbit(x, lhsvector);
	}

	if (y < 0)
	{
		rhs2.inttoboolbit(x, rhsvector);
	}
	else if (y >= 0)
	{
		rhs2.inttoboolbit(y, rhsvector);
	}

	//Creating dummy variables for the sizes of the vectors
	int a = lhsvector.size();
	int b = rhsvector.size();

	//Adjusting sizes of vectors to be equal 
	//If size of lhs vector is bigger
	if (a > b)
	{
		//Add zeroes in front of rhs vector
		int addzeroes = a - b;
		for (int i = 0; i < addzeroes; i++)
		{
			rhsvector.insert(rhsvector.begin(), 0);
		}
	}
	//If size of rhs vector is bigger
	if (b > a)
	{
		//Add zeroes in front of lhs vector
		int addzeroes = b - a;
		for (int i = 0; i < addzeroes; i++)
		{
			lhsvector.insert(lhsvector.begin(), 0);
		}
	}


	//If both lhs[i] and rhs[i] are 1, then we can push back 1 into the vector. 
	//Otherwise, we push back 0. 
	for (int i = 0; i < lhsvector.size(); i++)
	{
		if ((lhsvector[i] == 1) && (rhsvector[i] == 1))
		{
			andequals.push_back(1);
		}
		else
		{
			andequals.push_back(0);
		}
	}

	//Returning a sign 
	bool j;

	//If lhs and rhs are negative (true) then it is negative
	if ((lhs.getsign()) && (rhs.getsign()))
	{
		j = true;
	}
	else
	{
		j = false;
	}

	/*
	for (int i = 0; i < andequals.size(); i++)
	{
	std::cout << andequals[i];
	}

	*/

	Integer returnthis = backtoint(andequals, j);

	return returnthis;
}
/**@brief Binary OR Operator

Binary OR Operator copies a bit if it exists in either operand.

@param lhs is one of the Integers that will be compared.
@param rhs is the other Integer that will be compared.
@return Returns an Integer that contains copies of bits if the result exists in either operand.
*/
Integer operator| (Integer lhs, const Integer& rhs) //copies a bit if it exists in either operand
{
	std::vector<int> andequals;

	//Got value of x for lhs and rhs
	int x = lhs.getx();
	int y = rhs.getx();

	//Created vectors to store the bit form of x
	std::vector<bool>lhsvector;
	std::vector<bool>rhsvector;

	Integer rhs2 = rhs; //creating copy of rhs since it cannot be changed

						//Turning number positive to count bits
						//Converting the two Integers into boolean values and storing them in vectors
	if (x < 0)
	{
		x *= -1;
		lhs.n_intoboolbit(x, lhsvector);
	}
	else if (x >= 0)
	{
		lhs.inttoboolbit(x, lhsvector);
	}
	if (y < 0)
	{
		y *= -1;
		rhs2.n_intoboolbit(y, rhsvector);
	}
	else if (y >= 0)
	{
		rhs2.inttoboolbit(y, rhsvector);
	}

	//Creating dummy variables for the sizes of the vectors
	int a = lhsvector.size();
	int b = rhsvector.size();

	//Adjusting sizes of vectors to be equal 
	//If size of lhs vector is bigger
	if (a > b)
	{
		//Add zeroes in front of rhs vector
		int addzeroes = a - b;
		for (int i = 0; i < addzeroes; i++)
		{
			rhsvector.insert(rhsvector.begin(), 0);

		}
	}
	//If size of rhs vector is bigger
	if (b > a)
	{
		//Add zeroes in front of lhs vector
		int addzeroes = b - a;
		for (int i = 0; i < addzeroes; i++)
		{
			lhsvector.insert(lhsvector.begin(), 0);
		}
	}

	//If either lhs[i] and rhs[i] are 1, then we can push back 1 into the vector. 
	//Otherwise, we push back 0. 
	for (int i = 0; i < lhsvector.size(); i++)
	{
		if ((lhsvector[i] == 1) || (rhsvector[i] == 1))
		{
			andequals.push_back(1);
		}
		else
		{
			andequals.push_back(0);
		}
	}

	//Returning a sign 
	bool j;

	//If either are negative or both are negative 
	if ((!lhs.getsign()) && (!rhs.getsign()))
	{
		j = false;
	}
	else
	{
		j = true;
	}

	return backtoint(andequals, j);
}
/**@brief Binary XOR Operator

Binary XOR Operator copies the bit if it is set in one operand but not both.

@param lhs is one of the Integers that will be compared.
@param rhs is the other Integer that will be compared.
@return Returns an Integer that contains copies of bits if the result exists one operand but not both.
*/
Integer operator^ (Integer lhs, const Integer& rhs) //copies the bit if it is set in one operand but not both
{
	std::vector<int> andequals;

	//Got value of x for lhs and rhs
	int x = lhs.getx();
	int y = rhs.getx();

	//Created vectors to store the bit form of x
	std::vector<bool>lhsvector;
	std::vector<bool>rhsvector;

	Integer rhs2 = rhs; //creating copy of rhs since it cannot be changed

						//Turning number positive to count bits
						//Converting the two Integers into boolean values and storing them in vectors
	if (x < 0)
	{
		x *= -1;
		lhs.n_intoboolbit(x, lhsvector);
	}
	else if (x >= 0)
	{
		lhs.inttoboolbit(x, lhsvector);
	}
	if (y < 0)
	{
		y *= -1;
		rhs2.n_intoboolbit(y, rhsvector);
	}
	else if (y >= 0)
	{
		rhs2.inttoboolbit(y, rhsvector);
	}

	//Creating dummy variables for the sizes of the vectors
	int a = lhsvector.size();
	int b = rhsvector.size();

	//Adjusting sizes of vectors to be equal 
	//If size of lhs vector is bigger
	if (a > b)
	{
		//Add zeroes in front of rhs vector
		int addzeroes = a - b;
		for (int i = 0; i < addzeroes; i++)
		{
			rhsvector.insert(rhsvector.begin(), 0);

		}
	}
	//If size of rhs vector is bigger
	if (b > a)
	{
		//Add zeroes in front of lhs vector
		int addzeroes = b - a;
		for (int i = 0; i < addzeroes; i++)
		{
			lhsvector.insert(lhsvector.begin(), 0);
		}
	}

	for (int i = 0; i < lhsvector.size(); i++)
	{
		if ((lhsvector[i] == 1) && (rhsvector[i] == 1))
		{
			andequals.push_back(0);
		}
		else
		{
			if ((lhsvector[i] == 1) || (rhsvector[i] == 1))
			{
				andequals.push_back(1);
			}
			else
			{
				andequals.push_back(0);
			}
		}
	}

	//Returning a sign 
	bool j;

	//If either lhs or rhs were negative
	if ((lhs.getsign()) && (rhs.getsign()))
	{
		j = false;
	}
	else if ((!lhs.getsign()) && (!rhs.getsign()))
	{
		j = false;
	}
	else
	{
		j = true;
	}

	return backtoint(andequals, j);
}
/**@brief Binary Left Shift Operator

The left operands value is moved left by the number of bits specified by the right operand.

@param lhs is one of the Integers that will be shifted
@param number is the amount lhs will be shifted by
@return Returns an Integer that  has been moved left by the number of bits specified by the right operand.
*/
Integer operator<<(Integer lhs, int number) //left operands value is moved left by the number of bits specified by the right operand
{
	std::vector<bool>lhsvector;
	std::vector<int>newvector;

	lhs.inttoboolbit(lhs.getx(), lhsvector);

	//shifting twice
	for (int i = 0; i < number; i++)
	{
		lhsvector.push_back(false);
	}
	//copying lhsvector into newvector
	for (int i = 0; i < lhsvector.size(); i++)
	{
		if (lhsvector[i])
		{
			newvector.push_back(1);
		}
		else if (!lhsvector[i])
		{
			newvector.push_back(0);
		}
	}

	//Returning a sign 
	bool j;

	//If either lhs was negative
	if ((lhs.getsign()))
	{
		j = true;
	}
	else
	{
		j = false;
	}

	return backtoint(newvector, j);
}
/**@brief Binary Right Shift Operator

The left operands value is moved right by the number of bits specified by the right operand.

@param lhs is one of the Integers that will be shifted
@param number is the amount lhs will be shifted by
@return Returns an Integer that  has been moved right by the number of bits specified by the right operand.
*/
Integer operator >> (Integer lhs, int number) //left operands value is moved right by the number of bits specified by the right operand
{
	std::vector<bool>lhsvector;
	std::vector<int>newvector;

	lhs.inttoboolbit(lhs.getx(), lhsvector);

	//shifting once
	for (int i = 0; i < number; i++)
	{
		lhsvector.pop_back();
	}
	//copying lhsvector into newvector
	for (int i = 0; i < lhsvector.size(); i++)
	{
		if (lhsvector[i])
		{
			newvector.push_back(1);
		}
		else if (!lhsvector[i])
		{
			newvector.push_back(0);
		}
	}

	//Returning a sign 
	bool j;

	//If either lhs was negative
	if ((lhs.getsign()))
	{
		j = true;
	}
	else
	{
		j = false;
	}

	return backtoint(newvector, j);
}
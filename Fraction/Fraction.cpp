#include<iostream>

class Fraction
{
	int integer;
	int numerator;
	int denominator;
public:
	int get_integer()const
	{
		return integer;
	}
	int get_numenator()const
	{
		return numerator;
	}
	int get_denomenator()const
	{
		return denominator;
	}
	void set_integer(int integer)
	{
		this->integer = integer;
	}
	void set_numerator(int numerator)
	{
		this->numerator = numerator;
	}
	void set_denominator(int denominator)
	{
		this->denominator = denominator;
	}

	Fraction()
	{
		this->integer = integer;
		this->numerator = numerator;
		this->denominator = denominator;
	}
	Fraction(const int integer, const int numerator, const int denomenator)
	{
		this->integer = integer;
		this->numerator = numerator;
		this->denominator = denomenator;
	}
	~Fraction()
	{

	}

	void print()
	{
		if (numerator == 0 & integer != 0)
		{
			std::cout << integer << std::endl;
		}
		if (integer == 0 & numerator != 0)
		{
			std::cout << numerator << "/" << denominator << std::endl;
		}
		if (integer != 0 & numerator != 0)
		{
			std::cout << integer << "(" << numerator << "/" << denominator <<  ")" << std::endl;
		}
		else
		{
			std::cout << 0 << std::endl;
		}
		std::cout << std::endl;
	}

Fraction& operator=(const Fraction& other)
{
	this->integer = other.integer;
	this->numerator = other.numerator;
	this->denominator = other.denominator;
	return *this;
}
Fraction& operator+( const Fraction& right)
{
	Fraction resalt;
	resalt.set_integer(this->integer + right.integer);
	resalt.set_numerator(this->numerator + right.numerator);
	resalt.set_denominator(this->denominator + right.denominator);
	return resalt;
}

Fraction& operator-(const Fraction& right)
{
	Fraction resalt;
	resalt.set_integer(this->integer - right.integer);
	resalt.set_numerator(this->numerator - right.numerator);
	resalt.set_denominator(this->denominator - right.denominator);
	return resalt;
}

Fraction& operator*(const Fraction& right)
{
	Fraction resalt;
	resalt.set_integer(this->integer * right.integer);
	resalt.set_numerator(this->numerator * right.numerator);
	resalt.set_denominator(this->denominator * right.denominator);
	return resalt;
}

Fraction& operator/(const Fraction& right)
{
	Fraction resalt;
	resalt.set_integer(this->integer / right.integer);
	resalt.set_numerator(this->numerator / right.numerator);
	resalt.set_denominator(this->denominator / right.denominator);
	return resalt;
}


};



void main()
{
	using namespace std;

	setlocale(LC_ALL, "");
	
	Fraction A, B;
	Fraction C(2, 3, 4);
	C.print();
	B = Fraction(3, 4, 5);
	B.print();
	A = B + C;
	A.print();
	A = A - B;
	A.print();
	A = B * C;
	A.print();
	A = A / B;
	A.print();
}
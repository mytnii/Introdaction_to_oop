#include<iostream>
using std::cin;
using std::cout;
using std::endl;

class Fraction;
Fraction operator*(Fraction left, Fraction right);

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
	int get_numerator()const
	{
		return numerator;
	}
	int get_denominator()const
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
		if (denominator == 0)
		{
			denominator = 1;
		}
		this->denominator = denominator;
	}

	Fraction(int integer, int numerator, int denomenator)
	{
		this->integer = integer;
		this->numerator = numerator;
		set_denominator(denomenator);
		cout << "Constructor\t" << this << endl;
	}
	Fraction()
	{
		this->integer = 0;
		this->numerator = 0;
		this->denominator = 1;
		cout << "DefaulConstructor:\t" << this << endl;
	}
	Fraction(int integer)
	{
		this->integer = integer;
		this->numerator = 0;
		this->denominator = 1;
		cout << "1agrConstructor:\t" << this << endl;
	}
	Fraction(int numerator, int denominator)
	{
		this->integer = 0;
		this->numerator = numerator;
		set_denominator(denominator);
		cout << "Constructor:\t" << this << endl;
	}


	~Fraction()
	{
		cout << "Destructor\t" << this << endl;
	}

	Fraction& to_improper()
	{
		numerator += integer * denominator;
		integer = 0;
		return *this;
	}

	Fraction& to_proper()
	{
		integer += numerator / denominator;
		numerator %= denominator;
		return *this;
	}

	/*void reduce()
	{
			if (denominator % numerator == 0)
			{
				denominator /= numerator;
				numerator /= numerator;
			}
			if (denominator % 2 == 0 & numerator % 2 == 0)
			{
				denominator /= 2;
				numerator /= 2;
			}
			else if (denominator % 3 == 0 & numerator % 3 == 0)
			{
				denominator /= 3;
				numerator /= 3;
			}
	}*/

	Fraction& reduce()
	{
		if (numerator == 0)
		{
			return *this;
		}
		int more, less;
		int rest;
		if (numerator > denominator)
		{
			more = numerator;
			less = denominator;
		}
		else
		{
			less = numerator;
			more = denominator;
		}
		do
		{
			rest = more % less;
			more = less;
			less = rest;
		} while (rest);

		int GCD = more;
		numerator /= GCD;
		denominator /= GCD;
		return *this;
	}
	Fraction inverted()
	{
		to_improper();
		return Fraction(this->denominator, this->numerator);
	}

	void print()const
	{
		if (integer)
		{
			cout << integer;
		}
		if (numerator)
		{

		if (integer)
		{
			cout << "(";
		}
			cout << numerator << "/" << denominator;
			if (integer)
			{
				cout << ")";
			}
		}
		else if (integer == 0)
		{
			cout << 0;
		}
		cout << endl;
	}

	Fraction& operator*=(const Fraction& other)
	{
		return *this = *this * other;
	}
};

Fraction operator*( Fraction left,  Fraction right)
{
	left.to_improper();
	right.to_improper();
	//Fraction result
	//	(
	//		left.get_numerator() * right.get_numerator(),
	//        left.get_denominator()* right.get_denominator()
	//	);
	//result.set_numerator(left.get_numerator() * right.get_numerator());
	//result.set_denominator(left.get_denominator() * right.get_denominator());

	/*result.to_proper();
	result.reduce();
	return result;*/
	return Fraction
	(
		left.get_numerator() * right.get_numerator(),
		left.get_denominator() * right.get_denominator()
	).to_proper().reduce();

}

Fraction operator/(Fraction left, Fraction right)
{
	//left.to_improper();
	//right.to_improper();

	//return Fraction
	//(
	//	left.get_numerator() * right.get_denominator(),
	//	left.get_denominator() * right.get_numerator()
	//).to_improper().reduce();
	return left * right.inverted();
}

//#define CONSTRUCTORS_CHECK

void main()
{
	setlocale(LC_ALL, "");
#ifdef CONSTRUCTOR_CHECK


	Fraction A;
	A.print();
	Fraction B = 5;
	B.print();
	//Fraction C(7);
	//C.print();
	//Fraction D{ 8 };
	//D.print();
	Fraction C(3, 4);
	C.print();
	Fraction D(2, 3, 4);
	D.print();
#endif

	Fraction A(2, 1, 2);
	Fraction B(3, 2, 5);
	//Fraction C = A * B;
	//C.print();
	//Fraction D(840, 3600);
	//D.reduce();
	//D.print();
	//C = A / B;
	//C.print();

	A *= B;
	A.print();
}
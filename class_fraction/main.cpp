#pragma warning (disable:4326)
#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<cstdlib>
#include<cstring>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

class Fraction;
Fraction operator*(Fraction left, Fraction right);
Fraction operator/(Fraction left, Fraction right);
Fraction operator+( Fraction left, Fraction right);
Fraction operator-(Fraction left, Fraction right);

bool operator<(Fraction left, Fraction right);
bool operator>(Fraction left, Fraction right);
bool operator==(Fraction left, Fraction right);
bool operator<=(Fraction left, Fraction right);
bool operator>=(Fraction left, Fraction right);
bool operator!=(Fraction left, Fraction right);





std::ostream& operator<<(std::ostream& out, const Fraction& other);

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
	Fraction(double decimal_fraction)
	{
		decimal_fraction += 1e-11;
		this->integer = decimal_fraction;
		decimal_fraction -= this->integer;
		this->denominator = 1e+9;
		this->numerator = decimal_fraction * this->denominator;
		reduce();
	}
	explicit Fraction(int integer)
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

	std::ostream& print(std::ostream& out)const
	{
		if (integer)
		{
			out << integer;
		}
		if (numerator)
		{

		if (integer)
		{
			out << "(";
		}
			out << numerator << "/" << denominator;
			if (integer)
			{
				out << ")";
			}
		}
		else if (integer == 0)
		{
			out << 0;
		}
		return out;
	}

	//void print( Fraction& other)
	//{
	//	if (*this < other)
	//	{
	//		cout << *this << " < " << other << endl;
	//	}
	//	if (*this > other)
	//	{
	//		cout << *this << " > " << other << endl;
	//	}
	//	if (*this == other)
	//	{
	//		cout << *this << " = " << other << endl;
	//	}
	//}

	Fraction& operator= (const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "CopyAssignment:\t" << this << endl;
		return *this;
	}

	Fraction& operator*=(const Fraction& other)
	{
		return *this = *this * other;
	}

	Fraction& operator/=(const Fraction& other)
	{
		return *this = *this / other;
	}

	Fraction& operator+=(const Fraction& other)
	{
		return *this = *this + other;
	}

	Fraction& operator-=(const Fraction& other)
	{
		return *this = *this - other;
	}

	       // Type - cast operators
	explicit operator int()const
	{
		return integer;
	}

	 explicit operator double()const
	{
		return integer + (double)numerator / denominator;
	}
	
};
	void print(Fraction& left, Fraction& right)
	{
		if (left <= right)
		{
			cout << left << " <= " << right << endl;
		}
		if (left >= right)
		{
			cout << left << " >= " << right << endl;
		}
		if (left != right)
		{
			cout << left << " Не равно " << right << endl;
		}
	}

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

Fraction operator+( Fraction left,  Fraction right)
{
	return Fraction
	(
		left.to_improper().get_numerator() * right.get_denominator() + 
		right.to_improper().get_numerator() * left.get_denominator(),
		left.get_denominator() * right.get_denominator()
	).to_proper().reduce();
}

Fraction operator-(Fraction left, Fraction right)
{
	return Fraction
	(
		left.to_improper().get_numerator() * right.get_denominator() -
		right.to_improper().get_numerator() * left.get_denominator(),
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

bool operator<(Fraction left, Fraction right)
{
	return left.to_improper().get_numerator() * right.get_denominator() <
		   right.to_improper().get_numerator() * left.get_denominator();
}

bool operator>(Fraction left, Fraction right)
{
	return left.to_improper().get_numerator() * right.get_denominator() >
		   right.to_improper().get_numerator() * left.get_denominator();
}

bool operator==(Fraction left, Fraction right)
{
	return left.to_improper().get_numerator() * right.get_denominator() ==
		   right.to_improper().get_numerator() * left.get_denominator();
}

bool operator<=(Fraction left, Fraction right)
{
	return !(left > right);
}

bool operator>=(Fraction left, Fraction right)
{
	return !(left < right);
}

bool operator!=(Fraction left, Fraction right)
{
	return !(left == right);
}




	 std::ostream& operator<<(std::ostream& out, const Fraction& other)
	{
		/* i*//*f (other.get_numerator() == 0 && other.get_integer() != 0)
		 {
			 out << other.get_integer();

			 return out;
		 }
		 else if (other.get_integer() != 0 && other.get_numerator() != 0)
		 {
			 out << other.get_integer() << "("
				 << other.get_numerator() << "/"
				 << other.get_denominator() << ")";

			 return out;
		 }
		 else
		 {
			 out << other.get_numerator() << "/"
				 << other.get_denominator();

			 return out;
		 }*/
		/* if (other.get_integer())
		 {
			 out << other.get_integer();
		 }
		 if (other.get_numerator())
		 {

			 if (other.get_integer())
			 {
				 out << "(";
			 }
			 out << other.get_numerator() << "/" << other.get_denominator();
			 if (other.get_integer())
			 {
				 out << ")";
			 }
		 }
		 else if (other.get_integer() == 0)
		 {
			 out << 0;
		 }

		 return out;*/

		 return other.print(out);
	}

	 std::istream& operator>>(std::istream& in, Fraction& other)
	 {

		 other = Fraction();

		 const int size = 100;
		 char buffer[size] = {};
		 char delimiter[] = " (/),.";
		 int counter;

		 do{
		 in.getline(buffer, size);
		 char* value[3] = {};
		 char point = '.';
		 bool presence_point = false;
		 int counter_decimal = 0;
		 counter = 0;

	
			 for (int i = 0; buffer[i]; i++)
			 {
				 if (buffer[i] == point)
				 {
					 presence_point = true;
					 for (int j = i + 1; buffer[j]; j++)
					 {
						 ++counter_decimal;
					 }

				 }
			 }

			 char* pch = strtok(buffer, delimiter);


			 //for (char* pch = strtok(buffer, delimiter); pch; pch = strtok(NULL, delimiter))
			 //{
				// value[counter++] = pch;
			 //}
			 while (pch)
			 {
				 value[counter++] = pch;
				 pch = strtok(NULL, delimiter);
			 }

			 if (presence_point && counter <= 2 )
			 {
				 other.set_integer(atoi(value[0]));
				 other.set_denominator(pow(10, counter_decimal));
				 other.set_numerator(atoi(value[1]));
				 other.reduce();
				 return in;
			 }
			 /*if (counter == 0)
			 {
				 other.set_integer(0);
				 other.set_numerator(0);
				 other.set_denominator(0);
			 }*/
			 if (counter == 1)
			 {
				 other.set_integer(atoi(value[0]));
			 }
			 if (counter == 2)
			 {
				 other.set_numerator(atoi(value[0]));
				 other.set_denominator(atoi(value[1]));
			 }
			 if (counter == 3)
			 {
				 other.set_integer(atoi(value[0]));
				 other.set_numerator(atoi(value[1]));
				 other.set_denominator(atoi(value[2]));
			 }
			 if (counter > 3)
			 {
				 cout << "Введено неправильные значения" << endl;
				 cout << "Введите значения заново" << endl;
			 }
			 other.to_proper().reduce();
		 } while (counter > 3);
		 return in;
	 }

//#define CONSTRUCTORS_CHECK
//#define OPERATORS_CHECK
//#define TYPE_CONVERSIONS_BASICS
//#define CONVERSIONS_FROM_OTHER_TOCLASS
//#define HOME_WORK

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
#ifdef OPERATORS_CHECK
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
	cout << "---------------------------------------------------------\n";
	/*A.common_denominator(B);
	B.common_denominator(A);
	A.print();
	B.print();*/
	Fraction C = A + B;
	C.print();
	cout << "--------------------------------------------------------\n";
	C = C - A;
	C.print();
	cout << "-------------------------------------------------------\n";
	C = A * B;
	C.print();
	cout << "--------------------------------------------------------\n";
	C /= A;
	C.print();
	cout << "-------------------------------------------------------\n";
	C += A;
	C.print();
	cout << "------------------------------------------------------\n";
	C -= A;
	C.print();
	cout << "------------------------------------------------------\n";
	B.print(A);
	cout << "----------------------------------------------------\n";
	A.print(B);
	cout << "----------------------------------------------------\n";
	Fraction D = B;
	D.print(B);
	cout << "----------------------------------------------------\n";
	print(B, A);
	print(B, D);
#endif

#ifdef TYPE_CONVERSIONS_BASICS
	int a = 2;
	double b = 3;
	int c = b;
	int d = 4.5;
	cout << d << endl;
#endif

#ifdef CONVERSIONS_FROM_OTHER_TOCLASS
	double a = 2;
	Fraction A = (Fraction)5;
	A.print();

	Fraction B;
	cout << "\n-------------------------------------------------\n";

	B = Fraction(8);
	cout << "\n----------------------------------------------------\n";
	B.print();

	Fraction C(12);
	Fraction D{ 13 };
#endif // CONVERSIONS_FROM_OTHER_TOCLASS

	//Fraction A(2);

	/*int a(A);
	cout << a << endl;

	int i = (int)A;

	int g{ A };
	cout << g << endl;*/


#ifdef HOME_WORK

	Fraction A(2, 3, 4);
	double a = A;
	cout << a << endl;

	double b = 2.76;
	Fraction B = b;
	B.print();
#endif // HOME_WORK

	/*Fraction A(2, 3, 4);

	cout << A << endl;*/

	Fraction A;
	cout << "Введите простую дробь: ";
	cin >> A;
	cout << A << endl;
	
}
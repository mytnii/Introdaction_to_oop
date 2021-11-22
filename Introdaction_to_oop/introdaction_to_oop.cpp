#include<iostream>
using namespace std;

#define tab "\t"

class Point
{
	double x;
	double y;
public:
	double get_x()const
	{
		return x;
	}
	double get_y()const
	{
		return y;
	}
	void set_x(double x)
	{
		this->x = x;
	}
	void set_y(double y)
	{
		this->y = y;
	}

	/*Point()
	{
		x = y = 0;
		cout << "DefaultConstructor:\t" << this << endl;
	}*/

	/*Point(double x)
	{
		this->x = x;
		this->y = double();
		cout << "1argConstructor:\t" << this << endl;
	}*/

	Point(double x = 0, double y = 0)
	{
		this->x = x;
		this->y = y;
		cout << "Constructors:\t" << this << endl;
	}

	~Point()
	{
		cout << "Destructor:\t" << this << endl;
	}

	void print()const
	{
		cout << "X = " << x << "\tY = " << y << endl;
	}
};

//#define  STRUCT_POINT

void main()
{
	setlocale(LC_ALL, "Russian");
#ifdef STRUCT_POIN
	Point A;
	A.x = 2;
	A.y = 3;
	cout << A.x << tab << A.y << endl;

	Point* pA = &A;

	cout << pA->x << tab << pA->y << endl;

#endif STRUCT_POINT

	Point A;

	//A.set_x(2);
	//A.set_y(3);

	/*cout << A.get_x() << tab << A.get_y() << endl;*/
	A.print();

	Point B(4, 5);
	B.print();

	Point C = 5;
	C.print();

	Point D(8);
	D.print();
}
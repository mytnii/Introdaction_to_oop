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

	Point(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyConstractor" << this << endl;
	}

	~Point()
	{
		cout << "Destructor:\t" << this << endl;
	}

	Point& operator =(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyAssignment:\t" << this << endl;
		return *this;
	}

	Point& operator++()
	{
		this->x++;
		this->y++;
		return *this;
	}

	Point operator++(int)
	{
		Point old = *this;
		x++;
		y++;
		return old;
	}
	double distance(Point other)
	{
		double x_distance = this->x - other.x;
		double y_distance = this->y - other.y;
		double distance = sqrt(x_distance * x_distance + y_distance * y_distance);
		return distance;
	}

	void print()const
	{
		cout << "X = " << x << "\tY = " << y << endl;
	}
};

double distance(Point A, Point B)
{
	double x_distance = A.get_x() - B.get_x();
	double y_distance = A.get_y() - B.get_y();
	return sqrt(x_distance * x_distance + y_distance * y_distance);
}

Point& operator+(const Point& left, const Point& right)
{
	Point result;
	result.set_x(left.get_x() + right.get_x());
	result.set_y(left.get_y() + right.get_y());
	return result;
}

//#define  STRUCT_POINT
//#define CONSTRUCTORS_CHECK
//#define DISTANCE_CHECK
//define ASSIGNMENT_CHECK
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
#ifdef CONSTRUCTORS_CHECK
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

	Point E = D;
	E.print();
	Point F(B);
	F.print();

	Point G;

	G = F;
	G.print();
#endif CONSTRUCTOR_CHECK
#ifdef DISTANCE_CHECK
	Point A(2, 3);
	Point B(3, 4);
	cout << "\n-------------------------------------------------------------" << endl;
	cout << "РАсстояние от точки А до точки В: " << A.distance(B) << endl;
	cout << "\n-------------------------------------------------------------" << endl;
	cout << "РАсстояние от точки А до точки В: " << B.distance(A) << endl;
	cout << "\n-------------------------------------------------------------" << endl;
	cout << "РАсстояние между точками А и В: " << distance(A, B) << endl;
	cout << "\n-------------------------------------------------------------" << endl;
	cout << "РАсстояние между точками B и A: " << distance(B, A) << endl;
	cout << "\n-------------------------------------------------------------" << endl;
#endif
#ifdef ASSIGNMENT_CHECK
	Point A, B, C;
	cout << "\n-----------------------------------------------------------\n";
	A = B = C = Point(2, 3);
	cout << "\n------------------------------------------------------------\n";
	A.print();
	B.print();
	C.print();
#endif

	int a = 2;
	int b = 3;
	int c = a + b;

	Point A(2, 3);
	Point B(4, 5);
	Point C = A + B;
	C.print();
	C++;
	C.print();
}
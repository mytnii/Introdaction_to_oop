// ��������� ������� ������ ��������
#include<iostream>
#include<iomanip>
#include<conio.h>
using namespace std;

// ������������ ������ �����
const int maxNameLength = 20;

// ����� ������
const int markCount = 3;

// ����������� ������
// --------------------------------
// �������
class Student
{
	// ���
	char name[maxNameLength];

	// ������
	int marks[markCount];

public:
	// �����������: �������� ������� �������
	Student(const char* name, const int* mark)
	{
		strcpy_s(Student::name, maxNameLength, name);

		for (int i = 0; i < markCount; i++)
		{
			Student::marks[i] = marks[i];
		}
	}

	// ���������� ������� ������
	double getAver()
	{
		double sum = 0;
		for (int i = 0; i < markCount; i++)
		{
			sum += marks[i];
		}
		return sum / markCount;
	}

	// ����� ������ � ��������
	void print()
	{
		cout << name << endl;
		cout << "������: ";
		for (int i = 0; i < markCount; i++)
		{
			cout << setw(4) << marks[i];
		}
		cout << endl;
	}

	// ����� ������� ������
	void printAver()
	{
		cout << "������� ������: "
			<< fixed << setprecision(2)
			<< getAver() << endl;
	}
};
// ----------------------------------------------------
// ����� ����������� ������

int main()
{
	setlocale(LC_ALL, "");

	cout << "������������ ��������."
		<< endl << endl;

	// ����� ������������ ������
	// �������� �������
	Student student{ "������ �.�. ", new int[3]{4,4,3} };

	// ����� ������ ������
	// ������ � ������� �������
	student.print();
	student.printAver();

	_getch();
	return 0;
}
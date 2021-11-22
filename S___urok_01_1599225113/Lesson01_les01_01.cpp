// ��������� ������� ������ ��������

#include <iostream>
#include <iomanip>
#include <conio.h>
using namespace std;

// ������������ ������ �����
const int maxNameLenght = 20;

// ����� ������
const int markCount = 3;

// ����������� ��������� ������
// ------------------------------------
// �������
struct Student
{
	// ���
	char name[maxNameLenght];

	// ������
	int marks[markCount];
};
// ----------------------------------------
// ����� ����������� ��������� ������

// ������� ��������� ��������� ������
// -----------------------------------------
// ���������� ������ � ��������
void initStudent(Student& student, const char* name, const int marks[])
{
	strcpy_s(student.name, maxNameLenght, name);
	for (int i = 0; i < markCount; i++)
	{
		student.marks[i] = marks[i];
	}
}

// ���������� ������� ������
double averMark(Student student)
{
	double sum = 0;
	for (int i = 0; i < markCount; i++)
	{
		sum += student.marks[i];
	}
	return sum / markCount;
}

// ����� ������ � ��������
void printStudent(Student student)
{
	cout << student.name << endl;
	cout << "������: ";
	for (int i = 0; i < markCount; i++)
	{
		cout << setw(4) << student.marks[i];
	}
	cout << endl;
}
// -------------------------------------------
// ����� ������ ������� ��������� ��������� ������

int main()
{
	setlocale(LC_ALL, "");

	cout << "������������ ��������." << endl << endl;

	Student student;
	const char* studentName{ "������ �.�." };
	int studentMarks[]{ 4,4,3 };
	initStudent(student, studentName, studentMarks);
	printStudent(student);
	cout << "������� ������: "
		<< fixed << setprecision(2)
		<< averMark(student) << endl;

	_getch();
	return 0;
}
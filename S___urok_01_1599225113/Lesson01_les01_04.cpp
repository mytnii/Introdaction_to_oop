// ��������� ������� ������ ��������
#include<iostream>
#include<conio.h>
using namespace std;

// ����������� ������
class Student
{
public:
	// ���
	char name[21];

	//������
	int marks[3];
};

int main()
{
	setlocale(LC_ALL, "");
	cout << "������������ ��������."
		<< endl << endl;

	// ����������� �������
	Student student;

	// ���������� �������� �������
	strcpy_s(student.name, 20, "������ �.�");
	student.marks[0] = 10;

	// ��������� �������� �������
	cout << student.name << " : "
		<< student.marks[0] << endl;

	return 0;
}
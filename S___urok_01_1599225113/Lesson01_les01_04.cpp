// Вычислить среднюю оценку студента
#include<iostream>
#include<conio.h>
using namespace std;

// определение класса
class Student
{
public:
	// ФИО
	char name[21];

	//оценки
	int marks[3];
};

int main()
{
	setlocale(LC_ALL, "");
	cout << "Успеваемость студента."
		<< endl << endl;

	// определение объекта
	Student student;

	// присвоение значения объекту
	strcpy_s(student.name, 20, "Петров А.И");
	student.marks[0] = 10;

	// получение значений объекта
	cout << student.name << " : "
		<< student.marks[0] << endl;

	return 0;
}
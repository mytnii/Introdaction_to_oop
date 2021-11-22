// Вычислить среднюю оценку студента

#include <iostream>
#include <iomanip>
#include <conio.h>
using namespace std;

// максимальная длинна имени
const int maxNameLenght = 20;

// число оценок
const int markCount = 3;

// определение структуры данных
// ------------------------------------
// Студент
struct Student
{
	// ФИО
	char name[maxNameLenght];

	// оценки
	int marks[markCount];
};
// ----------------------------------------
// конец определения структуры данных

// функции обработки структуры данных
// -----------------------------------------
// заполнение данных о студенте
void initStudent(Student& student, const char* name, const int marks[])
{
	strcpy_s(student.name, maxNameLenght, name);
	for (int i = 0; i < markCount; i++)
	{
		student.marks[i] = marks[i];
	}
}

// вычисление средней оценки
double averMark(Student student)
{
	double sum = 0;
	for (int i = 0; i < markCount; i++)
	{
		sum += student.marks[i];
	}
	return sum / markCount;
}

// вывод данных о студенте
void printStudent(Student student)
{
	cout << student.name << endl;
	cout << "Оценки: ";
	for (int i = 0; i < markCount; i++)
	{
		cout << setw(4) << student.marks[i];
	}
	cout << endl;
}
// -------------------------------------------
// конец списка функций обработки структуры данных

int main()
{
	setlocale(LC_ALL, "");

	cout << "Успеваемость студента." << endl << endl;

	Student student;
	const char* studentName{ "Петров А.О." };
	int studentMarks[]{ 4,4,3 };
	initStudent(student, studentName, studentMarks);
	printStudent(student);
	cout << "Средняя оценка: "
		<< fixed << setprecision(2)
		<< averMark(student) << endl;

	_getch();
	return 0;
}
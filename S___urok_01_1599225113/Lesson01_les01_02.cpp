// Вычислить среднюю оценку студента
#include<iostream>
#include<iomanip>
#include<conio.h>
using namespace std;

// максимальная длинна имени
const int maxNameLength = 20;

// число оценок
const int markCount = 3;

// определение класса
// --------------------------------
// Студент
class Student
{
	// ФИО
	char name[maxNameLength];

	// оценки
	int marks[markCount];

public:
	// конструктор: создание объекта Студент
	Student(const char* name, const int* mark)
	{
		strcpy_s(Student::name, maxNameLength, name);

		for (int i = 0; i < markCount; i++)
		{
			Student::marks[i] = marks[i];
		}
	}

	// вычисление средней оценки
	double getAver()
	{
		double sum = 0;
		for (int i = 0; i < markCount; i++)
		{
			sum += marks[i];
		}
		return sum / markCount;
	}

	// вывод данных о студенте
	void print()
	{
		cout << name << endl;
		cout << "Оценки: ";
		for (int i = 0; i < markCount; i++)
		{
			cout << setw(4) << marks[i];
		}
		cout << endl;
	}

	// вывод средней оценки
	void printAver()
	{
		cout << "Средняя оценка: "
			<< fixed << setprecision(2)
			<< getAver() << endl;
	}
};
// ----------------------------------------------------
// конец определения класса

int main()
{
	setlocale(LC_ALL, "");

	cout << "Успеваемость студента."
		<< endl << endl;

	// вызов конструктора класса
	// создание объекта
	Student student{ "Петров А.О. ", new int[3]{4,4,3} };

	// вызов метода класса
	// работа с данными объекта
	student.print();
	student.printAver();

	_getch();
	return 0;
}
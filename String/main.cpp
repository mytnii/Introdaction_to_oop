

#include<iostream>
#include<cstring>


//Класс строка
class String
{
	int size; //Количество символов в строке
	char* str; //Адрес на индэкс первого элемента в строке

public:

//-------------------------Get-metods------------------------------

      //константный Get - метод для  переменной size типа int
	 const int get_size()const
	{
		return size;
	}

	 //константный Get - метод на адрес str типа char
	const char* get_str()const
	{
		return str;
	}
	

//---------------Constructors-------------------------------------
             
	//Конструктор по умолчанию
	String()
	{
		this->size = 80;
		this->str = new char[size] {};
		std::cout << "DefaultConstructor:\t" << this << std::endl;
	}

	//Конструктор с одним параметром типа char
	String(const char* str)
	{
		this->size = strlen(str) + 1;
		this->str = new char[size] {};
		for (int i = 0; i < size; i++)
		{
			this->str[i] = str[i];
		}
		std::cout << "Constructor:\t" << this << std::endl;
	}

	//Явный конструктор с одним параметром типа int
    explicit String( const int& size)
	{
		this->size = size;
		this->str = new char[size] {};

		std::wcout << "ExplicitConstructor:\t" << this << std::endl;
	}

	//Конструктор копирования
	String(const String& other)
	{
		this->size = other.size;
		this->str = new char[size];
		for (int i = 0; i < size; i++)
		{
			this->str[i] = other.str[i];
		}

		std::cout << "CopiConstructor:\t" << this << std::endl;
	}


//-------------Destructor----------------------------------------

	~String()
	{
		delete[] this->str;
		std::cout << "Destructor:\t" << this << std::endl;
	}

//-----------Print-----------------------------------------------

	void print()
	{
		std::cout << size << std::endl;
		std::cout << str << std::endl;
	}

//--------------Operators--------------------------------------

	//Оператор подстрочного индекса
	char& operator[](int i)
	{
		return str[i];
	}

	//Константный оператор подстрочного индекса
	const char& operator[](int i)const
	{
		return str[i];
	}

};


//Оператор унарного плюса
String operator+(const String& left,  const String& right)
{
	String string((left.get_size() + right.get_size() - 1));
	for (int i = 0; i < left.get_size(); i++)
	{
		string[i] = left[i];

	}

	for (int i = 0; i < right.get_size(); i++)
	{
		string[i + left.get_size() - 1] = right[i];
	}

	return string;
}

//Оператор сдвига в право
std::ostream& operator<<(std::ostream& out, String& other)
{
	out << other.get_str();

	return out;
}

int main()
{
	std::cout << " ------------------------------------------------\n";

	String str;
	str.print();

	std::cout << " ------------------------------------------------\n";

	String str1 = "Hello";
	str1.print();

	std::cout << " ------------------------------------------------\n";

	String str2 = "World";
	str2.print();

	std::cout << " ------------------------------------------------\n";

	String str3 = str1 + str2;
	std::cout << str3 << std::endl;

	std::cout << " -----------------------------------------------\n";

	String str4(25);
	str4.print();

	std::cout << " -----------------------------------------------\n";

	return 0;
}

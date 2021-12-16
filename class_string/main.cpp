#pragma warning(disable:4326)

#include<iostream>
using std::cin;
using std::cout;
using std::endl;

class String;
String operator+(const String& left, const String& right);


class String
{
	int size;  //Размер строки
	char* str; //Адрес строки в динамической памяти
public:
	const char* get_str()const
	{
		return str;
	}

	 char* get_str()
	{
		return str;
	}


	 int get_size()const
	{
		return size;
	}

	 void set_size(int size)
	 {
		 this->size = size;
	 }

	explicit String(int size = 80)
	{
		this->size = 80;
		this->str = new char[size] {};  //Память выделяемую для строки обязательно нужно занулить
		cout << "SizeConstructor:\t" << this << endl;
	}

	String(const char str[])
	{
		this->size = strlen(str) + 1;
		this->str = new char[size] {};
		for (int i = 0; str[i]; i++)
		{
			this->str[i] = str[i];
		}
		cout << "Constructor:\t" << this << endl;
	}

	String(const String& other)
	{
		this->size = other.size;
		this->str = new char[size] {};
		for (int i = 0; i < size; i++)
		{
			this->str[i] = other.str[i];
		}
		cout << "CopyConstructor:\t" << this << endl;
	}

	~String()
	{
		delete[] str;
		cout << "Destructor:\t" << this << endl;
	}

	//-------------------Operators------------
	String& operator=(const String& other)
	{
		if (this == &other)
		{
			return *this;
		}
		delete[] this->str;
		this->size = other.size;
		this->str = new char[size] {};
		for (int i = 0; i < size; i++)
		{
			this->str[i] = other.str[i];
		}
		cout << "CopyAssignment:\t" << this << endl;
		return *this;
	}

	String& operator+=(const String& other)
	{
		return *this = *this + other;
	}

	char& operator[](int i)
	{
		return str[i];
	}

	const char& operator[](int i)const
	{
		return str[i];
	}


	//-------------------Methods---------------

	void print()
	{
		cout << "Size:\t" << size << endl;
		cout << "Str:\t" << str << endl;

	}



};

String operator+(const String& left, const String& right)
{
	String result((left.get_size() + right.get_size() - 1));
	for (int i = 0; i < left.get_size(); i++)
	{
		
		//result.get_str()[i] = left.get_str()[i];
		result[i] = left[i];
	}

	for (int i = 0; i < right.get_size(); i++)
	{
		//result.get_str()[i + left.get_size() - 1] = right.get_str()[i];
		result[i + left.get_size() - 1] = right[i];

	}

	return result;
}


std::ostream& operator<<(std::ostream& os, const String& obj)
{
	return os << obj.get_str();
}

std::istream& operator>>(std::istream& in,  String& obj)
{
	//return in >> obj.get_str();
	in >> obj.get_str();
	//char* str = new char[strlen(obj.get_str())];
	//for (int i = 0; str[i]; i++)
	//{
	//	str[i] = obj[i];
	//}

	//obj = str;
	String str(obj.get_str());
	obj = str;

	return in;
}

//#define CONSTRUCTORS_CHECk

void main()
{
	setlocale(LC_ALL, "");
#ifdef CONSTRUCTORS_CHECk
	String str1;
	str1.print();
	cout << str1 << endl;
	String str2(25);
	str2.print();

	String str3 = "Hello";
	str3 = str3;
	cout << str3 << endl;

	String str4 = str3;
	cout << str4 << endl;

	String str5;
	str5 = str3;
	cout << str5 << endl;
#endif

	/*String str1 = "Hello";
	String str2 = "World";
	String str3 = str1 + str2;
	cout << str3 << endl;*/

	String str1 = "Hello";
	String str2 = "World";
	str1 += str2;
	cout << str1 << endl;

	String str;
	cout << "Введите строку: "; cin >> str;
	cout << str << endl;
	str.print();
}
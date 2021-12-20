#pragma warning(disable:4326)

#include<iostream>
#include<string>
using std::cin;
using std::cout;
using std::endl;

#define delimiter cout << "\n-----------------------------------------------------------\n";

class String;
String operator+(const String& left, const String& right);


class String
{
	int size;  //Размер строки
	char* str; //Адрес строки в динамической памяти
public:
	const char* get_str()const;
	char* get_str();


	int get_size()const;



	void set_size(int size);

	explicit String(int size = 80);

	String(const char str[]);

	String(const String& other);

	~String();

	//-------------------Operators------------
	String& operator=(const String& other);

	String& operator+=(const String& other);


	char& operator[](int i);
	const char& operator[](int i)const;


	//-------------------Methods---------------

	void print()const;



};

const char* String::get_str()const
{
	return str;
}
char* String::get_str()
{
	return str;
}

int String::get_size()const
{
	return size;
}




 String::String(int size) :size(size), str(new char[size] {})
{
	//this->size = size;
	//this->str = new char[size] {};  //Память выделяемую для строки обязательно нужно занулить
	cout << "SizeConstructor:\t" << this << endl;
}

String::String(const char str[]) :String(strlen(str) + 1)
{
	//this->size = strlen(str) + 1;
	//this->str = new char[size] {};
	for (int i = 0; str[i]; i++)
	{
		this->str[i] = str[i];
	}
	cout << "Constructor:\t" << this << endl;
}

String::String(const String& other) :String(other.str)
{
	/*this->size = other.size;
	this->str = new char[size] {};
	for (int i = 0; i < size; i++)
	{
		this->str[i] = other.str[i];
	}*/
	cout << "CopyConstructor:\t" << this << endl;
}

String::~String()
{
	delete[] str;
	cout << "Destructor:\t" << this << endl;
}

//-------------------Operators------------
String& String::operator=(const String& other)
{
	//if (this == &other)
	//{
	//	return *this;
	//}
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

String& String::operator+=(const String& other)
{
	return *this = *this + other;
}


char& String::operator[](int i)
{
	return str[i];
}
const char& String::operator[](int i)const
{
	return str[i];
}


//-------------------Methods---------------

void String::print()const
{
	cout << "Size:\t" << size << endl;
	cout << "Str:\t" << str << endl;

}






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
	
	/*in.getline(obj.get_str(), 1e+10);

	 int size = strlen(obj.get_str()) + 1;*/

	/*cout << size << endl;

	cout << obj.get_str() << endl;*/

	/*char* str = new char[size] {};*/
	//char* str = new char[strlen(obj.get_str())];
	//for (int i = 0; str[i]; i++)
	//{
	//	str[i] = obj.get_str()[i];
	//}
	/*String str(size);
	for (int i = 0; i < size; i++)
	{
		str.get_str()[i] = obj.get_str()[i];
	}*/

	/*str.print();*/
	/*obj = str;
	
	return in;*/

	const int SIZE = 1024 * 1000;
	char buffer[SIZE] = {};
	in >> buffer;
	obj = buffer;
	return in;
}
std::istream& getline(std::istream& is, String& obj)
{
	const int SIZE = 1024 * 1000;
	char buffer[SIZE] = {};
	is.getline(buffer, SIZE);
	obj = buffer;
	return is;
}

//#define CONSTRUCTORS_CHECk
#define OPERATORS_CHECK
//#define INPUT_CHECK

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
#ifdef OPERATORS_CHECK
	delimiter;
	String str1 = "Hello";

	delimiter;
	String str2 = "World";

	delimiter;
	str1 += str2;

	delimiter;
	cout << str1 << endl;

	delimiter;
	String str;

	cout << "Введите строку: "; cin >> str;
	delimiter;

	cout << str << endl;
	delimiter;

	str.print();
	delimiter;
#endif // OPERATORS_CHECK

#ifdef  INPUT_CHECK
	String str;
	cout << "Введите строку: ";
	/*cin >> str;*/
	getline(cin, str);
	cout << str << endl;
	str.print();
#endif //  INPUT_CHECK

}
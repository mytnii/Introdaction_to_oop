

#include<iostream>
#include<cstring>


//����� ������
class String
{
	int size; //���������� �������� � ������
	char* str; //����� �� ������ ������� �������� � ������

public:

//-------------------------Get-metods------------------------------

      //����������� Get - ����� ���  ���������� size ���� int
	 const int get_size()const
	{
		return size;
	}

	 //����������� Get - ����� �� ����� str ���� char
	const char* get_str()const
	{
		return str;
	}
	

//---------------Constructors-------------------------------------
             
	//����������� �� ���������
	String(const int size = 80)
	{
		this->size = size;
		this->str = new char[size] {};
		std::cout << "DefaultConstructor:\t" << this << std::endl;
	}

	//����������� � ����� ���������� ���� char
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

	//����� ����������� � ����� ���������� ���� int
	explicit String(int& size)
	{
		this->size = size;
		this->str = new char[size];

		std::wcout << "ExplicitConstructor:\t" << this << std::endl;
	}

	//����������� �����������
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

	//�������� ������������ �������
	char& operator[](int i)
	{
		return str[i];
	}

	//����������� �������� ������������ �������
	const char& operator[](int i)const
	{
		return str[i];
	}

};


//�������� �������� �����
String operator+(const String& left,  const String& right)
{
	String string = (left.get_size() + right.get_size() - 1);
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

//�������� ������ � �����
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



#include<iostream>

#define delimiter std::cout << "\n---------------------------------------\n";

class Matrix
{
	int rows;
	int cols;
	int** matrix;

public:

//-----------------------Get - metods-------------------------------

	 int get_rows()const
	{
		return rows;
	}

	 int get_cols()const
	{
		return cols;
	}

	 int** get_matrix()
	 {
		 return matrix;
	}

	 int** get_matrix()const
	 {
		 return matrix;
	 }

//----------------------------Constructors---------------------------

	explicit Matrix(const int rows = 3, const int cols = 3)
		:rows(rows), cols(cols), matrix(new int* [rows])
	{
		for (int i = 0; i < rows; i++)
		{
			matrix[i] = new int[cols] {};
		}

		std::cout << "Constructor:\t" << this << std::endl;
	}

	Matrix(const Matrix& other) :Matrix(other.rows, other.cols)
	{
		*this = other;
	}

//-----------------------------------Destructor------------------------

	~Matrix()
	{
		for (int i = 0; i < rows; i++)
		{
			delete[] matrix[i];
		}
		delete[] matrix;
		matrix = NULL;
		rows = 0;
		cols = 0;

		std::cout << "Destructor:\t" << this << std::endl;
	}

//-----------------------------Metods------------------------------

	//Вывод матрици на экран
	void print()
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				std::cout << matrix[i][j] << "\t";
			}

			std::cout << std::endl;
		}
	}

	//Заполнение матрици
	void filling()
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				matrix[i][j] = rand() % 10 + 1;
			}
		}
	}

//---------------------------------------Operators-------------------------

	int* operator[](int i)
	{
		return matrix[i];
	}
	const int* operator[](int i)const
	{
		return matrix[i];
	}

	Matrix& operator=(const Matrix& other)
	{
		if (this == &other)
		{
			return *this;
		}
		this->~Matrix();
		this->rows = other.rows;
		this->cols = other.rows;
		this->matrix = new int* [rows];
		for (int i = 0; i < rows; i++)
		{
			matrix[i] = new int[cols];
			memcpy(this->matrix[i], other.matrix[i], cols * sizeof(int));
		}

		std::cout << "CopyAssignment:\t" << this << std::endl;

		return *this;
	}

	friend Matrix operator+(const Matrix& left, const Matrix& right);
	friend Matrix operator-(const Matrix& left, const Matrix& right);
	friend Matrix operator*(const Matrix& left, const Matrix& right);
	friend Matrix operator/(const Matrix& left, const Matrix& right);

};

Matrix operator+(const Matrix& left, const Matrix& right)
{
	Matrix matrix = left;

		for (int i = 0; i < right.rows; i++)
		{
			for (int j = 0; j < right.cols; j++)
			{
				matrix[i][j] = matrix.matrix[i][j] + right.matrix[i][j];
			}
		}

	return matrix;
}

Matrix operator-(const Matrix& left, const Matrix& right)
{
	Matrix matrix = left;

	for (int i = 0; i < right.rows; i++)
	{
		for (int j = 0; j < right.cols; j++)
		{
			matrix[i][j] = matrix.matrix[i][j] - right.matrix[i][j];
		}
	}

	return matrix;
}

Matrix operator*(const Matrix& left, const Matrix& right)
{
	Matrix matrix = left;

	for (int i = 0; i < right.rows; i++)
	{
		for (int j = 0; j < right.cols; j++)
		{
			matrix[i][j] = matrix.matrix[i][j] * right.matrix[i][j];
		}
	}



	return matrix;
}

Matrix operator/(const Matrix& left, const Matrix& right)
{
	Matrix matrix = left;

	for (int i = 0; i < right.rows; i++)
	{
		for (int j = 0; j < right.cols; j++)
		{
			matrix[i][j] = matrix.matrix[i][j] / right.matrix[i][j];
		}
	}

	return matrix;
}



int main()
{
	setlocale(LC_ALL, "");

	srand(time(NULL));

	delimiter;
	Matrix matrix(4,4);
	matrix.filling();
	delimiter;
	matrix.print();

	delimiter;
	Matrix matrix2(4,4);
	matrix2.filling();
	delimiter;
	matrix2.print();

	delimiter;
	Matrix matrix3;
	delimiter;
	matrix3 = matrix;
	delimiter;
	matrix3.print();

	delimiter;
	Matrix matrix4;
	matrix4 = matrix + matrix2;
	delimiter;
	matrix4.print();

	delimiter;
	matrix4 = matrix4 - matrix2;
	delimiter;
	matrix4.print();

	delimiter;
	matrix4 = matrix * matrix2;
	delimiter;
	matrix4.print();

	delimiter;
	matrix4 = matrix4 / matrix2;
	delimiter;
	matrix4.print();

	return 0;
}
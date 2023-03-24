#include <windows.h>
#include <iostream>
#include <string>


int enterData(std::string text)
{
	int date;

	std::cout << "Write a date \n";
	std::cin >> date;

	return date;
}

class Matrix
{
public:
	int lengthN;
	int lengthM;

	int** matrix;

	Matrix(int LengthN, int LengthM,int userInput)
	{
		lengthN = LengthN;
		lengthM = LengthM;
		

		matrix = new int* [LengthN];
		
		for (int i = 0; i < LengthN; ++i)
		{
			matrix[i] = new int[LengthM] {};
		}

		if (userInput == 1)
		{
			for (int i = 0; i < LengthN; ++i)
				for (int j = 0; j < lengthM; ++j)
					matrix[i][j] = enterData("Write a number");
		}
		else if(userInput == 2)
		{
			int firstNumber = enterData("Write a number for first range");
			int secondNumber = enterData("Write a number for second range");

			for (int i = 0; i < LengthN; ++i)
				for (int j = 0; j < lengthM; ++j)
					 matrix[i][j] = firstNumber + rand() % secondNumber;
		}
		
	}

	void UpgradeMatrix(int OldLengthN,int LengthN, int LengthM)
	{
		for (int i = 0; i < OldLengthN; i++)
			delete[] matrix[i];

		delete[] matrix;

		matrix = new int* [LengthN];

		for (int i = 0; i < LengthN; ++i)
		{
			matrix[i] = new int[LengthM] {};
		}
	}

	~Matrix()
	{
		for (int i = 0; i < lengthN; i++)
			delete[] matrix[i];

		delete[] matrix;

		std::cout << "The matrix is deleted\n";
	}

	void DisplayMatrix()
	{
		
		for (int i = 0; i < lengthN; ++i)
		{
			for (int j = 0; j < lengthM; ++j)
					std::cout << matrix[i][j] << " ";

			std::cout << std::endl;
		}
	}

	void DeterminantOfMatrix()
	{

	}

};

Matrix& operator + (Matrix& MatrixA, Matrix& MatrixB)
{
	if (MatrixA.lengthN == MatrixB.lengthN and MatrixA.lengthM == MatrixB.lengthM)
	{
		for (int i = 0; i < MatrixA.lengthN; ++i)
			for (int j = 0; j < MatrixA.lengthM; ++j)
				MatrixA.matrix[i][j] += MatrixB.matrix[i][j];
	}
	else
		std::cout << "MatixA != MatrixB \n";

	return MatrixA;
	 
}


Matrix& operator * (Matrix& MatrixA, Matrix& MatrixB)
{
	Matrix m(MatrixA.lengthN, MatrixB.lengthM, 3);

	if (MatrixA.lengthN == MatrixB.lengthM)
	{
		for (int i = 0; i < MatrixA.lengthN; ++i)
			for (int d = 0; d < MatrixB.lengthM; d++)
				for (int j = 0; j < MatrixA.lengthM; j++)
					m.matrix[i][d] += MatrixA.matrix[i][j] * MatrixB.matrix[j][d];
	}
	else
		std::cout << "MatixA string lenght != MatrixB column lenght \n";

	
	


	MatrixA.UpgradeMatrix(MatrixA.lengthN,m.lengthN, m.lengthM);
	
	MatrixA.lengthM = m.lengthM;
	MatrixA.lengthN = m.lengthN;

	for (int i = 0; i < m.lengthN ; ++i)
		for (int j = 0; j < m.lengthM; ++j)
			MatrixA.matrix[i][j] = m.matrix[i][j];

	


	return MatrixA;
}




void main()
{
	//std::srand(std::time(nullptr));

	Matrix A(3, 2, 2);
	Matrix B(2, 3, 2);
	std::cout << "|||||||||||||||\n";
	A.DisplayMatrix();
	std::cout << "|||||||||||||||\n";
	B.DisplayMatrix();
	
	
	A = A * B;
	std::cout << "|||||||||||||||\n";
	A.DisplayMatrix();
	std::cout << "|||||||||||||||\n";
	

	
}

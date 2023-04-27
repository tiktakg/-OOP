#include <windows.h>
#include <iostream>
#include <string>

#define checkSymbol (('0' <= text[i] && text[i] <= '9') > 0)



int checkNumber(std::string repeat)
{
	int number1;
	bool work = true;
	bool work2 = true;
	std::string text;

	while (work == true or work2 == true)
	{
		work = true;
		work2 = true;
		std::cout << repeat;
		noskipws(getline(std::cin, text));

		text.insert(text.size(), 2, ' ');

		for (int i = 0; i < text.size(); i++)
		{
			for (int i = 0; i < text.size(); i++)
			{
				if (checkSymbol)
					if (text[i + 1] == ' ')
						if ('0' <= text[i + 2] && text[i + 2] <= '9') break;
						else work2 = false;

				if (text[i] == ' ')
				{
					text.erase(i, 1);
					i--;
				}
			}
			if (!checkSymbol) break;

			if (i == text.size() - 1) work = false;

		}
		system("cls");
		number1 = atof(text.c_str());
	}
	return number1;
}

class Matrix
{
public:
	int lengthN;
	int lengthM;


	int** matrix;

	Matrix(int userInput = 1, int LengthN = 0, int LengthM = 0)
	{
		
		if (userInput != 3)
		{
			lengthN = checkNumber("Write a lenght N \n");
			lengthM = checkNumber("Write a lenght M \n");

			userInput = checkNumber("Write a filling method \n1 - manual \n2 - automatic  \n");

			LengthN = lengthN;
			LengthM = lengthM;

			system("cls");

		}
		else
		{

			lengthN = LengthN;
			lengthM = LengthM;

		}
		

		matrix = new int* [LengthN];

		for (int i = 0; i < LengthN; ++i)
			matrix[i] = new int[LengthM] {};

		if (userInput == 1)
		{
			for (int i = 0; i < LengthN; ++i)
				for (int j = 0; j < LengthM; ++j)
					matrix[i][j] = checkNumber("Write a number \n");

			system("cls");
		}
		else if (userInput == 2)
		{
			int firstNumber = checkNumber("Write a number for first range\n");
			int secondNumber = checkNumber("Write a number for second range\n");

			system("cls");

			for (int i = 0; i < LengthN; ++i)
				for (int j = 0; j < LengthM; ++j)
					matrix[i][j] = firstNumber + rand() % secondNumber;
		}

	}

	void UpgradeMatrix(int OldLengthN, int LengthN, int LengthM)
	{
		matrix = new int* [LengthN];

		for (int i = 0; i < LengthN; ++i)
			matrix[i] = new int[LengthM] {};
	}

	//~Matrix()
	//{

	//	for (int i = 0; i < lengthN; i++)
	//			delete[] matrix[i];

	//	delete[] matrix;

	//}

	void DisplayMatrix()
	{
		for (int i = 0; i < lengthN; ++i)
		{
			for (int j = 0; j < lengthM; ++j)
				std::cout << matrix[i][j] << " ";

			std::cout << std::endl;
		}
		std::cout << std::endl;
		
	}
	 
	int  determinantOfMatrix()
	{
		int det = 0;
		if (lengthN != lengthM) 
		{
			std::cout << "The matrix is deleted\n";
		}
		else if (lengthN == 1)
			det = matrix[0][0];
		else if (lengthN == 2)
			det = matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
		else
		{
			for (int i = 0; i < lengthN; i++) {
				Matrix submatrix(3,lengthN - 1, lengthN - 1);
				for (int j = 1; j < lengthN; j++) {
					for (int k = 0; k < lengthN; k++) {
						if (k < i) 
							submatrix.matrix[j - 1][k] = matrix[j][k];
						else if (k > i) {
							submatrix.matrix[j - 1][k - 1] = matrix[j][k];
						}
					}
				}
				det += pow(-1, i) * matrix[0][i] * submatrix.determinantOfMatrix();
			}
			return det;
		}
		
	}
	

	void TransporantOfMaterix()
	{
		Matrix m(3, lengthN, lengthM);

		if(lengthN == lengthM)
			for (int i = 0; i < lengthN; ++i)
			{
				for (int j = 0; j < lengthM; ++j)
				{
					m.matrix[i][j] = matrix[j][i];
					std::cout << m.matrix[i][j] << " ";
				}
				std::cout << std::endl;
			}
		else
			std::cout << "Matix lengthN != lengthM \n";
	}

		
	

};

Matrix& operator + (Matrix& MatrixA, Matrix& MatrixB)
{

	if (MatrixA.lengthN == MatrixB.lengthN and MatrixA.lengthM == MatrixB.lengthM)
		for (int i = 0; i < MatrixA.lengthN; ++i)
			for (int j = 0; j < MatrixA.lengthM; ++j)
				MatrixA.matrix[i][j] += MatrixB.matrix[i][j];
	else 
		std::cout << "MatixA != MatrixB \n";
		

	return MatrixA;
	

}


Matrix& operator * (Matrix& MatrixA, Matrix& MatrixB)
{
	//Matrix m(3, MatrixA.lengthN, MatrixB.lengthM);

	if (MatrixA.lengthN == MatrixB.lengthM)
	{
		/*for (int i = 0; i < MatrixA.lengt1hN; ++i)
			for (int d = 0; d < MatrixB.lengthM; d++)
				for (int j = 0; j < MatrixA.lengthM; j++)
					m.matrix[i][d] += MatrixA.matrix[i][j] * MatrixB.matrix[j][d];

		MatrixA.UpgradeMatrix(MatrixA.lengthN, m.lengthN, m.lengthM);

		MatrixA.lengthM = m.lengthM;
		MatrixA.lengthN = m.lengthN;

		for (int i = 0; i < m.lengthN; ++i)
			for (int j = 0; j < m.lengthM; ++j)
				MatrixA.matrix[i][j] = m.matrix[i][j];*/
	}
	else
		std::cout << "MatixA string lenght != MatrixB column lenght \n";


	

	return MatrixA;
}




int main()
{
	std::srand(std::time(nullptr));


	Matrix A;
	Matrix B;

	A.DisplayMatrix();
	B.DisplayMatrix();

	//Matrix C = A + B;
	std::cout << "A + B\n";
	A.DisplayMatrix();

	////C = A * B;
	//std::cout << "A * B\n";
	//C.DisplayMatrix();

	//std::cout << A.determinantOfMatrix();
	

}

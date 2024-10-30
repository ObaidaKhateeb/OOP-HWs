//Student Bshara Haj, 212590186.
//Student Obaeda Khatib, 201278066.
#pragma once
#include<iostream>

using std::ostream;
using std::endl;

template <int rows = 1, int cols = 1, typename T = int>

class Matrix 
{
	T data[rows][cols];
public:
	//Defalut constructor
	Matrix()
	{
		int i,j;
		for (i = 0 ; i < rows ; i++)
		{
			for (j = 0 ; j < cols ; j++)
				data[i][j] = 0;
		}
	}
	//Constructor
	Matrix(T t) 
	{
		int i, j;
		for (i = 0 ; i < rows ; i++)
		{
			for (j = 0 ; j < cols ; j++)
				data[i][j] = t;
		}
	}
	//function that add scalar to each one of matrix elements
	friend Matrix <rows, cols, T> operator+(const Matrix<rows, cols, T>& matrix, const T scalar)
	{
		Matrix<rows, cols, T> sum;
		sum = scalar + matrix;
		return sum;
	}

	//function that add scalar to each one of matrix elements. 
	friend Matrix <rows, cols, T> operator+(const T scalar, const Matrix<rows, cols, T>& matrix)
	{
		Matrix<rows, cols, T> scalarMatrix(scalar);
		scalarMatrix = scalarMatrix + matrix;
		return scalarMatrix;
	}
	//function that add a matrix to another one. 
	friend Matrix <rows, cols, T> operator+(const Matrix <rows, cols, T>& firstMatrix, const Matrix <rows, cols, T>& secondMatrix)
	{
		Matrix <rows, cols, T> tempMatrix;
		for (int i = 0; i < rows; i++) 
		{
			for (int j = 0; j < cols; j++)
			{
				tempMatrix.data[i][j] = firstMatrix.data[i][j] + secondMatrix.data[i][j];
			}
		}
		return tempMatrix;
	}

	// function that substract a scalar from each of the matrix elements. 
	friend Matrix<rows, cols, T> operator-(const Matrix<rows, cols, T>& matrix, const T scalar) 
	{
		Matrix<rows, cols, T> sum;
		sum = - scalar + matrix; 
		return sum;
	}

	//function that substract a scalar from each of the matrix elements.
	friend Matrix<rows, cols, T> operator-(const T num, const Matrix<rows, cols, T>& matrix) 
	{
		Matrix<rows, cols, T> tempMatrix(num);
		tempMatrix = tempMatrix - matrix;
		return tempMatrix;
	}

	//function that substract a matrix from another matrix. 
	friend Matrix <rows, cols, T> operator-(const Matrix <rows, cols, T>& firstMatrix, const Matrix <rows, cols, T>& secondMatrix) 
	{
		Matrix<rows, cols, T> tempMatrix;
		tempMatrix = firstMatrix + T(-1) * secondMatrix;
		return tempMatrix;
	}

	//-matrix. function that return a new matrix with the opposite numbers of current matrix elements. 
	friend Matrix<rows, cols, T> operator-(const Matrix<rows, cols, T>& matrix)
	{
		int i, j;
		Matrix<rows, cols, T> tempMatrix;
		for (i = 0; i < rows; i++)
			for (j = 0 ; j < cols ; j++)
				tempMatrix.data[i][j] = - matrix.data[i][j];
		return (tempMatrix);
	}

	// function that multipy a matrix by a scalar. reutrns the result.
	friend  Matrix<rows, cols, T> operator*(const Matrix<rows, cols, T>& matrix, const T num) 
	{
		int i, j;
		Matrix<rows, cols, T> tempMatrix;
		for (i = 0; i < rows; i++) 
		{
			for (j = 0 ; j < cols ; j++)
				tempMatrix.data[i][j] = matrix.data[i][j] * num;

		}
		return tempMatrix;
	}

	// function that multipy a matrix by a scalar. reutrns the result.
	friend  Matrix<rows, cols, T> operator*(const T num, const Matrix<rows, cols, T>& matrix) 
	{
		Matrix<rows, cols, T> tempMatrix;
		tempMatrix = matrix * num;
		return tempMatrix;
	}

	// function that multipy two matrices. reutrns the result.
	friend Matrix <rows, cols, T> operator* (const Matrix <rows, cols, T>& firstMatrix, const Matrix <rows, cols, T>& secondMatrix)
	{
		int i, j, k;
		Matrix <rows, cols, T> tempMatrix(0);
		for (i = 0; i < rows; i++)
		{
			for (j = 0; j < cols; j++)
			{

				for (k = 0; k < cols; k++)
				{
					tempMatrix.data[i][j] += (firstMatrix.data[i][k] * secondMatrix.data[k][j]); 
				}
			}
		}
		return tempMatrix;
	}

	// function that returns the identity matrix of the same size of the matrix.
	static Matrix <rows, cols, T> getIdentityMatrix() 
	{   
		int i;
		Matrix<rows, cols, T> tempMatrix(T(0));   
		for (i = 0; i < rows; i++)
			tempMatrix.data[i][i] = T(1);
		return tempMatrix;
	}

	

	// matrix++. function that add one to each of the matrix elements, then return the matrix before the add operation. 
	Matrix <rows, cols, T> operator++(int)
	{
		Matrix <rows, cols, T> tempMatrix = *this;
		*this = *this + T(1);
		return tempMatrix;
	}

	// ++matrix. function that add one to each of the matrix elements. then returns it. 
	Matrix <rows, cols, T>& operator++()
	{
		*this = *this + T(1);
		return *this;
	}

	//matrix--. function that substracts one from each elemnt , and returns the matrix that was before the substract.
	Matrix <rows, cols, T> operator--(int) 
	{
		Matrix <rows, cols, T> tempMatrix = *this;
		*this = *this - T(1);
		return tempMatrix;
	}

	// --matrix. function that substracts one from each element in the matrix , then returns it.
	Matrix <rows, cols, T>& operator--()
	{
		*this = *this - T(1);
		return *this;
	}

	//function that returns the matrix main diagonal
	T* getDiag(int& num)
	{
		int i = 0;
		if (rows > cols) // get the min between rows and cols. 
		{
			num = cols;
		}
		else
		{
			num = rows;
		}
		T* diagArr = new T[num];
		for (i = 0; i < num; i++)
		{
			diagArr[i] = data[i][i];
        }
		return diagArr;
	}

	// Operator==. function that checks if the two matrices are equal, it returns true if the're equal.
	friend bool operator==(Matrix<rows, cols, T>& firstMatrix, Matrix<rows, cols, T>& secondMatrix) 
	{
		int i, j;
		T difference;
		for (i = 0; i < rows; i++)
			for (j = 0; j < cols; j++)
			{
				difference = (firstMatrix.data[i][j] - secondMatrix.data[i][j]);
				if (difference < 0)
				{
					difference = -difference;
				}
				if (difference > DBL_EPSILON)
				{
					return 0;
				}
			}
		return 1;
	}

	// Operator !=. function that checks if the two matrices are not equal, it returns true if the're not equal.
	friend bool operator!=(Matrix<rows, cols, T>& firstMatrix, Matrix<rows, cols, T>& secondMatrix) 
	{
		return !(firstMatrix == secondMatrix);
	}

	// function that returns the trace of the matrix.
	operator T()
	{
		T trace = 0;
		int i,num;
		T* temp = this->getDiag(num);

		for (i = 0 ; i < num ; i++)
		{
			trace += temp[i];
		}
		delete[] temp;
		return trace;
	}

	// operator << 
	friend ostream& operator<<(ostream& output, const Matrix<rows, cols, T>& matrix)
	{
		for (int i = 0 ; i < rows ; i++)
		{
			for (int j = 0 ; j < cols ; j++)
			{
				output << matrix.data[i][j] << " ";  //make a space
			}
			output << endl;
		}
		return output;
	}

	//function that returns a reference to the cell at the given index [i,j].
	T& operator()(int i, int j)
	{
		return data[i][j];

	}
};


//Student Bshara Haj, 212590186.
//Student Obaeda Khatib, 201278066.
#pragma once
#include"Matrix.h"

using std::endl;
template <int rows = 1, int cols = 1, typename T = int>

class MatrixContainer 
{
	int arraySize; //number of matrices it can contain 
	int quantity; //number of the matrices into it. 
	Matrix <rows, cols, T>* matrixArr;

public:
	//Constructor
	MatrixContainer()
	{
		arraySize = 1;
		quantity = 0;
		matrixArr = new Matrix<rows, cols, T>[arraySize];
	}

	//Destructor
	~MatrixContainer()
	{
		delete[] matrixArr;
	}

	//function the adds a matrix to the container
	void addMatrix(const Matrix<rows, cols, T> newMat)
	{
		matrixArr[quantity] = newMat;
		this->quantity++;
		if (quantity == arraySize) //checking if the matrix is full, so to resize it accordingly. 
		{
			reSize();
		}

	}

	//function that removes the last matrix from the container.
	void removeLastMatrix()
	{
		matrixArr[quantity - 1] = NULL;
		this->quantity--;
		if (quantity <= (arraySize / 4)) //checking if the matrix is 1/4 full, so to resize it accordingly. 
		{
			reSize();
		}
	}

	//function that returns a reference to the matrix at the given index "i". 
	Matrix<rows, cols, T>& operator[](int i)
	{
		return matrixArr[i];
	}

	// function that prints all the matrices in the container.
	friend ostream& operator<<(ostream& output, const MatrixContainer<rows, cols, T>& container)
	{
		int i;
		output << "There are " << container.quantity << " matrices in the container. The matrices:" << endl;
		for (i = 0 ; i < container.quantity ; i++)
		{
			output << container.matrixArr[i];
			output << endl;
		}
		return output;
	}

	//function that returns the amount of matrices in the container.
	int size()
	{
		return this->quantity;
	}

	//function that returns the size of the dynamic array
	int  capacity()
	{
		return this->arraySize;
	}

	//function that resize the array accordingly, when it's full or 1/4 full. 
	void reSize() 
	{
		Matrix<rows, cols, T>* temp = matrixArr;
		if (quantity == arraySize) //when the array is full it duplicates its capacity. 
		{
			arraySize *= 2;
			this->matrixArr = new Matrix<rows, cols, T>[arraySize];
			for (int i = 0 ; i < quantity ; i++)
			{
				this->matrixArr[i] = temp[i];
			}
			delete[] temp;
		}
		else if (quantity <= (arraySize / 4))  //when the array is 1/4 full it minimize its capacity by a half. 
		{
			arraySize /= 2;
			this->matrixArr = new Matrix<rows, cols, T>[arraySize];
			for (int i = 0 ; i < quantity ; i++)
			{
				this->matrixArr[i] = temp[i];
			}
			delete[] temp;
		}
	}


};
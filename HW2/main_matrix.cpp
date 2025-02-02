#include "Matrix.h"

template <int row, int col, typename T>
void printDiag(Matrix<row, col, T>& mat) {
   int number;
   T* diag = mat.getDiag(number);
   for (int i = 0; i < number; i++)
   {
       std::cout << diag[i] << " ";
   }
   std::cout << std::endl;
   delete[] diag;
}
template <int row, int col, typename T>
void print(Matrix<row, col, T>& mat) {
Note : std::cout<<mat should be identical to print(mat) 
   int i, j;
   for (i = 0; i < row; i++)
   {
       for (j = 0; j < col; j++)
       {
           std::cout << mat.data[i][j] << " ";
       }
       std::cout << std::endl;
   }
}

int main() {
   freopen("output_matrix.txt", "w", stdout);

   Matrix<4, 4> mat;
   std::cout << mat << std::endl;

   Matrix<4,4> identity = mat.getIdentityMatrix();
   std::cout << identity << std::endl;

   Matrix<4, 4> res = (identity + 2) * 3;
   std::cout << res << std::endl;

   Matrix<4, 3> mat1(9);
   Matrix<4, 3> mat2(4);

   std::cout << (mat1 - 4) << std::endl;

   mat2(2, 1) = 0;

   const int cell = (2 + mat1 - 1)(1, 2);

   std::cout << "The value of cell 1, 2 is: " << cell << std::endl;

   std::cout << (1 + mat2) << std::endl;

   std::cout << ++mat1 << std::endl;
   std::cout << --mat2 << std::endl;

   std::cout << "Values of mat1 and mat2, before..." << std::endl;
   std::cout << mat1++ << std::endl;
   std::cout << mat2-- << std::endl;

   std::cout << "Values of mat1 and mat2, after..." << std::endl;
   std::cout << mat1 << std::endl;
   std::cout << mat2 << std::endl;

   mat2(0, 0) = 13;

   /*
    * Matrix diagonal is:
    * 1. In case of nxn matrix it's simple all (i, i) cell for all
    * i between 0 and n - 1.
    * 2. In case of nxm matrix it's all cells (i, i) cells for all
    * i between 0 and min(n,m).
    */
   std::cout << "Printing main diagonal of mat2:" << std::endl;
   printDiag(mat2);

   /*
    *
    * Trace of any given Matrix nxm is the sum of main
    * diagonal entries.
    *
    * 
    */
   std::cout << "trace(mat2) = " << int(mat2) << std::endl;
   std::cout << std::endl;

   Matrix<4, 2, double> m1, m2;

   m1(0, 0) = 1;  m1(0, 1) = -1;   //  1 -1
   m1(1, 0) = 3;  m1(1, 1) = 7;    //  3  7
   m1(2, 0) = -5; m1(2, 1) = 0;    // -5  0
   m1(3, 0) = 2; m1(3, 1) = 2;    // -2  2


   std::cout << "Matrix m1: " << std::endl;
   std::cout << m1 << std::endl;
   std::cout << "Printing main diagonal of m1:" << std::endl;
   printDiag(m1);
   std::cout << "trace(m1) = " << double(m1) << std::endl;
   std::cout << std::endl;

   m2(0, 0) = 5;      m2(0, 1) = 1;   //  5  1
   m2(1, 0) = -2;     m2(1, 1) = 2;   // -2  2
   m2(2, 0) = 0;      m2(2, 1) = 6;   //  0  6
   m2(3, 0) = 4;      m2(3, 1) = 8;   //  4  8

   std::cout << "Matrix m2: " << std::endl;
   std::cout << m2 << std::endl;
   std::cout << "Printing main diagonal of m2:" << std::endl;
   printDiag(m2);
   std::cout << "trace(m2) = " << double(m2) << std::endl;
   std::cout << std::endl;

   Matrix<4, 2, double> m3 = m1 + m2;

   std::cout << "Matrix m3 = m1 + m2: " << std::endl;
   std::cout << m3 << std::endl;
   std::cout << "Printing main diagonal of m3:" << std::endl;
   printDiag(m3);
   std::cout << "trace(m3) = " << double(m3) << std::endl;
   std::cout << std::endl;

   Matrix<4, 2, double> m4 = m3 + double(1) - m2 * double(2) + m1;
   ++m4;
   std::cout << "Matrix m4 = m3 + 1 - 2*m2 + m1:" << std::endl;
   std::cout << "++m4" << std::endl;
   std::cout << "m4:" << std::endl;
   std::cout << m4 << std::endl;
   std::cout << "Printing main diagonal of m4:" << std::endl;
   printDiag(m4);
   std::cout << "trace(m4) = " << double(m4) << std::endl;
   std::cout << std::endl;


   Matrix<2, 4, float> mf1(2.5f);

   mf1(0, 0) += 3; mf1(0, 3) -= 0.5f;
   mf1(1, 1) = 0; mf1(1, 2) = 0;
   ++mf1;
   mf1 = (-mf1 + 1.7f) + mf1 * 0.25f - float(1);
   std::cout << "Matrix mf1:" << std::endl;
   std::cout << mf1 << std::endl;
   std::cout << "Printing main diagonal of mf1:" << std::endl;
   printDiag(mf1);
   std::cout << "trace(mf1) = " <<float(mf1) << std::endl;
   std::cout << std::endl;

   return 0;
}

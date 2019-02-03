#include <iostream>
#include "Matrix.hpp"
using namespace std;

int main()
{
	string str = "matB.txt";
	Matrix B, A, C;
	A.readFile("matA2.txt");
	cout << "\nisIdentity : " << A.isIdentity();
	cout << "\nisSymmetric : " << A.isSymmetric();
	cout << "\nisDiagonal : " << A.isDiagonal();
	cout << "\nisNull: " << A.isNull();
	cout << "\nisDiagonallyDominant : " << A.isDiagonallyDominant();

	B.readFile(str);
	C.addition(B, B);
	C.display();
	C.substract(A, A);
	C.display();
	C.multiply(A, B);
	C.display();
	C.scalarMultiply(4);
	C.display();
}

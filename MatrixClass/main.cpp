#include <iostream>
#include "Matrix.hpp"
using namespace std;

int main()
{
	string str = "matB.txt";
	Matrix B, A, C;
	A.readFile("matA2.txt");
	cout << "\nisIdentity : " << boolalpha << A.isIdentity();
	cout << "\nisSymmetric : " << A.isSymmetric();
	cout << "\nisDiagonal : " << A.isDiagonal();
	cout << "\nisNull: " << A.isNull();
	cout << "\nisDiagonallyDominant : " << A.isDiagonallyDominant();
	B.readFile(str);
	C.addition(B, B);
	cout << "\nAddition : ";
	C.display();
	/*
	cout << "\nAddition  + : ";
	C = B + B;
	C.display();
*/
	C.substract(A, A);
	cout << "\nSubstraction : ";
	C.display();
	C.multiply(A, B);
	cout << "\nMultiplication : ";
	C.display();
	C.scalarMultiply(4);
	cout << "\nScalar Multiplication : ";
	C.display();
}

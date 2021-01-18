#include <iostream>
#include "Matrix.hpp"
using namespace std;

int main()
{
	string str = "matB.txt";
	Matrix B, A, C;
	A.readFile("matDD.txt");
	B.readFile(str);
	cout << "Before";
	A.display();
	A.pivoting();
	cout << "After";
	A.display();
	C = A.guassElimination(B);
	cout << "\nTrace : " << A.trace();
	cout << "\nisOrthogonal : " << boolalpha << A.isOrthogonal();
	cout << "\nOverloading == : " << (A == A) << endl;
	cout << "A[][] : " << A[2][2] << endl;
	A[2][3] = 5;
	A.display();
	cout << "Result";
	C.display();
	/*
	cout << "\nisIdentity : " << boolalpha << A.isIdentity();
	cout << "\nisSymmetric : " << A.isSymmetric();
	cout << "\nisDiagonal : " << A.isDiagonal();
	cout << "\nisNull: " << A.isNull();
	cout << "\nisDiagonallyDominant : " << A.isDiagonallyDominant();
	B.readFile(str);

	C.addition(B, B);
	cout << "\nAddition : ";
	C.display();
	C = B + B;
	C.display();
	cout << "\nAddition  + : ";
	Matrix d = B + B;
	d.display();

	C.substract(A, A);
	cout << "\nSubstraction : ";
	C.display();
	//C.multiply(A, B);
	C = A * B;
	cout << "\nMultiplication : ";
	C.display();
	C.scalarMultiply(4);
	cout << "\nScalar Multiplication : ";
	C.display();*/
	return 0;
}

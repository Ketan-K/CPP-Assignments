//
// Created by KetanKatore on 25/1/19.
//

#ifndef MATRIXCLASS_MATRIX_HPP
#define MATRIXCLASS_MATRIX_HPP

class Matrix
{
  public:
	unsigned short int row, column;
	double **matrix;
	Matrix();												   //Null Constructor
	Matrix(const Matrix &);									   //Copy Constructor
	Matrix(unsigned short int row, unsigned short int column); //Constructor to initialize matrix & allocate memory
	~Matrix();												   // Destructor

	void init(unsigned short int row, unsigned short int column); //Initialize object

	void addition(const Matrix &, const Matrix &); //Addition of two matrices
	//Matrix addition(Matrix &);
	void substract(const Matrix &, const Matrix &); //Substration of two matrices
	void multiply(const Matrix &, const Matrix &);  //Multiplacation of two matrices

	void scalarMultiply(double); //Scalar Multiplacation

	bool isIdentity();			 //Check Matrix is Identity or not
	bool isSquare();			 //Check Matrix is Square or not
	bool isSymmetric();			 //Check Matrix is Symmetric or not
	bool isNull();				 //Check Matrix is Null not
	bool isDiagonal();			 //Check Matrix is Diagonal or not
	bool isDiagonallyDominant(); //Check Matrix is Diagonally Dominant or not
	bool isOrthogonal();
	void accept();  //Read matrix from console
	void display(); //write matrix to console

	bool readFile(const std::string filename); //Read matrix from file

	Matrix operator+(const Matrix &);
	Matrix operator-(const Matrix &);
	Matrix operator*(const Matrix &);
	void operator=(const Matrix &);
	Matrix transpose();
	double trace();
	void upperTriangular();
	Matrix makeAugmented(const Matrix &);
	Matrix guassElimination(const Matrix &);
};

#endif //MATRIXCLASS_MATRIX_HPP

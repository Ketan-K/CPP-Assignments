//
// Created by root on 25/1/19.
//

#ifndef MATRIXCLASS_MATRIX_HPP
#define MATRIXCLASS_MATRIX_HPP

class Matrix
{
  public:
	unsigned short int row, column;
	double **matrix;
	Matrix();
	~Matrix();												   //Null Constructor
	Matrix(unsigned short int row, unsigned short int column); //Constructor to initialize matrix & allocate memory
	void init(unsigned short int row, unsigned short int column);
	void addition(Matrix &, Matrix &);  //Addition of two matrix
	void substract(Matrix &, Matrix &); //Addition of two matrix
	void multiply(Matrix &, Matrix &);  //Addition of two matrix
	void scalarMultiply(double);		//Addition of two matrix
	bool isIdentity();
	bool isSquare();
	bool isSymmetric();
	bool isNull();
	bool isDiagonal();
	bool isDiagonallyDominant();
	//Matrix(Matrix &);
	void accept();
	void display();
	bool readFile(const std::string filename);
};

#endif //MATRIXCLASS_MATRIX_HPP

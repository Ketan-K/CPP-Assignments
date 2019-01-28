//
// Created by root on 25/1/19.
//

#ifndef MATRIXCLASS_MATRIX_HPP
#define MATRIXCLASS_MATRIX_HPP


class Matrix {
private:
	unsigned short int row,column;
	double **matrix;
public:
	Matrix();//Null Constructor
	Matrix(unsigned short int row,unsigned short int column);//Constructor to initialize matrix & allocate memory
	//Matrix add(Matrix &);//Addition of two matrix
	//Matrix(Matrix &);
	void accept();
	void display();
	bool readFile(const std::string filename);
};


#endif //MATRIXCLASS_MATRIX_HPP

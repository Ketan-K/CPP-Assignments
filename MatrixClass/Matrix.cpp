//
// Created by root on 25/1/19.
//
#include <iostream>
#include <fstream>
#include "Matrix.hpp"
using namespace std;
Matrix::Matrix()
{
	init(0, 0);
}
Matrix::Matrix(unsigned short int row, unsigned short int column)
{
	init(row, column);
}
void Matrix::init(unsigned short int row, unsigned short int column)
{
	this->row = row;
	this->column = column;
	this->matrix = new double *[row];
	for (int i = 0; i < row; i++)
	{
		this->matrix[i] = new double[column];
	}
}
void Matrix::accept()
{
	for (int i = 0; i < this->row; i++)
		for (int j = 0; j < this->column; j++)
			cin >> matrix[i][j];
}
void Matrix::display()
{
	cout << "\nMatrix : \n";
	//cout << "Rows : " << row << "\t Cols: " << column;
	for (int i = 0; i < this->row; i++)
	{
		for (int j = 0; j < this->column; j++)
		{
			cout << "\t" << matrix[i][j];
		}
		cout << endl;
	}
}

void Matrix::addition(Matrix &op1, Matrix &op2)
{
	if (op1.row != op2.row || op1.column != op2.column)
	{
		cerr
			<< "Addition not possible..";
		return;
	}
	init(op1.row, op1.column);
	for (int i = 0; i < op1.row; i++)
		for (int j = 0; j < op1.column; j++)
			this->matrix[i][j] = op1.matrix[i][j] + op2.matrix[i][j];
}

void Matrix::substract(Matrix &op1, Matrix &op2)
{
	if (op1.row != op2.row || op1.column != op2.column)
	{
		cerr << "Substraction not possible..";
		return;
	}
	init(op1.row, op1.column);
	for (int i = 0; i < op1.row; i++)
		for (int j = 0; j < op1.column; j++)
			this->matrix[i][j] = op1.matrix[i][j] - op2.matrix[i][j];
}
void Matrix::multiply(Matrix &op1, Matrix &op2)
{
	if (op1.column != op2.row)
	{
		cerr << "Multiplication not possible..";
		return;
	}
	init(op1.row, op2.column);
	for (int i = 0; i < op1.row; i++)
		for (int j = 0; j < op2.column; j++)
		{
			this->matrix[i][j] = 0;
			for (int k = 0; k < op1.column; k++)
			{
				this->matrix[i][j] += op1.matrix[i][k] * op2.matrix[k][j];
			}
		}
}

bool Matrix::readFile(const std::string filename)
{
	ifstream file;
	file.open(filename);
	if (!file)
		return false;
	unsigned short int row, column;
	file >> row;
	file >> column;
	init(row, column);
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			file >> this->matrix[i][j];
		}
	}
	return true;
}
Matrix::~Matrix()
{
	if (row > 0 || column > 0)
	{
		for (unsigned short int i = 0; i < row; i++)
		{
			delete[] matrix[i];
		}
		delete[] matrix;
		row = 0;
		column = 0;
	}
}
void Matrix::scalarMultiply(double k)
{
	for (unsigned short int i = 0; i < row; i++)
		for (unsigned short int j = 0; j < column; j++)
			this->matrix[i][j] *= k;
}
bool Matrix::isSquare()
{
	if (this->row == this->column)
		return true;
	return false;
}
bool Matrix::isIdentity()
{
	if (!isSquare())
		return false;
	for (unsigned short int i = 0; i < row; i++)
		for (unsigned short int j = 0; j < column; j++)
			if (i == j)
			{
				if (this->matrix[i][j] != 1)
					return false;
			}
			else
			{
				if (this->matrix[i][j] != 0)
					return false;
			}
	return true;
}
bool Matrix::isSymmetric()
{
	if (!isSquare())
		return false;
	for (unsigned short int i = 0; i < row; i++)
		for (unsigned short int j = 0; j < i; j++)
			if (this->matrix[i][j] != this->matrix[j][i])
				return false;
	return true;
}

bool Matrix::isNull()
{
	for (unsigned short int i = 0; i < row; i++)
		for (unsigned short int j = 0; j < column; j++)
			if (this->matrix[i][j] != 0)
				return false;
	return true;
}
bool Matrix::isDiagonal()
{
	if (!isSquare())
		return false;
	for (unsigned short int i = 0; i < row; i++)
		for (unsigned short int j = 0; j < column; j++)
			if (i != j)
			{
				if (this->matrix[i][j] != 0)
					return false;
			}
	return true;
}
bool Matrix::isDiagonallyDominant()
{
	double check = 0;
	if (!isSquare())
		return false;
	for (unsigned short int i = 0; i < row; i++, check = 0)
	{
		for (unsigned short int j = 0; j < column; j++)
		{
			if (i != j)
			{
				if (this->matrix[i][j] < 0)
				{
					this->matrix[i][j] *= -1;
				}
			}
			check += this->matrix[i][j];
		}
		//	cout << "ME : " << check << endl;
		if (this->matrix[i][i] < check)
			return false;
	}
	return true;
}

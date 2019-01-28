//
// Created by root on 25/1/19.
//
#include<iostream>
#include<fstream>
#include "Matrix.hpp"
using namespace std;
Matrix::Matrix()
{}
Matrix::Matrix(unsigned short int row,unsigned short int column)
{
	this->row=row;
	this->column=column;
	matrix=new double*[row];
	for(int i=0;i<row;i++)
	{
		matrix[i]=new double[column];
	}
}
void Matrix::accept()
{
	for(int i=0;i<this->row;i++)
			for(int j=0;j<this->column;j++)
			cin>>matrix[i][j];
}
void Matrix::display()
{
	for(int i=0;i<this->row;i++)
	{
			for(int j=0;j<this->column;j++)
			{
			cout<<"\t"<<matrix[i][j];
			}
		cout<<endl;
	}
}

/*
Matrix Matrix::add(Matrix &op2)
{
	if(this->row!=op2.row || this->column==op2.column)
	return Matrix();
	
	for(int i=0;i<this->row;i++)
			for(int j=0;j<this->column;j++)
			temp.matrix[i][j];
	
}
*/

bool Matrix::readFile(const std::string filename)
{
	ifstream fread;
	fread.open(filename);
	if(!fread)
		return false;
	unsigned short int row,column;
	cout<<row<<column;
	Matrix mat(row,column);
	fread>>row>>column;
	for(int i=0;i<this->row;i++)
			for(int j=0;j<this->column;j++)
				fread>>mat.matrix[i][j];
	mat.display();

	return true;
	
}


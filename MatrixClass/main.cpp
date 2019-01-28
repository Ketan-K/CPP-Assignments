#include <iostream>
#include"Matrix.hpp"
using namespace std;

int main() {
	Matrix  A(2,2);
	//A.accept();
	//A.display();
	string str;
	cin>>str;
	Matrix B;
	if(B.readFile(str))
	B.display();
	else
	cout<<"Failure...";
    return 0;
}

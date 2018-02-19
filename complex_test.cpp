#include <iostream>
#include "complex.h"
using namespace std;

//返回值非local变量，所以返回引用
ostream& operator <<(ostream& os, const complex& x)
{
	return os<<'('<<real(x) <<','<<imag(x)<<')';
}

int main()
{
	complex c1(2,1);
	complex c2;
	complex* p = new complex(4);
	cout<<c1<<endl;
	cout<<c2<<endl;

	c2 = c1 + 5;
	
	cout<<c2<<endl;
	return 0;
}
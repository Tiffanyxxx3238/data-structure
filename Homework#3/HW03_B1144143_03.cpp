#include <bits/stdc++.h>
using namespace std;
//define a structor to show ax^2+bx+c
struct Quadratic{
	double a, b, c;//a is x^2 num, b is x num, c is constant
	Quadratic(double a=0, double b=0, double c=0):a(a),b(b),c(c) {}//define a function, and if not has num, and all will be 0
	
	Quadratic operator+(const Quadratic& other) const{//operator overloading , to define two Quadratic add 
		return {a+other.a,b+other.b,c+other.c};
	}
	double Eval(double x) const{//a function to count the polynomial result of x
		return a*x*x+b*x+c;
	}
};
//a function to print and show the polynomial
void Print(const Quadratic& q){
	cout<<q.a<<"x^2+"<<q.b<<"x+"<<q.c;
}
//a function to read user input polynomial num
void Read(Quadratic& q){
	cout<<"Entr a, b, c for ax^2+bx+c: ";
	cin>>q.a>>q.b>>q.c; 
}

int main(){
	Quadratic q1, q2, q3;
	//read first polynomial num
	cout<< "Enter first polynomial:\n";
	Read(q1);
	//read second polynomial num
	cout<< "Enter second polynomial:\n";
	Read(q2);
	//show first polynomial
	cout<<"First polynomial:";
	Print(q1);
	//show second polynomial
	cout<<"\nSecond polynomial: ";
	Print(q2);
	//q3 is the first and second polynomial answer
	q3=q1+q2;
	//show the answer(first+second=third)
	cout<<"\nSum of polynomials: ";
	Print(q3);
	//ask user to input the x's num
	double x;
	//show input x and count to answer
	cout<<"\nEnter x to evaluate: ";
	cin>>x;
	cout<< "Value at x= "<<x<<" is: "<<q3.Eval(x)<<endl; 
	return 0;
} 

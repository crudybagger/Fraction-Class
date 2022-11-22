#include <iostream>
#include <algorithm>
#include <stdexcept>
using namespace std;
class fraction{
	int num, den;
	public:
	fraction(){
		num = 0;
		den = 1;
	}
	fraction(int n, int d){
		if(d == 0) throw std::invalid_argument("Denomenator cannot be 0");
		num = n;
		den = (d == 0) ? 1 : d;
	}
	fraction reduced(){
		return fraction(num/__gcd(num, den), den/__gcd(num, den));
	}
	fraction operator* (fraction &f){
		return fraction(num*f.num, den*f.den).reduced();
	}
	fraction operator+ (fraction &f){
		return fraction(num*f.den + den*f.num, den*f.den).reduced();
	}
	fraction operator- (fraction &f){
		return fraction(num*f.den - den*f.num, den*f.den).reduced();
	}
	fraction operator/ (fraction &f){
		return fraction(num*f.den, den*f.num).reduced();
	}
	friend ostream &operator<<( ostream &output, const fraction &f ) { 
		output << f.num << "/" << f.den;
		return output;
	}
	friend istream &operator>>( istream &input, fraction &f ) { 
		input >> f.num >> f.den;
		return input;            
	}
};

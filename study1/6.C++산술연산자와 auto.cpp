#include<iostream>

using namespace std;

int main(){

	// + - * / % 산술 연산자

	int a = 10;
	int b = 3;

	int c = a + b;
	int d = a - b;
	int e = a * b;
	int f = a / b;
	int g = a % b;
	
	cout << c << endl;
	cout << d << endl;
	cout << e << endl;
	cout << f << endl;
	cout << g << endl;

	//auto 

	auto n = 100; // n은 int
	auto x = 1.5; // x 는 float
	auto y = 1.3e12L; //y는 long long

	return 0;
}
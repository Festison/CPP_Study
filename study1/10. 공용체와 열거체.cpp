#include<iostream>

using namespace std;

int main() {
	//공용체(union)
	//서로 다른 데이터형을 한 번에 한 가지만 보관할 수 있음

	union MyUnion
	{
		int intVal;
		long longVal;
		float floatVal;
	};

	MyUnion test;
	test.intVal = 3;
	cout << test.intVal << endl;
	test.longVal = 33;
	cout << test.intVal << endl;
	cout << test.longVal << endl;
	test.floatVal = 33.3;
	cout << test.intVal << endl;
	cout << test.longVal << endl;
	cout << test.floatVal << endl;

	//열거체(enum)
	//기호 상수르 만드는 것에 대한 또다른 방법

	enum spectrum {red,orange,tellow,green,
	blue, violet, indigo, ultraviolet};
	/*
	1. spectrum을 새로운 데이터형 이름으로 만든다.
	2. red, orange, yellow.. 0 에서부터 7까지 정수 값을 각각
	나타내는 기호 상수로 만든다.
	*/

	spectrum a = orange;
	cout << a << endl;

	int b;
	b = blue;
	b = blue + 3;
	cout << b << endl;

	return 0;

}
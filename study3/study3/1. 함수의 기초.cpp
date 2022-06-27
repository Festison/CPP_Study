#include<iostream>

using namespace std;

void hellCPP(int);
//함수(매개변수)

int sub1() {
	/*
	1. 함수 정의 제공
	2. 함수 원형 제공
	3. 함수 호출
	리턴값이 있는 타입
	리턴값이 없는 타입
	*/
	int times;
	cout << "정수를 입력하시오." << endl;
	cin >> times;
	hellCPP(times);

	return 0;
}

void hellCPP(int n) {
	for (int i = 0; i < n; i++)
		cout << "Hello, C++!" << endl;
}
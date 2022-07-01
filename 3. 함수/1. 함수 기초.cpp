#include<iostream>
using namespace std;

// 오늘의 주제 : 함수(프로시저, 메서드, 루틴)
/*
input으로 무엇을 받고, output으로 무엇을 뱉을지 정해준다

반환타입 함수이름([인자타입 매개변수])
{

	함수 내용

	return ~~~;
}
*/
// Hello World를 출력하는 함수
// input : 없음 / output : 없음
// 타입 : int float double char ~~ void

void printHelloWorld(void)
{
	cout << "Hello World" << endl;
}

// 정수를 입력 받아서 , 콘솔에 출력하는 함수를 만들어보자
// input : int / output : 없음
void PrintNumber(int number) // 매개 변수
{
	cout << "넘겨주신 숫자는 " << number  << " 입니다" << endl;
}

// 2를 곱하고 결과물을 뱉는 함수를 만들어보자
// input : int / output : int

int MultplyBy2(int a)
{
	int result = a * 2;
	return result;
}

// 두 숫자를 곱해서 결과물을 뱉는 함수를 만들어보자
// input : int, int / output : int

int MultplyBy(int a, int b)
{
	int c = a * b;
	return c;
}
int main()
{
	int a = 3;
	int b = 5;
	int result = MultplyBy(b, a);
	int c= MultplyBy2(3);
	PrintNumber(result);
	printHelloWorld();
	return 0;
}
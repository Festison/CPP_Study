#include<iostream>
using namespace std;


// F5
// F10 프로시저 단위로 실행 프로시저는 함수의 다른이름
// F11

void PrintNumber(int number) 
{
	cout << "넘겨주신 숫자는 " << number << " 입니다" << endl;
}

int MultiplyBy(int a, int b)
{
	int c = a * b;
	return c;

}
int main()
{
	int a = 3;
	int b = 5;
	int result = MultiplyBy(b, a);

	PrintNumber(result);
	return 0;
}
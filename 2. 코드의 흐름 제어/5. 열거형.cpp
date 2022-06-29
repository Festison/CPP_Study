#include<iostream>
using namespace std;


const int SCISSORS = 1;
const int ROCK = 2;
const int PAPER = 3;

// 숫자를 지정 안하면 첫 값은 0부터 시작
// 그 다음 값들은 이전 값 + 1
enum ENUM_SRP
{
	ENUM_SCISSORS =1,
	ENUM_ROCK,
	ENUM_PAPER

};

// #가 붙으면 -> 전처리 지시문
// 1)전처리 2) 컴파일 3) 링크
#define DEFINE_SCISSORS 1 
#define DEFINE_TEST cout<<"Hello World"<<endl;

int main()
{

	DEFINE_TEST;

	if (ENUM_SCISSORS) // 1이 대입 
	{

	}

	return 0;
}
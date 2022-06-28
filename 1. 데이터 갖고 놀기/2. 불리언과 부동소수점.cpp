#include<iostream>
using namespace std;


// 불리언과 실수

// 불리언(boolean) 참/거짓
bool isHighLevel = true; // 1이 대입
bool isPlayer = true; 
bool isMale = false;  // 0이 대입

// bool = 1바이트 정수

//실수 (부동소수점)
// ex) float double

//부동 소수점: . 을 유동적으로 움직여서 표현하는 방법
//1) 정규화 = 0.31415926535 * 10 
//2) 31415926535 (유효숫자) 1 (지수)

float attackSpeed = -3.375f; // 4바이트
double attackSpeed2 = 123.4123; // 8바이트

// ex) -3.375라는 값을 저장
// 1) 2진수 변환 = (3) + (0.375) = 0b11 + Ob0.011 = 0b11.011
// 2) 정규화 0b11.011 * 2^1
// 1(부호) 1(지수) 1011(유효숫자)
// 단 지수는 unsigned byte라고 가정하고 숫자 +127을 만들어준다
// 예쌍 결과 : 0b 1 100000000 10110000'0000'0000'0000'0000

// 프로그래밍을 할 때 부동소수점은 항상 ' 근사값' 이라는 것을 기억
// 실수 2개를 ==으로 비교하는 것은 지양

int main() 
{

	cout << isHighLevel << endl;
	cout << attackSpeed << endl;
	cout << attackSpeed2 << endl;

	return 0;
}
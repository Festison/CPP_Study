#include<iostream>
using namespace std;

void Print(int a)
{
	cout << a << endl;
}

void Print(float a) // 함수 오버로딩
{
	cout << a << endl;
}

void Print(double a)
{
	cout << a << endl;
}

void Print(const char* a)
{
	cout << a << endl;
}

class Knight
{
public:

public:
	int _hp = 100;
};

template<typename T> // 경우에 따라서 자료형을 사용
void Print(T a)
{
	cout << a << endl;
}

template<typename T1, typename T2>
void Print(T1 a, T2 b)
{
	cout << a << " " << b << endl;
}

template<typename T>
T Add(T a, T b)
{
	return a + b;
}

 // 연산자 오버로딩 (전역함수 버전)
ostream& operator<<(ostream& os, const Knight& k)
{
	os << k._hp;
	return os;
}

// 템플릿 특수화
template<>
void Print(Knight a)
{
	cout << "Knight !!!!!" << endl;
	cout << a._hp << endl;
}

int main()
{
	// 템플릿 : 함수나 클래스를 찎어내는 틀
	// 1) 함수 템플릿
	// 2) 클래스 템플릿
	

	Print<int>(50); // 명시적 자료형 설정 
	Print(50.0f);
	Print(50.0);
	Print("Hello World");

	int result1 = Add(1, 2);
	float result2 = Add<float>(1.11f, 2.22f);

	Knight k1;
	Print(k1);

	return 0;

}
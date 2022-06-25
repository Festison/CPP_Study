#include<iostream>

using namespace std;

int main() {
	
	int a;
	cin >> a;

	switch (a)
	{
	case 1:
		cout << "입력하신 값은 1 입니다.";
		break;
	case 2:
		cout << "입력하신 값은 2입니다.";
		break;

	default:
		cout << "입력하신 값은 1,2 이외의 다른 값입니다.";
	}

	cout << "스위치문이 끝났습니다.";

	return 0;
}
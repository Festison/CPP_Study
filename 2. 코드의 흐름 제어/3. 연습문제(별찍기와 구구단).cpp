#include<iostream>
using namespace std;

int main()
{
	// 별찍기)
	// 유저들이 어떤 정수를 입력하면 n*n개의 별을 찍었으면 좋겠습니다.

	int star;
	cin >> star;

	for ( int i= 0; i < star; i++)
	{
		for (int j = 0; j < star; j++)
		{
			cout << "*";
		}
		cout << endl;
	}

	for (int i = 0; i < star; i++)
	{
		for (int j = 0; j < i+1; j++)
		{
			cout << "*";
		}
		cout << endl;
	}

	for (int i = 0; i < star; i++)
	{
		for (int j = 0; j < (star - i); j++)
		{
			cout << "*";
		}
		cout << endl;
	}

	// 구구단)

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			cout << i << "*" << j << " = " << i * j << endl;
		}

	}

	return 0;
}
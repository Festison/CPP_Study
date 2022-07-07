#include<iostream>
using namespace std;

// 문자열과 관련된 연습문제

// 문제1) 문자열 길이를 출력하는 함수
int StrLen(const char* str)
{
	int count = 0; // str이라는 문자열의 길이를 반환

	while (str[count] != '\0')
	{
		count++;
	}

	return count;

}

// 문제2) 문자열 복사 함수
#pragma warning(disable: 4996)
char* StrCpy(char* dest, char* src)
{
	int i = 0;

	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}

	dest[i] = '\0';
	return dest;

}

// 문제3) 문자열을 덧붙이는 함수
#pragma warning(disable: 4716)
char* StrCat(char* dest, char* src)
{
	int len = StrLen(dest);

	int i = 0;
	while (src[i] != '\0')
	{
		dest[len + i] = src[i];
		i++;
	}

	dest[len + i] = '\0';

	return dest;

}

// 문제4) 두 문자열을 비교하는 함수
int StrCmp(char* a, char* b)
{
	int i = 0;

	while (a[i] != '\0' || b[i] != '\0')
	{
		if (a[i] > b[i])
		{
			return 1;
		}
		if (a[i]<b[i])
		{
			return -1;
		}
	}

	return 0;

}

// 문제5) 문자열을 뒤집는 함수
void ReverseStr(char* str)
{
	int len = StrLen(str);

	for (int i = 0; i < len / 2; i++)
	{
		int temp = str[i];
		str[i] = str[len - 1 - i];
		str[len - 1 - i] = temp;
	}
}

int main()
{
	const int BUF_SIZE = 100;

	char a[BUF_SIZE] = "Hello";
	char b[BUF_SIZE] = "World";

	int len = StrLen(a);

	cout << len << endl;

	StrCpy(b, a);

	cout << b << endl;


	StrCat(a, b); 

	cout << a << endl;

	// 주소가 다르기 떄문에 다르다 출력 내용물 비교가 아니다.
	if (a == b)
	{
		cout << "같다" << endl;
	}
	else
	{
		cout << "다르다" << endl; 
	}

	int value = StrCmp(a, b);
	cout << value << endl;

	ReverseStr(a);

	cout << a << endl;

	return 0;

}
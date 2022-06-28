#include<iostream>
using namespace std;

//char 은 정수지만 '문자' 의미를 나타내기 위해 사용
// char : 알파벳 / 숫자 문자를 나타낸다
// wchar_t : 유니코드 문자를 나타낸다

char ch = 97; // ASCII 코드로인해서 A가 출력
char ch2 = 'a'; //문자의 의미로 작은 따옴표 '' 사용
char ch3 = '1';
char ch4 = 'a' + 1;

//전 서계 모든 문자에 대해 유일 코드를 부여한 것이 유니코드
//유니코드는 표기 방식이 여러가지가 있는데 대표적으로 UTF8 UTF16이 있다.

wchar_t wch = L'안';

//Escape Sequence
// 표기하기 애매한 애들을 표현
// \0 = 아스키코드0 = NULL
// \t = 아스키코드9 = tab
// \n = 아스키코드10 = LineFeed (한줄 아래로)
// \r = 아스키코드13= Carriagereturn (커서 <<)

// 문자열
// 문자들이 열을 지어서 모여 있는 것 
// 끝은 NULL (0)

char str[] = { 'h','e','l','l','o','\0'};
char str2[] = "Hello World"; // 마지막에 0 값떄문에 배열의 크기가 12로잡힌다.

int main()
{
	cout << ch << endl;
	cout << ch2 << endl;
	cout << ch3 << endl;
	cout << ch4 << endl;

	wcout.imbue(locale("kor"));
	wcout << wch << endl;

	cout << str << endl;
	cout << str2 << endl;

	return 0;

}
#include<iostream>
#include <cstring>

using namespace std;

int main() {

	const int Size = 15;
	char name1[Size];
	char name2[Size] = "C++programing";

	cout << "안녕하세요! 저는" << name2;
	cout << "입니다! 성함이 어떻게 되시나요?\n";
	cin.getline(name1, Size);
	cout << "음," << name1 << "씨,당신의 이름은";
	cout << strlen(name1) << "자입니다만\n";
	cout << sizeof(name1) << "바이트 크기의 배열에 저장되었습니다.\n";
	name2[3] = '\0';
	cout << "제 이름의 첫 세문자는 다음과 같습니다: ";
	cout << name2 << endl;

	//C++에서 문자열을 다루는 방법 중 하나인 string 
	/*
	c스타일로 string 객체를 초기화할 수 있다.
	cin을 사용하여 string 객체에 키보드 입력을 저장할 수 있다.
	cout을 사용하여 string 객체를 디스플레이할 수 있따.
	배열 표기를 사용하여 string 객체에 저장되어 있는 개별적인 문자들에 접근할 수 있다.
	배열을 다른 배열에 통로 대입할 수 없다.
	>> string에서는 가능 
	*/
	
	char char1[20];
	char char2[20] = "jauar";
	string str1;
	string str2 = "panda";
	//char1 = char2 와 다르다
	str1 = str2; //맞다
	cout << str1 << endl;

	return 0;
}

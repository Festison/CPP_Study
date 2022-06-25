#include<iostream>

using namespace std;

int sub8() {
	//논리 표현식
	//논리합, 논리곱 , 논리부정 연산자

	//논리합 || 
	//논리곱 &&
	//논리 부정 !

	cout << "당신의 나이를 입력하십시오.";
	int age;
	cin >> age;

	if (age < 0 || age>100) {
		cout << "거짓말 하시면 안됩니다," << endl;
	}
	else if (20 <= age && age <= 29) {
		cout << "당신은 20대 이군요?" << endl;
	}
	else {
		cout << "당신의 나이를 모르겠습니다.";
	}
	return 0;
}
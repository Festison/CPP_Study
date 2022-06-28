#include<iostream>
#include<climits>

using namespace std;

int main(){

	//정수형 : 소수부가 없는 수
	// 음의정수 , 0 , 양의 정수
	//short, int, long, long long  

	short n_short = SHRT_MAX;
	int n_int = INT_MAX;
	long n_long = LONG_MAX;
	long long n_llong = LLONG_MAX;

	cout << "short는" << sizeof n_short << "바이트이다."<< endl;
	cout << "이 바이트의 최대값은" << n_short << "이다." << endl;

	cout << "int는" << sizeof n_int << "바이트이다." << endl;
	cout << "이 바이트의 최대값은" << n_int << "이다." << endl;

	cout << "long는" << sizeof n_long << "바이트이다." << endl;
	cout << "이 바이트의 최대값은" << n_long << "이다." << endl;

	cout << "long long는" << sizeof n_llong << "바이트이다." << endl;
	cout << "이 바이트의 최대값은" << n_llong << "이다." << endl;

	return 0;

}
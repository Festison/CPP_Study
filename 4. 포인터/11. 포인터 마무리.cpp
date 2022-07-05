#include<iostream>
using namespace std;

int main()
{
	// 주소를 담는 바구니
	int* p;

	// 닭장처럼 데이터의 묶음
	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8 };

	// - [배열의 이름]은 배열의 시작 주소값을 가리키는 TYPE* 포인터로 변환 가능!;
	p = arr;

	// - [TYPE형 1차원 배열] 과 [TYPE*형 포인터]는 완전히 호환가능 
	cout << p[0] << endl;
	cout << arr[0] << endl;
	cout << p[5] << endl;
	cout << arr[5] << endl;
	cout << *p << endl;
	cout << *arr << endl;
	cout << *(p+3) << endl;
	cout << *(arr+3) << endl;

	// (2차원 배열 vs 다중 포인터)

	// [1][2][3][4]
	int arr2[2][2] = { {1, 2}, {3, 4} };

	// 주소2[ ] << 4바이트
	// 주소1 [ 주소2 ]
	// pp[ 주소1 ]

	// [1][2]
	// [ 주소 ]
	int(*p2)[2] = arr2; 
	cout << (*p2)[0] << endl;
	cout << (*p2)[1] << endl;
	cout << (*(p2+1))[0] << endl;
	cout << (*(p2+1))[1] << endl;

	cout << p2[0][0] << endl;
	cout << p2[0][1] << endl;
	cout << p2[1][0] << endl;
	cout << p2[1][1] << endl;


	return 0;

}
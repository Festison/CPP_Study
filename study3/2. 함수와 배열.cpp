#include<iostream>

using namespace std;

const int SIZE = 8;

int sumArr(int[], int);

int sub2() {

	int arr[SIZE] = { 1, 2, 4, 8, 16, 32, 64, 128 };
	// arr==&arr[0] 배열의이름이 배열의 첫번쨰 원소를 가르킨다.
	int sum = sumArr(arr, SIZE);

	cout << "함수의 총 합은" << sum << "입니다.";
	return 0;
}

int sumArr(int arr[], int n) {
	int total = 0;

	for (int i = 0; i < n; i++)
		total += arr[i];

	return total;
}


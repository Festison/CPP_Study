#include<iostream>
#include<vector>
using namespace std;

int main()
{
	// STL (Standard Template Library)
	// 프로그래밍할 때 필요한 자료구조/알고리즘들을
	// 템플릿으로 제공하는 라이브러리

	// 컨테이너(Container) : 데이터를 저장하는 객체 (자료구조 Data Structure)

	// vector (동적 배열)
	// - vector의 동작 원리 (size/capacity)
	// - 중간 삽입/삭제
	// - 처음/끝 삽입/삭제
	// - 임의 접근
	
	// 배열	
	const int MAX_SIZE = 10;
	int arr[MAX_SIZE] = { };

	for (int i = 0; i < MAX_SIZE; i++)
	{
		arr[i] = i;
	}

	for (int i = 0; i < MAX_SIZE; i++)
	{
		cout << arr[i] << endl;
	}

	// 동적 배열
	// 매우 중요한 개념 -> 배열을 유동적으로 사용

	// 1) 여유분을 두고 메모리를 할당한다.
	// 2) 여유분까지 꽉 찼으면, 메모리를 증설한다.

	// Q1) 여유분은 얼만큼이 적당할까? 
	// Q2) 증설을 얼만큼 해야 할까?
	// Q3) 기존의 데이터를 어떻게 처리할까?

	// size (실제 사용 데이터 개수)
	// 1 2 3 4 5 6 7

	// capacity (여유분을 포함한 용량 개수)
	// 1 2 3 4 6 9 13 19 28 

	vector<int> v(1000, 0); // 벡터 1000개를 0으로 초기화
	vector<int> v2 = v;

	v.resize(1000); // 데이터 크기를 명시적으로 고정 

	v.reserve(1000); // 데이터 여유분을 명시적으로 고정 
	// 하는 이유 : 기존 데이터를 복사하는 비용을 줄이기 위해서

	for (int i = 0; i < 1000; i++)
	{
		v.push_back(100); // 데이터를 추가
		cout <<v[i]<<" " << v.size() << " " << v.capacity() << endl;
	}

	v.clear(); // 데이터의 크기를 초기화 여유분은 남아	있다.
	vector<int>().swap(v); // 임시벡터를 이용해 여유분 까지 초기화
	cout << v.size() << " " << v.capacity() << endl;

	return 0;

}
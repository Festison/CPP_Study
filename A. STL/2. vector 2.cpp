#include<iostream>
#include<vector>
using namespace std;

int main()
{
	// 컨테이너(Container) : 데이터를 저장하는 객체 (자료구조 Data Structure)

	// vector (동적 배열)
	// - vector의 동장 원리 (size/capacity)
	// - 중간 삽입/삭제 (BAD)
	// - 처음/끝 삽입/삭제 (BAD / GOOD)
	// - 임의 접근

	// 반복자(lterator) : 포인터와 유사한 개념. 컨테이너의 데이터를 가리키고 다음/이전 데이터로 이동 가능
	vector<int>v(10);

	v.reserve(1000);

	for (vector<int>::size_type i = 0; i < v.size(); i++)
	{
		v[i] = i;
	}

	/* vector<int>::iterator it;
	int* ptr;

	it = v.begin();
	ptr = &v[0];

	cout << (*it) << endl;
	cout << (*ptr) << endl; */

	vector<int>::iterator itBegin = v.begin();
	vector<int>::iterator itEnd = v.end();

	// 더복잡해 보이지만 iterator는 vector뿐만이 아니라 다른 컨테이너에도 공통적으로 있는 개념이다.
	for (vector<int>::iterator it = v.begin(); it !=v.end(); ++it)
	{
		cout << (*it) << endl;
	}
	
	int* ptrBegin = &v[0]; // v.begin()._Ptr;
	int* ptrEnd = ptrBegin + 10; // v.end()._Ptr;
	for (int* ptr = ptrBegin; ptr != ptrEnd; ++ptr)
	{
		cout << (*ptr) << endl;
	}

	// const int*;
	vector<int>::const_iterator cit1 = v.cbegin();
	
	for (vector<int>::reverse_iterator it = v.rbegin(); it != v.rend(); ++it) // 거꾸로 시작
	{
		cout << (*it) << endl;
	}

	// vector = 동적 배열 = 동적으로 커지는 배열 = 배열
	// 원소가 하나의 메모리 블록에 연속하게 저장된다.

	// [              ]
	// [0] [1] [2] [3] [4] [ ] [ ]

	v.push_back(1);
	v.pop_back();

	// 3번쨰 데이터는 어디 있습니까?
	v[2] = 3;

	vector<int>::iterator insertIt = v.insert(v.begin() + 2, 5);
	vector<int>::iterator eraseIt1 = v.erase(v.begin() + 2);
	vector<int>::iterator eraseIt2 = v.erase(v.begin() + 2, v.begin() + 4);

	// 쭉~ 스캔을 하면서 3이라는 데이터가 있으면 알괄 삭제하고 싶다.
	for (vector<int>::iterator it = v.begin(); it != v.end();)
	{
		int data = *it;
		if (data == 3)
		{
			it = v.erase(it);
		}
		else
		{
			++it;
		}
	}

	return 0;

}
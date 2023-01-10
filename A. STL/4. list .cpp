#include<iostream>
#include<list>
using namespace std;

// vector : 동적 배열
// [   push   ]
// [   push   ] capacity ]

// Node [  data(4) next(4/8)  ]  -> Node [  data(4) next(4/8)  ] 
class Node
{
public:
	Node* _next;
	int   _data;
};

// 단일 / 이중 / 원형
// list : 연결 리스트 

// [1] -> [2] -> [3] -> [4] -> [5]
// [1] <-> [2] <-> [3] <-> [4] <-> [5]
// [1] <-> [2] <-> [3] <-> [4] <-> [5] <-> [1]


int main()
{
	// list (연결 리스트)
	// - list의 동작 원리
	// - 중간 삽입/삭제 (GOOD / GOOD)
	// - 처음/끝 삽입/삭제 (GOOD / GOOD)
	// - 임의 접근 (i번쨰 데이터는 어디 있습니까?) 느디라.
	
	list<int> li;

	list<int>::iterator itRemember;

	for (int i = 0; i < 100; i++)
	{
		if (i==50)
		{
			itRemember = li.insert(li.end(), i);
		}
		else
		{
			li.push_back(i);
		}
	}

	int size = li.size();

	int first = li.front();
	int last = li.back();

	list<int>::iterator itBegin = li.begin();
	list<int>::iterator itEnd = li.end();

	// list<int>::iterator itTest1 = --itBegin; 맨처음값을 기준으로는 뒤로가면 에러가 일어난다.
	// list<int>::iterator itTest2 = --itEnd; 리스트는 한칸 이동만 지원
	// list<int>::iterator itTest3 = ++itEnd;

	int* ptrBegin = &(li.front());
	int* ptrEnd = &(li.back());

	for (list<int>::iterator it = li.begin(); it != li.end(); ++it)
	{
		cout << *it << endl;
	}

	li.insert(itBegin, 100);

	li.erase(li.begin());

	li.pop_front();

	li.remove(10);

	// * 임의 접근이 안 된다
	// * 중간 삽입/삭제 빠르다
	// 50번 인덱스에 있는 데이터를 삭제
	list<int>::iterator it = li.begin();
	for (int i = 0; i < 50; i++)
	{
		++it;
	}

	li.erase(itRemember);

	return 0;

}
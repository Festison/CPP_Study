#include<iostream>
#include<vector>
#include<list>
#include<deque>
using namespace std;

// vector : 동적 배열
// [          ]

// list : 이중 연결 리스트
// [ ] <-> [ ] <-> [ ] <-> [ ]

// deque : double-ended queue 데크
// [    ]
// [    ]

int main()
{
	// 시퀀스 컨테이너
	// 데이터가 삽입 순서대로 나열되는 형태
	//vector list deque

	// vector와 마찬가지로 배열 기반으로 동작
	// 다만 메모리 할당 정책이 다르다

	// vector
	// [ 1 1 1 ]
	// [       ]      ]

	// deque
	// [     3 3] 양방향으로 데이터를 밀어 넣는 특징이 있다.
	// [1 1 1 2 ]
	// [2       ]
	
	vector<int> v(3, 1);
	deque<int> dq(3, 1);

	v.push_back(2);
	v.push_back(2);

	dq.push_back(2);
	dq.push_back(2);

	dq.push_front(3);
	dq.push_front(3);

	// - deque의 동작 원리
	// - 중간 삽입/삭제    (BAD / BAD)
	// - 처음/끝 삽입/삭제 (GOOD / GOOD)
	// - 임의 접근 (GOOD)

	dq[3] = 10;
	cout << dq[3] << endl;

	return 0;

}
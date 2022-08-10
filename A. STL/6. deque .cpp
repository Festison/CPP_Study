#include<iostream>
#include<vector>
#include<list>
#include<deque>
using namespace std;

// vector : ���� �迭
// [          ]

// list : ���� ���� ����Ʈ
// [ ] <-> [ ] <-> [ ] <-> [ ]

// deque : double-ended queue ��ũ
// [    ]
// [    ]

int main()
{
	// ������ �����̳�
	// �����Ͱ� ���� ������� �����Ǵ� ����
	//vector list deque

	// vector�� ���������� �迭 ������� ����
	// �ٸ� �޸� �Ҵ� ��å�� �ٸ���

	// vector
	// [ 1 1 1 ]
	// [       ]      ]

	// deque
	// [     3 3] ��������� �����͸� �о� �ִ� Ư¡�� �ִ�.
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

	// - deque�� ���� ����
	// - �߰� ����/����    (BAD / BAD)
	// - ó��/�� ����/���� (GOOD / GOOD)
	// - ���� ���� (GOOD)

	dq[3] = 10;
	cout << dq[3] << endl;

	return 0;

}
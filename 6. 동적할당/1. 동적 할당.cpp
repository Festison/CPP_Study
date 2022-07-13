#include<iostream>
using namespace std;

// 실행할 코드가 저장되는 영역 -> 코드 영역
// 전역/정적 변수 -> 데이터 영역
// 지역변수/매개 변수 -> 스택 영역

// 실제 상황)
// - MMORPG 개발시 동접 1명~5만명 일때 몬스터 또한 엄청 많아야한다.
// - 몬스터 생성 이벤트 -> 5분 동안 몬스터가 10배 많이 나오는 이벤트

// 스택 영역
// 함수가 끝나면 같이 정리되는 불안정한 메모리
// 잠시 함수에 매개변수를 넘긴다거나 할때는 OK

// 메모리 영역
// 프로그램이 실행되는 도중에는 무조건 사용된다.

// 희망사항)
// 필요할때만 사용하고, 필요없으면 반납할 수 있는 메모리
// 그러면서도 생성/소멸 시점을 관리할 수 있는 메모리 -> HEAP
// 동적할당과 연관된 함수/연산자 : malloc, free, new, delete, new[], delete[]

// malloc
// 할당할 메모리 크기를 건내준다.
// 메모리 할당 후 시작 주소를 가리키는 포인터를 반환해준다 (메모리 부족 NULL)

// free
// malloc (혹은 기타 calloc, realloc 등의 사촌) 을 통해 할당된 영역을 해제
// 힙관리자가 할당/미할당 여부를 구분해서 관리


// new / delete
// C++에 추가됨
// malloc/free는 함수 new/delete는 연산자

// new[] / delete[]
// new가 malloc에 비해 좋긴 한데 배열과 같이 N개 데이터를 같이 할당하려면?

// malloc/free vs new/delete
// 사용 편의성 -> new/delete 승
// 타입에 상관없이 특정한 크기의 메모리 영역을 할당 받기 위해서는 malloc/free 사용

// 둘의 가장 중요한 차이는 new/delete는 생성타입이 클래스일 경우 생성자/소멸자를 호출해준다.

class Monster
{
public:
	Monster()
	{
		cout << "Monster()" << endl;
	}

	~Monster()
	{
		cout << "~Monster()" << endl;
	}

public:
	int _hp;
	int _x;
	int _y;
};


int main()
{
	// 컴퓨터 프로그램
	// 유저 영역 (메모장, 게임, 곰플레이어)
	// -----------------------------------
	// 커널 영역 (Windows 등의 핵심 코드)

	// 유저 영역) 운영체제에서 제공하는 API 호출
	// 커널 영역) 메모리를 할당해서 건네준다.
	// 유저 영역) 받아서 잘쓴다.

	// 메모리를 한번에 많이받는다. [   [ 12 ]              ]
	// C++에서는 기본적으로 CRT(C런타임 라이브러리)의 [힙 관리자]를 통해서 힙 영역 사용
	// 단, 정말 원한다면 우리가 직접 API를 통해 힙을 생성하고 관리할 수도 있음 (MMORPG 서버 메모리 풀링)


	// void* 는 무엇일까?
	// *가 있으니까 포인터는 포인터 (주소를 담는 바구니)
	// 타고 가면 void 무엇이 있는지 모른다 사용자가 적당히 변환해서 사용
	void* pointer = malloc(sizeof(Monster));

	Monster* m1 = (Monster*)pointer;
	m1->_hp = 100;
	m1->_x = 1;
	m1->_y = 2;

	// Heap Overflow 
	// 유효한 힙 범위를 초과해서 사용하는 문제

	// 만약에 free하지 않으면 메모리 누수가 발생
	free(pointer); // 메모리가 필요없을때 할당을 끝낸다.
	pointer = nullptr;
	m1 = nullptr;

	// Use-After-Free
	// 재 할당시 발생
	m1->_hp = 100;
	m1->_x = 1;
	m1->_y = 2;

	Monster* m2 = new Monster;
	m2->_hp = 200;
	m2->_x = 2;
	m2->_y = 3;
	delete m2;

	Monster* m3 = new Monster[5];
	m3->_hp = 200;
	m3->_x = 2;
	m3->_y = 3;

	Monster* m4 = (m3 + 1);
	m4->_hp = 300;
	m4->_x = 3;
	m4->_y = 4;
	delete[] m3;

	return 0;

}
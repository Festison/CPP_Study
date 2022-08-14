#include<iostream>
#include<vector>
#include<map>
#include<list>
#include<deque>
#include<set>
#include<algorithm>
using namespace std;

class Knight
{

};

Knight* FindKnight()
{

	return nullptr;
}

void Test(int a)
{
	cout << "Test(int)" << endl;
}

void Test(void* ptr)
{
	cout << "Test(*)" << endl;
}

// Nullptr 구현

const
class
{
public:
	// 그 어떤 타입의 포인터와도 치환 가능
	template<typename T>
	operator T* () const
	{
		return 0;
	}

	// 그 어떤 타입의 멤버 포인터와도 치환 가능
	template<typename C, typename T>
	operator T C::* () const
	{
		return 0;
	}

private:
	void operator&() const; // 주소값 &을 막는다.

} _nullptr;

int main()
{
	int* ptr = NULL;
	// 0 NULL

	// 1) 오동작
	Test(0);
	Test(NULL); 
	Test(_nullptr);

	// 2) 가독성
	auto knight = FindKnight();
	if (knight == _nullptr);
	{

	}

	&

	// nullptr_t whoami = _Nullptr;


	return 0;

}
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
public:
	
public:
	// 정의되지 않은 비공개 함수
	void operator =(const Knight& k) = delete; // 함수를 사용 안하겠다는 의미
	

private:
	int _hp = 100;
};

class Admin
{
public:
	void CopyKnight(const Knight& k)
	{
		Knight k1;
		// 복사 연산
		k1 = k;
	}
};

int main()
{
	Knight k1;
	
	Knight k2;

	// 복사 연산자
	k1 = k2;

	return 0;

}
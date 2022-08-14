#include<iostream>
#include<vector>
#include<map>
#include<list>
#include<deque>
#include<set>
#include<algorithm>
using namespace std;

typedef vector<int>::iterator VecIt;

typedef __int64 id;
using id2 = int;

// 1) 직관성
typedef void (*MyFunc)();
using MyFunc2 = void(*)();

// 2) 템플릿

template<typename T>
using List = std::vector<T>;

template<typename T>
struct List2
{
	typedef std:list<T> type;
};

int main()
{
	id playerId = 0;

	List<int> li;
	li.push_back(1);
	li.push_back(2);
	li.push_back(3);



	return 0;

}
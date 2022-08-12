#include<iostream>
#include<vector>
#include<map>
using namespace std;

class Knight
{
public:
	int _hp;
};

int main()
{

	/*
	int a = 3;
	float b = 3.14f;
	double c = 1.23;
	Knight d = Knight();
	const char* e = "Festison";
	*/

	auto a = 3;
	auto b = 3.14f;
	auto c = 1.23;
	auto d = Knight();
	auto e = "Festison";

	// auto는 일종의 조커카드 
	// 형식 연역 (type deduction)
	// 말이 되게 맞춘다 (추론)
	// 추론 규칙은 생각보다 복잡해질 수 있다.

	auto f = &d;
	const auto test1 = b;
	auto* test2 =e;

	// 주의
	// 기본 auto는 const, & 무시
	int& reference = a;
	const int cst = a;

	auto test1 = reference;
	auto test2 = cst;

	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);

	for (vector<int>::size_type i = 0; i <v.size(); i++)
	{
		auto& data = v[i];

		data = 100;
	}

	// 타이핑이 길어지는 경우 auto가 좋다.
	// 가독성을 위해서는 일반적인 자료형을 사용

	map<int, int> m;
	auto ok = m.insert(make_pair(1, 100));

	for (auto it = v.begin(); it != v.end(); it++)
	{
		cout << *it << endl;
	}

	return 0;

}
#include<iostream>
#include<vector>
#include<map>
#include<list>
#include<deque>
#include<set>
#include<algorithm>
using namespace std;

// 람다 : 함수객체를 편하게 만드는 방법

enum class ItemType
{
	None,
	Armor,
	Weapon,
	Jewelry,
	Consumable
};

enum class Rarity
{
	Common,
	Rare,
	Unique
};

class Item
{
public:
	Item() { }
	Item(int itemId, Rarity rarity, ItemType type)
		: _itemId(itemId), _rarity(Rarity), _type(type)
	{

	}

public:
	int _itemId =0;
	Rarity _rarity = Rarity::Common;
	ItemType _type = ItemType::None;
};

int main()
{
	vector<Item> v;
	v.push_back(Item(1, Rarity::Common, ItemType::Weapon));
	v.push_back(Item(2, Rarity::Common, ItemType::Armor));
	v.push_back(Item(3, Rarity::Rare, ItemType::Jewelry));
	v.push_back(Item(4, Rarity::Unique, ItemType::Weapon));

	// 람다 = 함수 객체를 손쉽게 만드는 문법
	// 람다 자체로 C++11에 새로운 기능이 들어간 것은 아니다

	{
		struct FindItem
		{
			FindItem(int itemId, Rarity rarity, ItemType type)
				: _itemId(itemId), _rarity(rarity), _type(type)
			{

			}

			bool operator() (Item& item)
			{
				return item._itemId == itemId && item._rarity == rarity && item._type == type;
			}

			int _itemId;
			Rarity _rarity;
			ItemType _type;
		};

		int itemId = 4;
		Rarity rarity = Rarity::Unique;
		ItemType type = ItemType::Weapon;

		// [ ] 캡처 : 함수 객체 내부에 변수를 저장하는 개념과 유사 
		// 사진을 캠처하듯 스냅샷을 찍는다고 이해
		// 기본 캡처 모드 : 값(복사) 방식(=), 참조 방식(&)
		// 변수마다 캡처 모드를 지정해서 사용 가능 : 값 방식[itemId], 참조 방식[&itemId] 

		auto findByItem = [itemId](Item& item) {return item._itemId == itemId; }; // [&]참조값을 활용 [=] 아이템 값을 활용

		auto findIt = std::find_if(v.begin(), v.end(), FindItem(itemid, rarity, type));

		if (findIt != v.end())
		{
			cout << "아이템ID: " << findIt->_itemId << endl;
		}
	}

	{
		class Knight
		{
		public:
			auto ResetHpJob()
			{
				auto f = [this]() 
				{
					this->_hp = 200;
				};


				return f;

			}

		public:
			int _hp = 100;
		};

		Knight* k = new Knight();
		auto job = k->ResetHpJob();
		delete k;
		job();
	}

	// [캡처](인자값) {구현부}

	return 0;

}
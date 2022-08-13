#include<iostream>
using namespace std;

int Add(int a, int b)
{
	return a + b;
}

int Sub(int a, int b)
{
	return a - b;
}

class Item
{
public:

public:
	int _itemId;  // 아이템 ID
	int _rarity;  // 희귀도
	int _ownerId; // 소지자 ID
};

Item* FindItemByItemId(Item items[], int itemCount, int itemId)
{
	for (int i = 0; i < itemCount; i++)
	{
		Item* item = &items[i]; 
		if (item ->_itemId==itemId)
		{
			return item;
		}
	}

	return nullptr;
}

Item* FindItemByRarity(Item items[], int itemCount, int rarity)
{
	for (int i = 0; i < itemCount; i++)
	{
		Item* item = &items[i]; 
		if (item->_rarity == rarity)
		{
			return item;
		}
	}

	return nullptr;
}

typedef bool(ITEM_SELECTOR)(Item* , int);

Item* FindItem(Item items[], int itemCount, ITEM_SELECTOR* selector, int value)
{
	for (int i = 0; i < itemCount; i++)
	{
		Item* item = &items[i];
		// TODO 동작
		if (selector(item, value))
		{
			return item;
		}
	}

	return nullptr;
}

bool IsRareItem(Item* item, int value)
{
	return item->_rarity >= value;
}

bool ISOwnerItem(Item* item, int ownerId)
{
	return item->_ownerId == ownerId;
}

int main()
{
	int a = 10;

	// 바구니 주소
	// pointer [ 주소 ] -> 주소 [      ]

	typedef int DATA;
	// 1) 포인터		*
	// 2) 변수이름		pointer
	// 3) 데이터 타입	int
	DATA* pointer = &a;

	// 함수
	typedef int(FUNC_TYPE)(int a, int b);

	// 1) 포인터		*
	// 2) 변수이름		fn
	// 3) 데이터 타입	함수 (인자는 int, int 반환은 int)
	FUNC_TYPE* fn;

	// 함수 포인터
	fn = Sub;

	// 함수의 이름은 함수의 시작 주소 (배열과 유사)
	int result = fn(1, 2);
	cout << result << endl;
	
	int result2 = (*fn)(1, 2); // 함수 포인터는 *(접근 연산자)를 붙여도 함수 주소이다.
	cout << result2 << endl;

	Item items[10] = { };
	items[3]._rarity = 2; // RARE
	Item* rareItem = FindItem(items, 10, ISOwnerItem, 100);
	Item* rareItem = FindItem(items, 10, IsRareItem, 100);

	return 0;

}
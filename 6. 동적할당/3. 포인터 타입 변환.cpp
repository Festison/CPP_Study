#include <iostream>
using namespace std;

class Knight
{
public:
	int _hp = 0;
};

class Item
{
public:
	Item()
	{
		cout << "Item()" << endl;
	}

	Item(int itemType) : _itemType(itemType)
	{
		cout << "Item(int itemType)" << endl;
	}

	Item(const Item& item)
	{
		cout << "Item(const Item&)" << endl;
	}

	virtual ~Item()
	{
		cout << "~Item()" << endl;
	}

	virtual void Test()
	{
		cout << "Test Item" << endl;
	}

public:
	int _itemType = 0;
	int _itemDbId = 0;

	char _dummy[4906] = {}; // 이런 저런 정보들로 인해 비대해진
};

enum ItemType
{
	IT_WEAPON = 1,
	IT_ARMOR = 2,
};

class Weapon : public Item
{
public:
	Weapon() : Item(IT_WEAPON)
	{
		cout << "Weapon()" << endl;
		_damage = rand() % 100;
	}

	virtual ~Weapon()
	{
		cout << "~Weapon()" << endl;
	}

	virtual void Test()
	{
		cout << "Test Weapon" << endl;
	}

public:
	int _damage = 0;
};

class Armor : public Item
{
public:
	Armor() : Item(IT_ARMOR)
	{
		cout << "Armor()" << endl;
	}

	virtual ~Armor()
	{
		cout << "~Armor()" << endl;
	}

	virtual void Test()
	{
		cout << "Test Armor" << endl;
	}

public:
	int _defence = 0;
};

void TestItem(Item item)
{

}

void TestItemPtr(Item* item)
{

}

int main()
{
	// 복슴
	{
		// Stack [type(4) dbid(4) dummy(4096) ]
		Item item;

		// Stack [ 주소(4~8) ] -> Heap 주소 [type(4) dbid(4) dummy(4096) ]
		Item* item2 = new Item();
		
		TestItem(item);
		TestItem(*item2);

		TestItemPtr(&item);
		TestItemPtr(item2);

		// 메모리 누수 -> 점점 가용 메모리가 줄어들어서 Crash 발생
		delete item2;
	}

	// 배열
	{
		cout << "----------------------------------" << endl;

		// 진짜 아이템이 100개 있는 것 (스택 메모리에 올라와 있는)
		Item item3[100] = {};

		cout << "----------------------------------" << endl;

		// 아이템을 가리키는 바구니가 100개 실제 아이템은 1개도없다.
		Item* item4[100] = {};

		for (int i = 0; i < 100; i++)
		{
			item4[i] = new Item();
		}

		cout << "----------------------------------" << endl;

		for (int i = 0; i < 100; i++)
		{
			delete item4[i];
		}

		cout << "----------------------------------" << endl;
	}

	// 연관성이 없는 클래스 사이의 포인터 변환 테스트
	{
		// Stack [ 주소 ] -> Heap [ _hp(4) ]
		Knight* knight = new Knight();

		// 암시적으로는 불가능
		// 명시적으로는 가능

		// Stack [ 주소 ]
		//Item* item = (Item*)knight;
		//item->_itemType = 2;
		//item->_itemDbId = 1;
		
		delete knight;
	}

	// 부모 -> 자식 변환 테스트
	{
		Item* item = new Item();

		// [  [ Item ]  ]
		// [   _damage  ]
		//Weapon* weapon = (Weapon*)item; 잘못된 메모리 할당 크래쉬 발생
		//weapon->_damage = 10;

		delete item; 
	}

	// 자식 -> 부모 변환 테스트
	{
		Weapon* weapon = new Weapon();

		Item* item = weapon;

		delete weapon;
	}

	// 명시적으로 타입 변환을 할 떄는 항상 조심해야한다.

	Item* inventory[20] = {};

	srand((unsigned int)time(nullptr));
	for (int i = 0; i < 20; i++)
	{
		int randValue = rand() % 2; // 0~1
		switch (randValue)
		{
		case 0:
			inventory[i] = new Weapon();
			break;
		case 1:
			inventory[i] = new Armor();
			break;
		}
	}

	for (int i = 0; i < 20; i++)
	{
		Item* item = inventory[i];
		if (item == nullptr)
		{
			continue;
		}

		if (item->_itemType == IT_WEAPON)
		{
			Weapon* weapon = (Weapon*)item; // 문법이 무기가 아니였을땐 잘못된 문장
			cout << "Weapon Damage : " << weapon->_damage << endl;
		}
	}

	// *********************** 매우 중요 ************************
	// 소멸자를 item이 아닌 weapon과 armor로 받아줘야 한다.
	for (int i = 0; i < 20; i++)
	{
		Item* item = inventory[i];
		if (item == nullptr)
		{
			continue;
		}

		/* if (item->_itemType == IT_WEAPON) // 함수를 가상 함수로 만들지 않으면 다 정의해야한다.
		{
			Weapon* weapon = (Weapon*)item; 
			delete weapon;
		}
		else
		{
			Armor* armor = (Armor*)item;
			delete armor;
		}
		*/

		delete item;
	}

	// [결론]
	// 포인터 vs 일반 타입 : 메모리 구조의 차이를 이해하자
	// 포인터 사이의 타입 변환을 할 떄는 매우 조심해야한다.
	// 부모 자식 관계에서 부모 클래스의 소멸자에는 까먹지 말고 virtual을 붙이자

	return 0;

}

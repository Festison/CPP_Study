#include<iostream>
using namespace std;

struct StatInfo
{
	int hp; // +0
	int attack; // +4
	int defence; // +8
};

void EnterLobby();
StatInfo CreatePlayer();
void CreateMonster(StatInfo* info);
bool StartBattle(StatInfo* player, StatInfo* monster); // 플레이어 승리 시 true, 패배 시 false


int main()
{
	EnterLobby();
	return 0;
}

void EnterLobby()
{
	cout << "로비에 입장했습니다." << endl;

	StatInfo player;
	player.hp = 0xbbbbbbbb;
	player.attack = 0xbbbbbbbb;
	player.defence = 0xbbbbbbbb;

	// [매개변수][RET][지역변수(temp(100, 10, 2) player(b,b,b))] [매개변수(&temp)][RET][지역변수(ret(100, 10, 2))] 
	player = CreatePlayer();

	StatInfo monster;
	monster.hp = 0xbbbbbbbb;
	monster.attack = 0xbbbbbbbb;
	monster.defence = 0xbbbbbbbb;
	// [매개변수][RET][지역변수(monster(40, 8, 1)] [매개변수(&monster)][RET][지역변수()] 
	CreateMonster(&monster);

	// 번외
	// 구조체끼리 복사할 경우 무슨 일이 일어날까?

	// player = monster; 
	// player.hp == monster.hp;
	// player.attack == monster.attack;
	// player.defence == monster.defence; 과정이 실행 

	bool victory = StartBattle(&player, &monster);

	if (victory)
		cout << "승리" << endl;
	else
		cout << "패배" << endl;
}

StatInfo CreatePlayer()
{
	StatInfo ret;

	cout << "플레이어 생성" << endl;

	ret.hp = 100;
	ret.attack = 10;
	ret.defence = 2;

	return ret;
}

void CreateMonster(StatInfo* info)
{
	cout << "몬스터 생성" << endl;

	info->hp = 40;
	info->attack = 8;
	info->defence = 1;

}

bool StartBattle(StatInfo* player, StatInfo* monster)
{
	while (true)
	{
		int damage = player->attack - monster->defence;
		if (damage < 0)
		{
			damage = 0;
		}

		monster->hp -= damage;
		if (monster->hp<0)
		{
			monster->hp = 0;
		}

		cout << "몬스터 HP : " << monster->hp << endl;

		if (monster->hp==0)
		{
			return true;
		}

		damage = monster->attack - player->defence;
		if (damage<0)
		{
			damage = 0;
		}

		cout << " 플레이어 HP : " << player->hp << endl;

		player->hp -= damage;
		if (player->hp<0)
		{
			player->hp = 0;
		}

		if (player->hp==0)
		{
			return false;
		}
	}
}

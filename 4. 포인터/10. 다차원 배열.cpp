#include<iostream>
using namespace std;

int main()
{
	int a[10] = { 1,2,3 };

	// [1] [1] [5] [2] [2] << 1층 
	// [4] [2] [3] [4] [1] << 0층 아파트

	int first[5] = { 4, 2, 3, 4, 1 };
	int second[5] = { 1, 1, 5, 2, 2 };

	int apartment2Floor[2][5] = { { 4, 2, 3, 4, 1 }, { 1, 1, 5, 2, 2 } };

	for (int floor = 0; floor < 2; floor++)
	{
		for (int room = 0; room < 5; room++)
		{
			int num = apartment2Floor[floor][room];
			cout << num << " ";
		}
		cout << "\n";
	}
	
	int apartment1Floor[10] = { 4, 2, 3, 4, 1, 1, 1, 5, 2, 2 };

	for (int floor = 0; floor < 2; floor++)
	{
		for (int room = 0; room < 5; room++)
		{
			int index = (floor * 5) + room;
			int num = apartment1Floor[index];
			cout << num << " ";
		}
		cout << "\n";
	}

	// 2차원 배열의 사용 2D 로그라이크 맵 
	int map[5][5] =
	{
		{ 1, 1, 1, 1, 1 },
		{ 1, 0, 0, 1, 1 },
		{ 0, 0, 0, 0, 1 },
		{ 1, 0, 0, 0, 0 },
		{ 1, 1, 1, 1, 1 },
	};

	for (int y = 0; y < 5; y++)
	{
		for (int x = 0; x < 5; x++)
		{
			int info = map[y][x];
			cout << info << " ";
		}
		cout << "\n";
	}

	return 0;

}
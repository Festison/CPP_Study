#include<iostream>
using namespace std;

// 1) Swap 함수 만들기
void Swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

// 2) 정렬 함수 만들기 (작은 숫자가 먼저 오도록 정렬)
void Sort(int numbers[], int count)
{
	for (int i = 0; i < count; i++)
	{
		// i번째 값이 제일 좋은 후보라고 가정
		int best = i;

		// 다른 후보와 비교를 통해 제일 좋은 후보를 찾는다.
		for (int j = i+1; j < count; j++)
		{
			if (numbers[j] > numbers[best])
				best = j;
		}

		// 제일 좋은 후보와 교체
		if (i != best)
			Swap(numbers[i], numbers[best]);
	}
}

// 3) 로또 번호 생성기
void ChooseLotto(int numbers[])
{
	// TODO : 랜덤으로 1~45 사이의 숫자 6개를 골라주세요! (단, 중복이 없어야 한다)
	srand((unsigned)time(0));

	int count = 0;
	while (count !=6)
	{
		int randValue = 1 + (rand() % 45);

		// 이미 찾은 값인가?
		bool found = false;
		for (int i = 0; i < count; i++)
		{
			if (numbers[i] == randValue)
			{
				found = true;
				break;
			}
		}

		// 못 찾았으면 추가
		if (found==false)
		{
			numbers[count] = randValue;
			count++;
		}
	}

	Sort(numbers, 6);
}

int main()
{
	// 1) Swap 함수 만들기
	int a = 1;
	int b = 2;
	Swap(a, b);
	// a = 2, b = 1

	// 2) 정렬 함수 만들기 (작은 숫자가 먼저 오도록 정렬)
	int numbers[6] = { 1, 42, 3, 15, 5, 6 };

	int size1 = sizeof(numbers); // 24
	int size2 = sizeof(int); // 4

	Sort(numbers, sizeof(numbers) / sizeof(int));

	// 3) 로또 번호 생성기
	ChooseLotto(numbers);

	// 로또 앱 완성
	for (int i = 0; i < 6; i++)
	{
		cout << numbers[i] << endl;
	}

	return 0;

}

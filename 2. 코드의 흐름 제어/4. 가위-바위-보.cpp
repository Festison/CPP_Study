#include<iostream>
using namespace std;

int main()
{
	srand(time(0)); //시드 설정

	// 가위 바위 보 세가지 랜덤값을 얻는다.

	int value = 1 + (rand() % 3); // 0~32767

	const int SCISSORS = 1;
	const int ROCK = 2;
	const int PAPER = 3;
	
	int wins = 0;
	int total = 0; // 비긴건 뺀다.

	while (true)
	{
		cout << "가위(1) 바위(2) 보(3) 중 하나를 골라주세요!" << endl;
		cout << "> ";


		if (total == 0)
		{
			cout << "현재 승률 : 없음" << endl;
		}
		else
		{
			int winPercentage = (wins * 100) / total; // 승률
			cout << "현재 승률 : " << winPercentage << endl;
		}

		// 컴퓨터
		int computerValue = 1 + (rand() % 3);

		// 사용자
		int input;
		cin >> input;

		if (input == SCISSORS)
		{
			switch (computerValue)
			{
			case SCISSORS:
				cout << "가위(당신) vs 가위(컴퓨터) 비겼습니다!" << endl;
				break;
			case ROCK:
				cout << "가위(당신) vs 바위(컴퓨터) 졌습니다!" << endl;
				total++;
				break;
			case PAPER:
				cout << "가위(당신) vs 보(컴퓨터) 이겼습니다!" << endl;
				total++;
				wins++;
				break;
			}
		}
		else if (input == ROCK)
		{
			switch (computerValue)
			{
			case SCISSORS:
				cout << "바위(당신) vs 가위(컴퓨터) 이겼습니다!" << endl;
				total++;
				wins++;
				break;
			case ROCK:
				cout << "바위(당신) vs 바위(컴퓨터) 비겼습니다!" << endl;
				break;
			case PAPER:
				cout << "바위(당신) vs 보(컴퓨터) 졌습니다!" << endl;
				total++;
				break;
			}
		}
		else if (input == PAPER)
		{
			switch (computerValue)
			{
			case SCISSORS:
				cout << "보(당신) vs 가위(컴퓨터) 졌습니다!" << endl;
				total++;
				break;
			case ROCK:
				cout << "보(당신) vs 바위(컴퓨터) 이겼습니다!" << endl;
				total++;
				wins++;
				break;
			case PAPER:
				cout << "보(당신) vs 보(컴퓨터) 비겼습니다!" << endl;
				break;
			}
		}
	}
	return 0;
}
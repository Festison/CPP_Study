#include<iostream>
using namespace std;

// 은닉성
// 몰라도 되는것은 숨긴다.
// 이유 : 1) 건드리면 안되는 경우 2) 다른 경로로 접근하길 원하는 경우

// public (공개적) protected(보호받는) private (개인의)
// - public : 누구한테나 공개
// - protceted : 나의 자손들한테만 허락
// - private : 나만 사용가능 << class Car 내부에서만 사용 가능

// 상속 접근 지정자: 다음 세대한테 유산을 어떻게 물려줄지?
// 부모님한테 물려받은 유산을 꼭 내 자손들에게도 똑같이 물려줘야 하는 것은 아니다.
// - public : 공개적 상속 , 부모님의 유산 설계 그대로 (public -> public, protected -> portected)
// - protceted : 보호받는 상속 , 내 자손들에게만 물려줌 (public -> protected, protected -> protected)
// - private : 개인적 상속 , 나까지만 쓰고 자손들에게도 안 물려준다. (public -> private, protected -> private)

class Car
{
public: // 접근 지정자
	void MoveHandle() { }
	void PushPedal() { }
	void OpenDoor() { }

	void TurnKey()
	{
		RunEngine();
	}

protected:
	void DisassembleCar() { } // 차를 분해한다.
	void RunEngine() { } // 엔진을 구동시킨다.
	void ConnectCircuit() { } // 전기선 연결

public:

};

class SuperCar : private Car // 상속 접근 지정자
{
public:
	void PushRemoteController()
	{
		RunEngine();
	}

};

class TestSuperCar : SuperCar
{
public:
	void Test()
	{
	
	}
};

// 캡슐화
// 연관된 데이터와 함수를 논리적으로 묶어놓은 것
class Berserker
{
public:

	int GetHp() { return _hp; }

	void SetHp(int hp)
	{
		_hp = hp;
		if (_hp <= 50)
		{
			SetBerserkerMode();
		}
	}

	// 사양 : 체력이 50이하로 떨어지면 강해진다.

private:
	void SetBerserkerMode()
	{
		cout << "매우 강해진다." << endl;
	}

private:
	int _hp = 100;
};

int main()
{
	SuperCar car;
	car.PushRemoteController();
	
	Berserker b;

	b.SetHp(20);

	TestSuperCar car;
	car.PushRemoteController();

	return 0;

}
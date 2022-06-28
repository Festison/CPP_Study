#include<iostream>

using namespace std;


//프로그래밍을 단순하게 생각하면 적절한 데이터를 저장하고 가공하는 것
//데이터 + 로직

// 그중에서도 가장 빈번히 사용되는 정수에 대해 알아본다.

//변수 선언 방법: [타입] [이름];
// [타입] [이름] = [초기값]; = 변수의 초기화


int hp = 100;

char a; // 1바이트 (-128~127)
short b; // 2바이트 (-32768~32767)
int c; // 4바이트  (-21.4억~21.4억)
__int64 d; // 8바이트 (long long)

unsigned char e; //(0~255)
unsigned short f; //(0~65536)
unsigned int g;
unsigned __int64 h;

// 콘솔/모바일게임은 늘 메모리가 부족 자료형을 잘쓰자

int main()
{


	b = 32767;
	b = b + 1;
	cout << b << endl; //-32768 출력 오버플로우 발생 


	cout << "체력이 " << hp << " 남았습니다." << endl;
	

	return 0;
}
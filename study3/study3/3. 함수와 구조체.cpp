#include <iostream>

using namespace std;

struct Time
{
    int hours;
    int mins;
};

const int minsPerHr = 60;

Time sum(Time*, Time*);
void showTime(Time);

int main() {
    //함수는 원본이 아닌 복사본을 대상으로 작업한다.
    Time day1 = { 5, 45 };
    Time day2 = { 4, 55 };

    Time total = sum(&day1, &day2);

    cout << "이틀간 소요 시간 : ";
    showTime(total);

    return 0;
}

Time sum(Time* t1, Time* t2) {
    Time total;

    //값에서 멤버로 접근할 때: .
    //주소에서 멤버로 접근할 때 : ->
    total.mins = (t1->mins + t2->mins) % minsPerHr;
    total.hours = t1->hours + t2->hours +
        (t1->mins + t2->mins) / minsPerHr;

    return total;
}

void showTime(Time t1) {
    cout << t1.hours << "시간, " << t1.mins << "분 입니다." << endl;
}
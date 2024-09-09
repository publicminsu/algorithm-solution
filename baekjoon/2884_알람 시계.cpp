#include <iostream>
using namespace std;
#define HourToMinute 60
#define HourToSecond 1440
int H, M;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> H >> M;

    int m = (H * HourToMinute + M - 45 + HourToSecond) % HourToSecond;

    cout << m / HourToMinute << " " << m % HourToMinute;

    return 0;
}
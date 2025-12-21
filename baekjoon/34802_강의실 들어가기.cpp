#include <iostream>

using namespace std;

string curTime, targetTime;

int curSec, targetSec;
int t, k;

int timeToSec(string time)
{
    int hourSec = stoi(time.substr(0, 2)) * 3600;
    int minSec = stoi(time.substr(3, 2)) * 60;
    int sec = stoi(time.substr(6, 2));

    return hourSec + minSec + sec;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> curTime >> targetTime;

    curSec = timeToSec(curTime);
    targetSec = timeToSec(targetTime);

    cin >> t >> k;

    int addSec = t * (100 - k) / 100;

    cout << (curSec + addSec <= targetSec);
    return 0;
}
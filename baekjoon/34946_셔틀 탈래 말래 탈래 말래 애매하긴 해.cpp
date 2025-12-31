#include <iostream>

using namespace std;

int A, B, C, D;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> A >> B >> C >> D;

    int shuttleTime = A + B;
    int walkTime = C;

    if (shuttleTime <= D && walkTime <= D)
    {
        cout << "~.~";
    }
    else if (shuttleTime > D && walkTime > D)
    {
        cout << "T.T";
    }
    else if (shuttleTime <= D)
    {
        cout << "Shuttle";
    }
    else
    {
        cout << "Walk";
    }
    return 0;
}
#include <iostream>
#include <cstring>
using namespace std;

int N, M;
bool isUsed[10];

bool isRoom(int num)
{
    memset(isUsed, false, sizeof(isUsed));

    while (num)
    {
        int i = num % 10;

        if (isUsed[i])
        {
            return false;
        }

        isUsed[i] = true;
        num /= 10;
    }

    return true;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    while (cin >> N >> M)
    {
        int cnt = 0;

        for (int i = N; i <= M; ++i)
        {
            cnt += isRoom(i);
        }

        cout << cnt << "\n";
    }
    return 0;
}
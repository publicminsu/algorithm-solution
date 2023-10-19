#include <iostream>
#include <cstring>
#include <unordered_set>
#include <algorithm>
using namespace std;
int scores[10001];
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int N, M, firstVal, secondVal, minPlayer, maxPlayer;
    while (true)
    {
        cin >> N >> M;
        if (!N)
            break;
        memset(scores, 0, sizeof(scores));
        firstVal = 0, secondVal = 0, maxPlayer = 0, minPlayer = 10001;
        for (int i = 0, j; i < N * M; ++i)
        {
            cin >> j;
            minPlayer = min(minPlayer, j);
            maxPlayer = max(maxPlayer, j);
            firstVal = max(++scores[j], firstVal);
        }
        for (int i = minPlayer; i <= maxPlayer; ++i)
        {
            int val = scores[i];
            if (val == firstVal)
                continue;
            secondVal = max(secondVal, val);
        }
        for (int i = minPlayer; i <= maxPlayer; ++i)
            if (secondVal == scores[i])
                cout << i << " ";
        cout << "\n";
    }
    return 0;
}
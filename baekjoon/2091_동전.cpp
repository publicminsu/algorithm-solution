#include <iostream>

using namespace std;

int X, A, B, C, D;
int maxCnt, maxA, maxB, maxC, maxD;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> X >> A >> B >> C >> D;

    for (int dCnt = 0; dCnt <= D; ++dCnt)
    {
        if (dCnt * 25 > X)
        {
            continue;
        }

        for (int cCnt = 0; cCnt <= C; ++cCnt)
        {
            if (dCnt * 25 + cCnt * 10 > X)
            {
                continue;
            }

            for (int bCnt = 0; bCnt <= B; ++bCnt)
            {
                int value = dCnt * 25 + cCnt * 10 + bCnt * 5;

                int aCnt = X - value;

                if (value > X || aCnt > A)
                {
                    continue;
                }

                int cnt = dCnt + cCnt + bCnt + aCnt;

                if (maxCnt < cnt)
                {
                    maxCnt = cnt;
                    maxA = aCnt;
                    maxB = bCnt;
                    maxC = cCnt;
                    maxD = dCnt;
                }
            }
        }
    }

    cout << maxA << " " << maxB << " " << maxC << " " << maxD;
    return 0;
}
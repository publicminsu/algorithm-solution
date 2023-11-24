#include <iostream>
#include <vector>
#include <string>
using namespace std;
char map[3][3];
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    string tc;
    int xLine, oLine, xSum, oSum, xCnt, oCnt;
    while (true)
    {
        cin >> tc;
        if (tc == "end")
        {
            break;
        }

        xLine = oLine = xSum = oSum = 0;

        for (int i = 0; i < 9; ++i) // 격자판으로 옮기기
        {
            map[i / 3][i % 3] = tc[i];
        }

        for (int i = 0; i < 3; ++i) // 가로 3칸 확인
        {
            xCnt = oCnt = 0;
            for (int j = 0; j < 3; ++j)
            {
                if (map[i][j] == 'O')
                {
                    ++oCnt;
                }
                else if (map[i][j] == 'X')
                {
                    ++xCnt;
                }
            }
            if (oCnt == 3)
            {
                ++oLine;
            }
            else if (xCnt == 3)
            {
                ++xLine;
            }
        }

        for (int i = 0; i < 3; ++i) // 세로 3칸 확인
        {
            xCnt = oCnt = 0;
            for (int j = 0; j < 3; ++j)
            {
                if (map[j][i] == 'O')
                {
                    ++oCnt;
                }
                else if (map[j][i] == 'X')
                {
                    ++xCnt;
                }
            }
            if (oCnt == 3)
            {
                ++oLine;
            }
            else if (xCnt == 3)
            {
                ++xLine;
            }
            xSum += xCnt;
            oSum += oCnt;
        }

        if (map[0][0] == map[1][1] && map[1][1] == map[2][2]) // \확인
        {
            if (map[1][1] == 'X')
            {
                ++xLine;
            }
            else if (map[1][1] == 'O')
            {
                ++oLine;
            }
        }

        if (map[0][2] == map[1][1] && map[1][1] == map[2][0]) // /확인
        {
            if (map[1][1] == 'X')
            {
                ++xLine;
            }
            else if (map[1][1] == 'O')
            {
                ++oLine;
            }
        }

        if (xLine + oLine >= 1) // 두 줄의 크기가 1 이상인 경우
        {
            if (xLine == 0) // O로만 완성한 경우
            {
                if (xSum == oSum) // O는 X보다 늦게 두기에 같아야 한다.
                {
                    cout << "valid";
                }
                else
                {
                    cout << "invalid";
                }
            }
            else if (oLine == 0) // X로만 완성한 경우
            {
                if (xSum == oSum + 1) // X가 먼저 시작했기에 1만큼 커야 한다.
                {
                    cout << "valid";
                }
                else
                {
                    cout << "invalid";
                }
            }
            else
            {
                cout << "invalid";
            }
        }
        else // 두 줄의 크기가 0인 경우
        {
            if (xSum + oSum == 9 && xSum == oSum + 1) // 9개여야 하고 X는 5개 O는 4개이다.
            {
                cout << "valid";
            }
            else
            {
                cout << "invalid";
            }
        }
        cout << "\n";
    }
    return 0;
}
#include <iostream>
#include <cstring>
using namespace std;

int N, answer, cnt, firstSize;
string first, str;
bool isVisited[11];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> first;

    firstSize = first.size();

    while (--N)
    {
        cin >> str;

        cnt = 0;
        memset(isVisited, false, sizeof(isVisited));

        int strSize = str.size();

        for (char c : first)
        {
            for (int i = 0; i < strSize; ++i)
            {
                if (isVisited[i] || str[i] != c)
                {
                    continue;
                }

                isVisited[i] = true;
                ++cnt;
                break;
            }
        }

        if (firstSize == strSize)
        {
            if (firstSize - cnt <= 1)
            {
                ++answer;
            }
        }
        else
        {
            if (firstSize - 1 == strSize)
            {
                if (firstSize - cnt == 1)
                {
                    ++answer;
                }
            }
            else if (firstSize + 1 == strSize)
            {
                if (firstSize == cnt)
                {
                    ++answer;
                }
            }
        }
    }

    cout << answer;

    return 0;
}
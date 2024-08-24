#include <iostream>
#include <vector>
using namespace std;
#define HEIGHT_LIMIT 257
int N, M, B, answerTime = 987654321, answerHeight;
vector<vector<int>> map;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> N >> M >> B;

    map = vector<vector<int>>(N, vector<int>(M));

    for (vector<int> &line : map)
    {
        for (int &i : line)
        {
            cin >> i;
        }
    }

    for (int i = 0; i < HEIGHT_LIMIT; ++i)
    {
        int time = 0, b = B;

        for (int j = 0; j < N; ++j)
        {
            for (int k = 0; k < M; ++k)
            {
                int heightDiff = map[j][k] - i;

                if (heightDiff > 0)
                {
                    time += heightDiff * 2;
                    b += heightDiff;
                }
                else
                {
                    time -= heightDiff;
                    b += heightDiff;
                }
            }
        }

        if (b >= 0)
        {
            if (time <= answerTime)
            {
                answerTime = time;
                answerHeight = i;
            }
        }
    }

    cout << answerTime << " " << answerHeight;
    return 0;
}
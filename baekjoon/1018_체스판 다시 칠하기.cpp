#include <iostream>
using namespace std;
int N, M, answer = 64;
char map[51][51];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> M;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            cin >> map[i][j];
        }
    }

    for (int i = 0; i < N - 7; ++i)
    {
        for (int j = 0; j < M - 7; ++j)
        {
            for (int k = 0; k < 2; ++k)
            {
                int cnt = 0;
                for (int l = 0; l < 8; ++l)
                {
                    int y = i + l;

                    for (int n = 0; n < 8; ++n)
                    {
                        int x = j + n;

                        char &c = map[y][x];

                        char bw = (l + n + k) % 2 == 1 ? 'W' : 'B';

                        if (c == bw)
                        {
                            ++cnt;
                        }
                    }
                }
                answer = min(cnt, answer);
            }
        }
    }
    cout << answer;
    return 0;
}
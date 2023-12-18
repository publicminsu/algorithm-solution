#include <iostream>
#include <vector>
using namespace std;
#define HEIGHT_GAP 3
#define WIDTH_GAP 8
int N, M;
vector<vector<char>> test;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> M;

    N *= HEIGHT_GAP;
    M *= WIDTH_GAP;

    test = vector<vector<char>>(N, vector<char>(M));

    for (int height = 0; height < N; ++height)
    {
        for (int width = 0; width < M; ++width)
        {
            cin >> test[height][width];
        }
    }

    for (int height = 0; height < N; height += HEIGHT_GAP)
    {
        for (int width = 0; width < M; width += WIDTH_GAP)
        {
            // char을 int로
            int a = static_cast<int>(test[height + 1][width + 1] - '0');
            int b = static_cast<int>(test[height + 1][width + 3] - '0');
            int c = static_cast<int>(test[height + 1][width + 5] - '0');
            if (test[height + 1][width + 6] != '.') // 2자리 수라면
            {
                c *= 10;
                c += static_cast<int>(test[height + 1][width + 6] - '0');
            }

            if (a + b == c) // 수식이 옳다면
            {
                int len = (c >= 10 ? 7 : 6); // 2자리인지 확인하고 *의 길이를 조절
                test[height + 1][width] = '*';
                test[height + 1][width + len] = '*';
                for (int i = 1; i < len; ++i)
                {
                    test[height][width + i] = '*';
                    test[height + 2][width + i] = '*';
                }
            }
            else
            {
                for (int i = 0; i < 3; ++i)
                {
                    test[height + i][width + 3 - i] = '/';
                }
            }
        }
    }

    for (int height = 0; height < N; ++height)
    {
        for (int width = 0; width < M; ++width)
        {
            cout << test[height][width];
        }
        cout << "\n";
    }
    return 0;
}
#include <iostream>
using namespace std;

struct starPos
{
    int y, x;
};

int N, M, L, K, answer;
starPos stars[100];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> N >> M >> L >> K;

    for (int i = 0; i < K; ++i)
    {
        cin >> stars[i].x >> stars[i].y;
    }

    for (int i = 0; i < K; ++i)
    {
        const int &x = stars[i].x;

        for (int j = 0; j < K; ++j)
        {
            const int &y = stars[j].y;

            int cnt = 0;

            for (int k = 0; k < K; ++k)
            {
                const starPos &targetStar = stars[k];
                if (x <= targetStar.x && x + L >= targetStar.x && y <= targetStar.y && y + L >= targetStar.y)
                {
                    ++cnt;
                }
            }

            answer = max(cnt, answer);
        }
    }

    cout << K - answer;
    return 0;
}
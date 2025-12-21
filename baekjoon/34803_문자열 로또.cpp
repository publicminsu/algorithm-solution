#include <iostream>

using namespace std;

int L, N, K;
string lottos[20];

void input()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> L >> N;
    for (int i = 0; i < N; ++i)
    {
        cin >> lottos[i];
    }
    cin >> K;
}

void solve()
{
    int maxScore = 0;

    for (int i = 0; i < N; ++i)
    {
        const string &lotto = lottos[i];
        for (int j = 0; j <= L - K; ++j)
        {
            string str = lotto.substr(j, K);
            int score = 0;

            for (int k = 0; k < N; ++k)
            {
                const string &otherLotto = lottos[k];

                for (int l = 0; l <= L - K; ++l)
                {
                    string otherStr = otherLotto.substr(l, K);

                    if (str == otherStr)
                    {
                        ++score;
                    }
                }
            }

            maxScore = max(maxScore, score);
        }
    }

    cout << maxScore;
}

int main()
{
    input();
    solve();
    return 0;
}
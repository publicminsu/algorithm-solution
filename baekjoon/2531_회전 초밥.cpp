#include <iostream>
#include <vector>
using namespace std;
int N, d, k, c, answer;
vector<int> count, sushi;
void input()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> d >> k >> c;

    sushi.reserve(N + k);
    count = vector<int>(d + 1);

    for (int i = 0, j; i < N; ++i)
    {
        cin >> j;
        sushi.push_back(j);
    }

    for (int i = 0; i < k; ++i)
    {
        sushi.push_back(sushi[i]);
    }
}

void updateAnswer(int num)
{
    answer = max(answer, num + (count[c] ? 0 : 1));
}

void solve()
{
    int num = 0;
    for (int i = 0; i < k; ++i)
    {
        if (count[sushi[i]]++ == 0)
        {
            ++num;
        }
    }

    updateAnswer(num);

    for (int i = k; i < k + N; ++i)
    {
        if (--count[sushi[i - k]] == 0)
        {
            --num;
        }

        if (count[sushi[i]]++ == 0)
        {
            ++num;
        }

        updateAnswer(num);
    }
}

int main()
{
    input();
    solve();

    cout << answer;
    return 0;
}
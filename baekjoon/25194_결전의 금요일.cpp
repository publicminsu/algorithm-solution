#include <iostream>
using namespace std;
int N, A;
int cnt[7];

bool recur(int value, int index)
{
    if (value == 4)
    {
        return true;
    }

    for (int i = index; i < 7; ++i)
    {
        if (cnt[i])
        {
            --cnt[i];

            if (recur((value + i) % 7, i))
            {
                return true;
            }

            ++cnt[i];
        }
    }

    return false;
}

bool check()
{
    if (cnt[4])
    {
        return true;
    }

    return recur(0, 0);
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> N;

    for (int i = 0; i < N; ++i)
    {
        cin >> A;
        ++cnt[A % 7];
    }

    cout << (check() ? "YES" : "NO");

    return 0;
}
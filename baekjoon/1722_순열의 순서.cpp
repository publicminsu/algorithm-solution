#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
int N, cmd;
ll k;
vector<bool> isVisited;
vector<ll> factorial;
void cmd1()
{
    cin >> k;

    for (int i = N - 1; i >= 0; --i)
    {
        for (int j = 1; j <= N; ++j)
        {
            if (isVisited[j])
            {
                continue;
            }

            if (factorial[i] < k) // 만약 i!를 초과할 정도로 순서가 남아있다면
            {
                k -= factorial[i];
            }
            else
            {
                isVisited[j] = true;
                cout << j << " ";
                break;
            }
        }
    }
}
void cmd2()
{
    for (int i = N - 1, num; i >= 0; --i)
    {
        cin >> num;
        for (int j = 1; j < num; ++j)
        {
            if (isVisited[j])
            {
                continue;
            }

            k += factorial[i];
        }
        isVisited[num] = true;
    }
    cout << k + 1;
}
void input()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> cmd;

    isVisited = vector<bool>(N + 1);
    factorial = vector<ll>(N);
}
void solve()
{
    factorial[0] = factorial[1] = 1;
    for (int i = 2; i < N; ++i)
    {
        factorial[i] = factorial[i - 1] * i;
    }

    if (cmd == 1)
    {
        cmd1();
    }
    else
    {
        cmd2();
    }
}
int main()
{
    input();
    solve();
    return 0;
}
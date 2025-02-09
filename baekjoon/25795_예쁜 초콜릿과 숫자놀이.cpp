#include <iostream>
using namespace std;
#define MOD 100000
using ll = long long;

int N, a, b, c;
ll answer;
bool isVisited[16][16][MOD];

void input()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> a >> b >> c;
}

void comb(int white, int dark, ll value)
{
    bool &check = isVisited[white][dark][value];

    if (check)
    {
        return;
    }

    check = true;

    if (dark == N)
    {
        answer = max(answer, value);

        return;
    }

    if (white < N)
    {
        comb(white + 1, dark, (value + b) % MOD);
    }
    if (white > dark)
    {
        comb(white, dark + 1, (value * c) % MOD);
    }
}

int main()
{
    input();
    comb(0, 0, a);
    cout << answer;
    return 0;
}
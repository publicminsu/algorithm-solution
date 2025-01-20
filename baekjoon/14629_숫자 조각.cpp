#include <iostream>
using namespace std;
using ll = long long;
ll N, answer;
bool isVisited[10];

void comb(ll num)
{
    if (abs(num - N) < abs(answer - N))
    {
        answer = num;
    }
    else if (abs(num - N) == abs(answer - N))
    {
        answer = min(answer, num);
    }

    for (int i = 0; i < 10; ++i)
    {
        if (isVisited[i])
        {
            continue;
        }
        isVisited[i] = true;

        comb(num * 10 + i);

        isVisited[i] = false;
    }
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N;
    comb(0);
    cout << answer;
    return 0;
}
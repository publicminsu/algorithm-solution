#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N;
vector<int> pNums, nNums;

void input()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> N;

    pNums.reserve(N);
    nNums.reserve(N);

    for (int i = 0, num; i < N; ++i)
    {
        cin >> num;

        if (num > 0)
        {
            pNums.push_back(num);
        }
        else
        {
            nNums.push_back(num);
        }
    }
}

void solve()
{
    int answer = 0;

    sort(pNums.begin(), pNums.end(), greater<int>());
    sort(nNums.begin(), nNums.end());

    int pSize = pNums.size();
    int nSize = nNums.size();

    for (int i = 0; i < pSize; ++i)
    {
        if (pNums[i] == 1 || i + 1 == pSize || pNums[i + 1] == 1)
        {
            answer += pNums[i];
        }
        else
        {
            answer += pNums[i] * pNums[i + 1];
            ++i;
        }
    }

    for (int i = 0; i < nSize; ++i)
    {
        if (i + 1 == nSize)
        {
            answer += nNums[i];
        }
        else
        {
            answer += nNums[i] * nNums[i + 1];
            ++i;
        }
    }

    cout << answer;
}

int main()
{
    input();
    solve();
    return 0;
}
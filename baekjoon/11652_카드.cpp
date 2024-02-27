#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
ll curNum, maxNum;
int N, curCnt, maxCnt;
vector<ll> cards;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> N;
    cards = vector<ll>(N);
    for (ll &card : cards)
    {
        cin >> card;
    }

    sort(cards.begin(), cards.end());

    for (const ll &card : cards)
    {
        if (curNum != card) // 새로운 값이면
        {
            if (curCnt > maxCnt) // 기록된 값보다 크다면
            {
                maxNum = curNum;
                maxCnt = curCnt;
            }
            curNum = card;
            curCnt = 1;
        }
        else
        {
            ++curCnt;
        }
    }
    if (curCnt > maxCnt) // 기록된 값보다 크다면
    {
        maxNum = curNum;
        maxCnt = curCnt;
    }
    cout << maxNum;
    return 0;
}
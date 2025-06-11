#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using pii = pair<int, int>;

int prices[100000];
pii piis[100000];
int N, lastIndex, profit;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> N;

    for (int i = 0; i < N; ++i)
    {
        cin >> prices[i];
        piis[i] = {prices[i], i};
    }

    sort(piis, piis + N, greater<>());

    for (int i = 0; i < N; ++i)
    {
        int idx = piis[i].second;
        int price = piis[i].first;

        for (int j = lastIndex; j < idx; ++j)
        {
            profit += price - prices[j];
        }

        lastIndex = max(lastIndex, idx + 1);
    }

    cout << profit;
    return 0;
}
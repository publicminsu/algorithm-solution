#include <iostream>

using namespace std;

int prices[100000];
int N, maxPrice, profit;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> N;

    for (int i = 0; i < N; ++i)
    {
        cin >> prices[i];
    }

    for (int i = N - 1; i >= 0; --i)
    {
        if (maxPrice < prices[i])
        {
            maxPrice = prices[i];
        }

        profit += maxPrice - prices[i];
    }

    cout << profit;
    return 0;
}
#include <iostream>
using namespace std;
int N, winner, maxValue;
int cards[5];
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N;

    for (int i = 1; i <= N; ++i)
    {
        for (int &card : cards)
        {
            cin >> card;
        }

        for (int j = 0; j < 3; ++j)
        {
            for (int k = j + 1; k < 4; ++k)
            {
                for (int l = k + 1; l < 5; ++l)
                {
                    int value = (cards[j] + cards[k] + cards[l]) % 10;

                    if (value >= maxValue)
                    {
                        maxValue = value;
                        winner = i;
                    }
                }
            }
        }
    }

    cout << winner;
    return 0;
}
#include <iostream>
using namespace std;

int sum;

void calcScore(int size)
{
    int minScore = 100;
    for (int i = 0; i < size; ++i)
    {
        int score;
        cin >> score;
        minScore = min(minScore, score);
        sum += score;
    }

    sum -= minScore;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    calcScore(4);
    calcScore(2);
    cout << sum;
}
#include <iostream>
using namespace std;

#define INF 601

int N, A, B, C;
int sum = INF;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N;
    while (N--)
    {
        cin >> A >> B >> C;

        int temp = A + B + C;

        if (temp >= 512)
        {
            sum = min(temp, sum);
        }
    }

    if (sum == INF)
    {
        sum = -1;
    }

    cout << sum;
    return 0;
}
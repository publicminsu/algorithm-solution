#include <iostream>
int N, answer;
using namespace std;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> N;

    for (int i = N - 1; i > 0; --i)
    {
        int sum = i;
        int j = i;

        while (j)
        {
            sum += j % 10;
            j /= 10;
        }

        if (sum == N)
        {
            answer = i;
        }
    }

    cout << answer;
    return 0;
}
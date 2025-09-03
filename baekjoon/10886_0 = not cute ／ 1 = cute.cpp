#include <iostream>
using namespace std;

int N, sum;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N;

    for (int i = 0, j; i < N; ++i)
    {
        cin >> j;
        sum += j;
    }

    cout << ((sum * 2 > N) ? "Junhee is cute!" : "Junhee is not cute!");
    return 0;
}
#include <iostream>
#include <algorithm>
using namespace std;

int N;
int S[100000];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        cin >> S[i];
    }

    sort(S, S + N);

    int minPrice = S[0], cnt = 1;

    for (int i = 1; i < N; ++i)
    {
        if (minPrice * 2 <= S[i])
        {
            ++cnt;
            minPrice = S[i];
        }
    }

    cout << cnt;
    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> P;
int N, M, price, sum;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> N >> M;

    P = vector<int>(M);
    for (int &i : P)
    {
        cin >> i;
    }

    sort(P.begin(), P.end());

    for (int i = 0; i < M; ++i)
    {
        int nextSum = P[i] * min(N, M - i);
        if (sum < nextSum)
        {
            price = P[i];
            sum = nextSum;
        }
    }

    cout << price << " " << sum;
    return 0;
}
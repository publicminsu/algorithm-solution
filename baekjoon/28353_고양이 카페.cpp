#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, K, s, e, answer;
vector<int> w;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> N >> K;

    w = vector<int>(N);
    for (int &i : w)
    {
        cin >> i;
    }

    sort(w.begin(), w.end());

    e = N - 1;
    while (s < e)
    {
        if (w[s] + w[e] <= K)
        {
            ++answer;
            ++s;
            --e;
        }
        else
        {
            --e;
        }
    }
    cout << answer;
    return 0;
}
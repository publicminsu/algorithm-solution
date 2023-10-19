#include <iostream>
#include <vector>
using namespace std;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int N, sum = 0;
    cin >> N;
    vector<int> level;
    for (int i = 0, j; i < N; ++i)
    {
        cin >> j;
        level.push_back(j);
    }
    for (int i = N - 1; i > 0; --i)
    {
        if (level[i] > level[i - 1])
            continue;
        sum += level[i - 1] - level[i] + 1;
        level[i - 1] = level[i] - 1;
    }
    cout << sum;
    return 0;
}
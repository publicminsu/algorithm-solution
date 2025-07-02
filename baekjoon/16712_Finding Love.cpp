#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N, M;
vector<int> a;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> N >> M;

    a.reserve(N);

    for (int i = 0, j; i < N; ++i)
    {
        cin >> j;
        a.push_back(j);
    }

    for (int i = 0, j; i < N - M + 1; ++i)
    {
        sort(a.begin(), a.begin() + M);
        cin >> j;
        a.erase(a.begin() + j - 1);
    }

    sort(a.begin(), a.end());

    for (const int &i : a)
    {
        cout << i << " ";
    }
}
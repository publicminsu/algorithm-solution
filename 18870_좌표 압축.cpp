#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int N;
    cin >> N;
    vector<int> X(N);
    vector<pii> order(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> X[i];
        order[i].first = X[i];
        order[i].second = i;
    }
    sort(order.begin(), order.end());
    for (int i = 0, prev = order[0].first, j = 0; i < order.size(); ++i)
    {
        if (prev == order[i].first)
            X[order[i].second] = j;
        else
        {
            ++j;
            X[order[i].second] = j;
            prev = order[i].first;
        }
    }
    for (int i = 0; i < N; ++i)
        cout << X[i] << " ";
    return 0;
}
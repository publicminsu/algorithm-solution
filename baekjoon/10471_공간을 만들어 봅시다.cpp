#include <iostream>
#include <vector>
using namespace std;

int W, P;
vector<int> v;
bool isVisited[101];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> W >> P;

    v.reserve(P + 2);
    v.push_back(0);
    for (int i = 0, j; i < P; ++i)
    {
        cin >> j;
        v.push_back(j);
    }
    v.push_back(W);

    for (int i = 0; i < v.size(); ++i)
    {
        for (int j = i + 1; j < v.size(); ++j)
        {
            isVisited[v[j] - v[i]] = true;
        }
    }

    for (int i = 1; i <= W; ++i)
    {
        if (isVisited[i])
        {
            cout << i << " ";
        }
    }
    return 0;
}
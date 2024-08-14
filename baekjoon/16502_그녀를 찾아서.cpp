#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
using pii = pair<int, int>;
using piif = pair<pii, float>;
int N, M;
vector<piif> graph;
float amount[4] = {25, 25, 25, 25};
float nextAmount[4];
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cout << fixed;
    cout.precision(2);

    cin >> N >> M;

    graph = vector<piif>(M);

    for (piif &node : graph)
    {
        char s, e;
        cin >> s >> e >> node.second;
        node.first.first = s - 'A';
        node.first.second = e - 'A';
    }

    while (N--)
    {
        memset(nextAmount, 0, sizeof(nextAmount));

        for (const piif &node : graph)
        {
            nextAmount[node.first.second] += amount[node.first.first] * node.second;
        }

        swap(amount, nextAmount);
    }

    for (float i : amount)
    {
        cout << i << "\n";
    }
    return 0;
}
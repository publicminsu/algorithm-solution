#include <iostream>
#include <vector>
using namespace std;
vector<vector<bool>> graph;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int N;
    cin >> N;
    graph = vector<vector<bool>>(N, vector<bool>(N));
    for (int i = 0; i < N; ++i)
        for (int j = 0, k; j < N; ++j)
            cin >> k, graph[i][j] = k;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            for (int k = 0; k < N; ++k)
                if (graph[j][i] && graph[i][k])
                    graph[j][k] = true;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0, k; j < N; ++j)
            cout << graph[i][j] << " ";
        cout << "\n";
    }
    return 0;
}
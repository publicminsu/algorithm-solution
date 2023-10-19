#include <iostream>
#include <vector>
using namespace std;
vector<int> v;
int N, M;
void dfs(int depth)
{
    if (depth == M)
    {
        for (int i : v)
        {
            cout << i << " ";
        }
        cout << "\n";
        return;
    }
    for (int i = 1; i <= N; ++i)
    {
        v[depth] = i;
        dfs(depth + 1);
    }
    return;
}
int main()
{
    cin >> N >> M;
    v = vector<int>(M);
    dfs(0);
    return 0;
}
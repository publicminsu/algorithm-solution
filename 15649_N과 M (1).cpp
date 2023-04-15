#include <iostream>
#include <vector>
using namespace std;
int N, M;
vector<int> seq;
vector<bool> visted;
void dfs()
{
    if (M == seq.size())
    {
        for (int i : seq)
        {
            cout << i << " ";
        }
        cout << "\n";
        return;
    }
    for (int i = 1; i <= N; ++i)
    {
        if (visted[i])
            continue;
        visted[i] = true;
        seq.push_back(i);
        dfs();
        seq.pop_back();
        visted[i] = false;
    }
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> M;
    visted = vector<bool>(N + 1);
    dfs();
    return 0;
}
#include <iostream>
#include <vector>
using namespace std;
vector<int> map; // 기존 y값
int N, ret = 0;
bool isOverlap(int i, int depth)
{
    for (int j = 0; j < depth; ++j) // 기존 x값
    {
        if (map[j] == i)
            return true;
        if ((j - map[j] == depth - i) || (j + map[j] == depth + i))
            return true;
    }
    return false;
}
void dfs(int depth) // 현재 x값
{
    if (depth == N)
    {
        ++ret;
        return;
    }
    for (int i = 0; i < N; ++i) // 새로운 y값
    {
        if (isOverlap(i, depth))
            continue;
        map[depth] = i;
        dfs(depth + 1);
        map[depth] = -1;
    }
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N;
    map = vector<int>(N);
    dfs(0);
    cout << ret;
}
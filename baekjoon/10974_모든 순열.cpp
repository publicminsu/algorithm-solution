#include <iostream>
#include <vector>
using namespace std;
bool isUsed[9];
int N, arr[8];
void dfs(int depth)
{
    if (depth == N) // 모두 탐색한 경우
    {
        for (int i = 0; i < N; ++i)
        {
            cout << arr[i] << " ";
        }
        cout << "\n";
        return;
    }
    for (int i = 1; i <= N; ++i)
    {
        if (isUsed[i]) // 이미 사용한 수
        {
            continue;
        }
        arr[depth] = i;
        isUsed[i] = true;
        dfs(depth + 1);
        isUsed[i] = false;
    }
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N;
    dfs(0);
    return 0;
}
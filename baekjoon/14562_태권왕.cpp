#include <iostream>
using namespace std;
int C, S, T;
int dfs(int point, int penalty)
{
    if (point > T + penalty)
    {
        return 100;
    }
    else if (point == T + penalty)
    {
        return 0;
    }

    int A = dfs(point * 2, penalty + 3);
    int B = dfs(point + 1, penalty);

    return min(A, B) + 1;
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> C;
    while (C--)
    {
        cin >> S >> T;

        cout << dfs(S, 0) << "\n";
    }
    return 0;
}
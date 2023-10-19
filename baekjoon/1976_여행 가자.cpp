#include <iostream>
using namespace std;
int parents[201];
int find(int num)
{
    if (parents[num] == num)
        return num;
    return parents[num] = find(parents[num]);
}
void merge(int num1, int num2)
{
    int x = find(num1);
    int y = find(num2);
    if (x > y)
    {
        parents[x] = y;
    }
    else
    {
        parents[y] = x;
    }
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int N, M, k;
    cin >> N >> M;
    for (int i = 1; i <= N; ++i)
        parents[i] = i;
    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= N; ++j)
        {
            cin >> k;
            if (k)
                merge(i, j);
        }
    }
    cin >> k;
    int group = parents[k];
    for (int i = 2; i <= M; ++i)
    {
        cin >> k;
        if (parents[k] != group)
        {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
}
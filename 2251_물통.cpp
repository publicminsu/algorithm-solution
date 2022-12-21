#include <iostream>
#include <set>
#include <queue>
#include <vector>
using namespace std;
bool isVisted[201][201];
int dx[] = {0, 0, 1, 1, 2, 2};
int dy[] = {1, 2, 0, 2, 0, 1};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int bucket[3];
    queue<pair<int, int>> bfs;
    set<int> ans;
    for (int i = 0; i < 3; ++i)
    {
        int _b;
        cin >> _b;
        bucket[i] = _b;
    }
    bfs.push({0, 0});
    isVisted[0][0] = true;
    ans.insert(bucket[2]);
    while (!bfs.empty())
    {
        int n1 = bfs.front().first;
        int n2 = bfs.front().second;
        int n3 = bucket[2] - n1 - n2;
        bfs.pop();
        for (int i = 0; i < 6; ++i)
        {
            int arr[] = {n1, n2, n3};
            arr[dx[i]] += arr[dy[i]];
            arr[dy[i]] = 0;
            if (arr[dx[i]] > bucket[dx[i]])
            {
                arr[dy[i]] = arr[dx[i]] - bucket[dx[i]];
                arr[dx[i]] = bucket[dx[i]];
            }
            if (!isVisted[arr[0]][arr[1]])
            {
                isVisted[arr[0]][arr[1]] = true;
                bfs.push({arr[0], arr[1]});
                if (!arr[0])
                {
                    ans.insert(arr[2]);
                }
            }
        }
    }
    for (int a : ans)
    {
        cout << a << " ";
    }
    return 0;
}
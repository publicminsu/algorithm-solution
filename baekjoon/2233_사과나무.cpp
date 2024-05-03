#include <iostream>
#include <vector>
#include <stack>
using namespace std;
using pii = pair<int, int>;
pii maxVal;
string binary;
int N, X, Y, ret;
vector<int> inIdx, outIdx;
vector<vector<int>> graph;
void input()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N;
    inIdx = outIdx = vector<int>(N + 1);
    graph = vector<vector<int>>(N + 1, vector<int>());

    cin >> binary >> X >> Y;
}
void init()
{
    stack<int> s;
    for (int i = 1, idx = 1; i <= N * 2; ++i)
    {
        char c = binary[i - 1];

        if (c == '0')
        {
            if (!s.empty())
            {
                int parent = s.top();
                graph[parent].push_back(idx);
            }

            s.push(idx);

            if (X == i)
            {
                X = idx;
            }
            if (Y == i)
            {
                Y = idx;
            }

            inIdx[idx++] = i;
        }
        else
        {
            int cur = s.top();
            s.pop();

            if (X == i)
            {
                X = cur;
            }
            if (Y == i)
            {
                Y = cur;
            }

            outIdx[cur] = i;
        }
    }
}
pii dfs(int cur)
{
    pii sum = {0, 0};

    for (int next : graph[cur])
    {
        pii value = dfs(next);

        sum.first += value.first;
        sum.second += value.second;
    }

    // 썩은 사과인 경우
    if (cur == X || cur == Y)
    {
        ++sum.second;
    }
    else
    {
        ++sum.first;
    }

    // 썩은 사과 많이, 멀쩡한 사과 적게
    if (sum.second > maxVal.second)
    {
        maxVal = sum;
        ret = cur;
    }
    else if (sum.second == maxVal.second)
    {
        if (sum.first < maxVal.first)
        {
            maxVal = sum;
            ret = cur;
        }
    }

    return sum;
}
int main()
{
    input();
    init();
    dfs(1);
    cout << inIdx[ret] << " " << outIdx[ret];
    return 0;
}
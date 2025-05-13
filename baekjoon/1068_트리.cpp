#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> tree;
int N, root, deleteNode;

void input()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> N;

    tree = vector<vector<int>>(N, vector<int>());

    for (int i = 0, parent; i < N; ++i)
    {
        cin >> parent;

        if (parent == -1)
        {
            root = i;
        }
        else
        {
            tree[parent].push_back(i);
        }
    }

    cin >> deleteNode;
}

int dfs(int curNode)
{
    if (curNode == deleteNode)
    {
        return 0;
    }

    if (tree[curNode].size() == 0)
    {
        return 1;
    }

    if (tree[curNode].size() == 1)
    {
        if (tree[curNode][0] == deleteNode)
        {
            return 1;
        }
    }

    int sum = 0;

    for (int nextNode : tree[curNode])
    {
        sum += dfs(nextNode);
    }

    return sum;
}

int main()
{
    input();
    cout << dfs(root);
    return 0;
}

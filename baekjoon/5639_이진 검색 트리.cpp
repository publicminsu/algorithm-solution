#include <iostream>
#include <vector>
using namespace std;
vector<int> tree;
void input()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int node;
    while (cin >> node)
    {
        tree.push_back(node);
    }
}
void recur(int start, int end)
{
    if (start >= end) // 범위를 벗어나는 경우
    {
        return;
    }

    int choice = start + 1, num = tree[start];
    for (; choice < end; ++choice)
    {
        if (tree[choice] > num) // 현재 값보다 큰 경우
        {
            num = tree[choice];
            break;
        }
    }

    recur(start + 1, choice); // 좌측
    recur(choice, end);       // 우측
    cout << tree[start] << "\n";
}
int main()
{
    input();
    recur(0, tree.size());
    return 0;
}
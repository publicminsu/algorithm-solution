#include <iostream>
#include <queue>
using namespace std;

int N, M;
priority_queue<int> boxes;

void input()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> N >> M;

    while (N--)
    {
        int c;
        cin >> c;
        boxes.push(c);
    }
}

bool solve()
{
    for (int i = 0; i < M; ++i)
    {
        int w;
        cin >> w;

        if (boxes.empty())
        {
            return false;
        }

        int remain = boxes.top() - w;
        boxes.pop();

        if (remain > 0)
        {
            boxes.push(remain);
        }
        else if (remain < 0)
        {
            return false;
        }
    }

    return true;
}

int main()
{
    input();
    cout << solve();
    return 0;
}
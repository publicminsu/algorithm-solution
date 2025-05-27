#include <iostream>
#include <deque>
using namespace std;
using pii = pair<int, int>;
deque<pii> dq;
int N;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N;

    for (int i = 1; i <= N; ++i)
    {
        int num;
        cin >> num;
        dq.push_back({i, num});
    }

    while (!dq.empty())
    {
        pii curNode = dq.front();
        dq.pop_front();
        cout << curNode.first << " ";

        int num = curNode.second;

        while (num > 1)
        {
            dq.push_back(dq.front());
            dq.pop_front();
            --num;
        }

        while (num < 0)
        {
            dq.push_front(dq.back());
            dq.pop_back();
            ++num;
        }
    }
    return 0;
}
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int N, num;
    string cmd;
    queue<int> q;
    cin >> N;
    while (N--)
    {
        cin >> cmd;
        if (cmd == "push")
        {
            cin >> num;
            q.push(num);
        }
        else if (cmd == "pop")
        {
            if (q.empty())
            {
                cout << -1;
            }
            else
            {
                cout << q.front();
                q.pop();
            }
        }
        else if (cmd == "size")
        {
            cout << q.size();
        }
        else if (cmd == "empty")
        {
            cout << q.empty();
        }
        else if (cmd == "front")
        {
            if (q.empty())
            {
                cout << -1;
            }
            else
            {
                cout << q.front();
            }
        }
        else if (cmd == "back")
        {
            if (q.empty())
            {
                cout << -1;
            }
            else
            {
                cout << q.back();
            }
        }

        if (cmd != "push")
        {
            cout << "\n";
        }
    }
    return 0;
}
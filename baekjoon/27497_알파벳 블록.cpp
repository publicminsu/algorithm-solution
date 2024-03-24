#include <iostream>
#include <vector>
#include <deque>
using namespace std;
using pic = pair<int, char>;
vector<pic> stack;
deque<char> str;
int N, cmd;
char c;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> N;
    stack.reserve(N);

    while (N--)
    {
        cin >> cmd;
        if (cmd == 3)
        {
            if (stack.empty())
            {
                continue;
            }

            stack.pop_back();
        }
        else
        {
            cin >> c;
            stack.push_back({cmd, c});
        }
    }

    for (const pic &cur : stack)
    {
        if (cur.first == 1)
        {
            str.push_back(cur.second);
        }
        else
        {
            str.push_front(cur.second);
        }
    }

    if (str.empty())
    {
        cout << 0;
    }
    else
    {
        for (const char &c : str)
        {
            cout << c;
        }
    }
    return 0;
}
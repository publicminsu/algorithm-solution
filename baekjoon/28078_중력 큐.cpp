#include <iostream>
#include <deque>
using namespace std;

int Q, dir, wCount;
string cmd;
char arg;
deque<char> dq;

void push()
{
    cin >> arg;
    dq.push_back(arg);

    if (arg == 'w')
    {
        ++wCount;
    }
}

void pop()
{
    if (dq.empty())
    {
        return;
    }

    if (dq.front() == 'w')
    {
        --wCount;
    }

    dq.pop_front();
}

void rotate()
{
    cin >> arg;

    if (arg == 'l')
    {
        dir = (dir - 1 + 4) % 4;
    }
    else
    {
        dir = (dir + 1) % 4;
    }
}

void count()
{
    cin >> arg;

    if (arg == 'b')
    {
        cout << (dq.size() - wCount);
    }
    else
    {
        cout << wCount;
    }

    cout << "\n";
}

void fall()
{
    if (dir % 2 == 0)
    {
        return;
    }

    if (dir == 1) // 앞
    {
        while (!dq.empty() && dq.front() == 'b')
        {
            dq.pop_front();
        }
    }
    else
    {
        while (!dq.empty() && dq.back() == 'b')
        {
            dq.pop_back();
        }
    }
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> Q;

    while (Q--)
    {
        cin >> cmd;

        if (cmd == "push")
        {
            push();
        }
        else if (cmd == "pop")
        {
            pop();
        }
        else if (cmd == "rotate")
        {
            rotate();
        }
        else if (cmd == "count")
        {
            count();
        }

        fall();
    }
    return 0;
}
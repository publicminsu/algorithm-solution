#include <iostream>
using namespace std;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int robot, box, goal;
    for (int i = 0; i < 10; ++i)
    {
        char c;
        cin >> c;
        if (c == '@')
        {
            robot = i;
        }
        else if (c == '#')
        {
            box = i;
        }
        else if (c == '!')
        {
            goal = i;
        }
    }
    if ((robot < box && box < goal) || (robot > box && box > goal))
    {
        cout << abs(robot - goal) - 1;
    }
    else
    {
        cout << -1;
    }
    return 0;
}
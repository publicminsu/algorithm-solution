#include <iostream>
#include <deque>
using namespace std;
int tc;
string str;
deque<char> front, back;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> tc;
    while (tc--)
    {
        cin >> str;
        for (char c : str)
        {
            if (c == '-')
            {
                if (!front.empty())
                {
                    front.pop_back();
                }
            }
            else if (c == '<')
            {
                if (!front.empty())
                {
                    back.push_front(front.back());
                    front.pop_back();
                }
            }
            else if (c == '>')
            {
                if (!back.empty())
                {
                    front.push_back(back.front());
                    back.pop_front();
                }
            }
            else
            {
                front.push_back(c);
            }
        }

        while (!front.empty())
        {
            cout << front.front();
            front.pop_front();
        }
        while (!back.empty())
        {
            cout << back.front();
            back.pop_front();
        }
        cout << "\n";
    }
    return 0;
}
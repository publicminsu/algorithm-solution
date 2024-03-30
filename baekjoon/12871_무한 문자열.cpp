#include <iostream>
using namespace std;
string s, t;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> s >> t;

    string copyS = s;
    string copyT = t;

    while (s.size() != t.size()) // 같은 크기가 될 때까지 더한다.
    {
        if (s.size() < t.size())
        {
            s += copyS;
        }
        else if (s.size() > t.size())
        {
            t += copyT;
        }
    }

    cout << (s == t);
    return 0;
}
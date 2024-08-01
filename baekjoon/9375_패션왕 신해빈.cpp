#include <iostream>
#include <map>
using namespace std;
int tc, n, answer;
string name, type;
map<string, int> m;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> tc;

    while (tc--)
    {
        m.clear();

        cin >> n;

        while (n--)
        {
            cin >> name >> type;

            ++m[type];
        }

        answer = 1;

        for (pair<string, int> p : m)
        {
            answer *= p.second + 1;
        }

        cout << answer - 1 << "\n";
    }
    return 0;
}
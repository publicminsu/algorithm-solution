#include <iostream>
#include <map>
#include <set>
using namespace std;
int N, problemCnt;
string temp, id;
map<string, int> m;
set<string> s;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> N;

    for (int i = 0, j; i < N; ++i)
    {
        cin >> temp >> id >> j >> temp >> temp >> temp >> temp;

        if (id == "megalusion")
        {
            continue;
        }

        if (s.find(id) != s.end())
        {
            continue;
        }

        if (j == 4)
        {
            s.insert(id);
            problemCnt += m[id];
        }
        else
        {
            ++m[id];
        }
    }

    cout << fixed;
    cout.precision(10);

    if (!(problemCnt + s.size()))
    {
        cout << 0;
    }
    else
    {
        cout << ((static_cast<double>(s.size()) / (problemCnt + s.size())) * 100);
    }
    return 0;
}
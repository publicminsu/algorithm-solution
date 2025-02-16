#include <iostream>
#include <map>
#include <algorithm>
using namespace std;
string X, Y, Z;
int k;
map<string, int> m;
void comb(const string &str, string value, int idx, int cnt)
{
    if (cnt == k)
    {
        ++m[value];
        return;
    }

    for (int i = idx; i < str.size(); ++i)
    {
        comb(str, value + str[i], i + 1, cnt + 1);
    }
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> X >> Y >> Z >> k;
    comb(X, "", 0, 0);
    comb(Y, "", 0, 0);
    comb(Z, "", 0, 0);

    bool isFind = false;

    for (auto p : m)
    {
        if (p.second >= 2)
        {
            isFind = true;
            cout << p.first << "\n";
        }
    }

    if (!isFind)
    {
        cout << -1;
    }
    return 0;
}
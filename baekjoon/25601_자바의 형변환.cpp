#include <iostream>
#include <map>
using namespace std;
int N;
map<string, string> m;
string A, B;
bool isConnect(string x, string y)
{
    const string &nx = m[x];

    if (nx.empty())
    {
        return false;
    }

    if (nx == y)
    {
        return true;
    }

    return isConnect(nx, y);
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> N;

    while (--N)
    {
        cin >> A >> B;
        m[A] = B;
    }

    cin >> A >> B;

    cout << (isConnect(A, B) || isConnect(B, A));
    return 0;
}
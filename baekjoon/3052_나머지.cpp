#include <iostream>
#include <set>
using namespace std;
set<int> s;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    for (int i = 0, j; i < 10; ++i)
    {
        cin >> j;
        s.insert(j % 42);
    }

    cout << s.size();
    return 0;
}
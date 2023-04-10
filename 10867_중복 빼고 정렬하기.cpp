#include <iostream>
#include <set>
using namespace std;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int N, i;
    set<int> s;
    cin >> N;
    while (N--)
    {
        cin >> i;
        s.insert(i);
    }
    for (int i : s)
    {
        cout << i << " ";
    }
    return 0;
}
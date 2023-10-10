#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<string> v;
string S;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> S;
    while (!S.empty())
    {
        v.push_back(S);
        S.erase(S.begin());
    }
    sort(v.begin(), v.end());
    for (string i : v)
        cout << i << "\n";
    return 0;
}
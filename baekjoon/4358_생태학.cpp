#include <iostream>
#include <map>
#include <string>
using namespace std;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cout << fixed;
    cout.precision(4);
    int cnt = 0;
    string wood;
    map<string, float> m;
    while (getline(cin, wood))
    {
        ++m[wood];
        ++cnt;
    }
    for (auto node : m)
        cout << node.first << " " << (node.second / cnt * 100) << "\n";
    return 0;
}
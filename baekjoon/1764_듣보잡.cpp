#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    unordered_map<string, int> people;
    vector<string> ret;
    int N, M;
    cin >> N >> M;
    N += M;
    while (N--)
    {
        string name;
        cin >> name;
        ++people[name];
        if (people[name] == 2)
            ret.push_back(name);
    }
    sort(ret.begin(), ret.end());
    cout << ret.size() << "\n";
    for (string name : ret)
        cout << name << "\n";
    return 0;
}
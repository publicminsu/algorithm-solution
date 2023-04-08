#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
    ios::sync_with_stdio(0),cin.tie(0);
    int N;
    cin >> N;
    vector<pair<int, pair<int, string>>> v(N);
    for (int i = 0; i < N; ++i)
    {
        int age;
        string name;
        cin >> age >> name;
        v[i] = {age, {i, name}};
    }
    sort(v.begin(), v.end());
    for (auto u : v)
    {
        cout << u.first << " " << u.second.second << "\n";
    }
    return 0;
}
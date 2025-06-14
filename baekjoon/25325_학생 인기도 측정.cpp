#include <iostream>
#include <map>
#include <algorithm>

using namespace std;
using pis = pair<int, string>;

int n;
map<string, int> indexes;
pis popularity[100];
string student;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        cin >> student;
        indexes[student] = i;
        popularity[i].second = student;
    }

    while (cin >> student)
    {
        int index = indexes[student];
        --popularity[index].first;
    }

    sort(popularity, popularity + n);

    for (int i = 0; i < n; ++i)
    {
        cout << popularity[i].second << " " << -popularity[i].first << "\n";
    }
    return 0;
}
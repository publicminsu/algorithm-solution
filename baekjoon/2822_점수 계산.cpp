#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    vector<pair<int, int>> v;
    vector<int> v2;
    int sum = 0;
    for (int i = 0; i < 8; ++i)
    {
        int number;
        cin >> number;
        sum += number;
        v.push_back({number, i + 1});
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < 8; ++i)
    {
        if (i <= 2)
        {
            sum -= v[i].first;
            if (i == 2)
                cout << sum << "\n";
        }
        else
            v2.push_back(v[i].second);
    }
    sort(v2.begin(), v2.end());
    for (int n : v2)
        cout << n << " ";
    return 0;
}
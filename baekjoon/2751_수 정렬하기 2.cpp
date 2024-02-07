#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> v;
int N;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N;
    v = vector<int>(N);
    for (int &i : v)
    {
        cin >> i;
    }

    sort(v.begin(), v.end());

    for (const int &i : v)
    {
        cout << i << "\n";
    }
    return 0;
}
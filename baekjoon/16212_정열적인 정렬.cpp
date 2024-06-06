#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N;
vector<int> v;
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
        cout << i << " ";
    }
    return 0;
}
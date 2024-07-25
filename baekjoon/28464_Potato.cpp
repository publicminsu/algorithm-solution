#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, sum, otherSum;
vector<int> a;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> N;

    a = vector<int>(N);

    for (int &i : a)
    {
        cin >> i;
        sum += i;
    }

    sort(a.begin(), a.end());

    for (int i = 0; i < a.size() / 2; ++i)
    {
        otherSum += a[i];
    }

    cout << otherSum << " " << sum - otherSum;
    return 0;
}
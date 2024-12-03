#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
int n;
ll answer;
vector<int> v;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> n;

    v = vector<int>(n);
    for (int &i : v)
    {
        cin >> i;
    }

    answer = v[n - 1];

    for (int i = n - 2; i >= 0; --i)
    {
        ll quotient = answer / v[i];

        if (answer % v[i])
        {
            ++quotient;
        }

        answer = quotient * v[i];
    }

    cout << answer;
    return 0;
}
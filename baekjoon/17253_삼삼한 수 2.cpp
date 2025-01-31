#include <iostream>
using namespace std;
using ll = long long;
ll N;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N;

    if (N == 0)
    {
        cout << "NO";
        return 0;
    }

    while (N)
    {
        if (N % 3)
        {
            --N;
        }

        if (N % 3)
        {
            cout << "NO";
            return 0;
        }

        N /= 3;
    }

    cout << "YES";
    return 0;
}
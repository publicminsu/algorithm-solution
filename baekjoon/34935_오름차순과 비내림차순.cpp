#include <iostream>
#include <climits>

using namespace std;

using ll = long long;

int N;
ll A, prevA = LLONG_MIN;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> N;

    while (N--)
    {
        cin >> A;

        if (prevA >= A)
        {
            cout << 0;
            return 0;
        }

        prevA = A;
    }

    cout << 1;
    return 0;
}
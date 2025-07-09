#include <iostream>
using namespace std;

int N;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> N;

    int sum = N * (N + 1) / 2;

    cout << sum << "\n"
         << sum * sum << "\n"
         << sum * sum;

    return 0;
}
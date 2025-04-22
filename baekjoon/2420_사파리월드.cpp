#include <iostream>
using namespace std;

long long N, M;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> N >> M;
    cout << abs(N - M);
    return 0;
}
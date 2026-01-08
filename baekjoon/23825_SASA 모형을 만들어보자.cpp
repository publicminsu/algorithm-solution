#include <iostream>
using namespace std;

int N, M;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> M;
    cout << min(N / 2, M / 2);
    return 0;
}
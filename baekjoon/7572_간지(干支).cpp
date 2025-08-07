#include <iostream>

using namespace std;

int N;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> N;

    N += 56;

    cout << (char)('A' + N % 12) << N % 10;
    return 0;
}
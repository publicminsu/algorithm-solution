#include <iostream>

using namespace std;

long long A, B;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> A >> B;

    cout << (A + B) * (A - B);

    return 0;
}
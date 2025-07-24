#include <iostream>
using namespace std;

int N;
double V, A;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cout << fixed;
    cout.precision(6);
    cin >> N;
    while (N--)
    {
        cin >> A;
        V = 1 - (1 - V) * (1 - A * 0.01);
        cout << V * 100 << "\n";
    }
    return 0;
}
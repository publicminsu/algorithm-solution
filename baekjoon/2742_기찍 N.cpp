#include <iostream>
using namespace std;

int N;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N;
    for (int i = N; i >= 1; --i)
    {
        cout << i << "\n";
    }
    return 0;
}
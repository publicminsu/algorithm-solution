#include <iostream>
using namespace std;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int N, A = -1;
    cin >> N;
    while (N--)
    {
        A += 2;
        cout << A << " ";
    }
    return 0;
}
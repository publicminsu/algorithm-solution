#include <iostream>
using namespace std;
int N, maxX, x;
float sum;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N;
    while (N--)
    {
        cin >> x;
        sum += x;
        maxX = max(maxX, x);
    }
    cout << (sum - maxX) / 2 + maxX;
    return 0;
}
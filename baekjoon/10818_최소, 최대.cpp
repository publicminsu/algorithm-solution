#include <iostream>
using namespace std;
int N, maxNum = -1000000, minNum = 1000000, num;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> N;

    while (N--)
    {
        cin >> num;

        minNum = min(minNum, num);
        maxNum = max(maxNum, num);
    }

    cout << minNum << " " << maxNum;
    return 0;
}
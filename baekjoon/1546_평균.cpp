#include <iostream>
using namespace std;
int N;
float sum, num, maxNum;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N;

    for (int i = 0; i < N; ++i)
    {
        cin >> num;

        maxNum = max(num, maxNum);

        sum += num;
    }

    cout << sum / maxNum * 100 / N;
    return 0;
}
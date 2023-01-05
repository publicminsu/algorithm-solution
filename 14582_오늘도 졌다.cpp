#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int arr[2][9], sum[2] = {
                       0,
                   };
    bool isWin = false;
    for (int i = 0; i < 2; ++i)
        for (int j = 0; j < 9; ++j)
        {
            int num;
            cin >> num;
            arr[i][j] = num;
        }
    for (int i = 0; i < 9; ++i)
    {
        sum[0] += arr[0][i];
        if (sum[0] > sum[1])
            isWin = true;
        sum[1] += arr[1][i];
        if (isWin && sum[0] < sum[1])
        {
            cout << "Yes";
            return 0;
        }
    }
    cout << "No";
    return 0;
}
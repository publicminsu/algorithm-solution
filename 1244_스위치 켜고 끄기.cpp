#include <iostream>
#include <vector>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, S;
    cin >> N;
    vector<bool> sw(N + 1);
    for (int i = 1; i <= N; ++i)
    {
        bool s;
        cin >> s;
        sw[i] = s;
    }
    cin >> S;
    while (S--)
    {
        int gender, num;
        cin >> gender >> num;
        if (gender == 1)
        {
            for (int i = num; i <= N; i += num)
            {
                sw[i] = !sw[i];
            }
        }
        else
        {
            int low, high;
            low = high = num;
            while (true)
            {
                if (low == 1 || high == N)
                {
                    break;
                }
                if (sw[low - 1] == sw[high + 1])
                {
                    --low;
                    ++high;
                }
                else
                    break;
            }
            for (int i = low; i <= high; ++i)
            {
                sw[i] = !sw[i];
            }
        }
    }
    for (int i = 1; i <= N; ++i)
    {
        cout << sw[i] << " ";
        if (!(i % 20))
            cout << "\n";
    }
    return 0;
}
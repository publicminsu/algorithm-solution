#include <iostream>
using namespace std;
int T, W, N, ret;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> T;
    while (T--)
    {
        cin >> W >> N;
        int curX = 0, curW = 0;
        ret = 0;
        while (N--)
        {
            int x_i, w_i;
            cin >> x_i >> w_i;
            curX = x_i;
            if (W < curW + w_i) // 그 지점의 쓰레기를 실었을 때 쓰레기차의 용량을 넘게 될 때.
            {
                ret += (curX << 1);
                curW = w_i;
            }
            else if (W == curW + w_i) // 쓰레기의 양이 용량에 도달했을 때.
            {
                ret += (curX << 1);
                curW = 0;
            }
            else
            {
                curW += w_i;
            }
        }
        if (curW) // 더 이상 쓰레기를 실을 지점이 없을 때.
        {
            ret += (curX << 1);
        }
        cout << ret << "\n";
    }
    return 0;
}
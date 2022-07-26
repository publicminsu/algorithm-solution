#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
#define MAX 1001
int x[20], y[20], N, totalX, totalY;
long double ret;
void recursion(int chance, int Idx, long long vecX, long long vecY)
{
    if (chance == 0)
    {
        long long X = totalX - (vecX << 1);
        long long Y = totalY - (vecY << 1);
        // 한번 빼면 더하기값만 두번빼면 벡터
        unsigned long long mag = X * X + Y * Y;
        ret = min(ret, sqrtl(mag));
        return;
    }
    if (Idx >= N)
    {
        return;
    }
    recursion(chance, Idx + 1, vecX, vecY);
    recursion(chance - 1, Idx + 1, vecX + x[Idx], vecY + y[Idx]);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    cin >> T;
    cout.precision(19);
    while (T--)
    {
        ret = 1e10, totalX = totalY = 0;
        cin >> N;
        for (int i = 0; i < N; ++i)
        {
            cin >> x[i] >> y[i];
            totalX += x[i];
            totalY += y[i];
        }
        recursion(N / 2, 0, 0, 0);
        cout << ret << endl;
    }
}
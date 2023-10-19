#include <iostream>
using namespace std;
int N, M, ret = 0;
void comb(int idx, int sum)
{
    if (idx == N)
    {
        if (sum == M)
            ++ret;
        return;
    }
    for (int i = 0; i <= M; ++i)
    {
        int nextSum = sum + i;
        if (nextSum > M)
            break;
        comb(idx + 1, nextSum);
    }
}
int main()
{
    scanf("%d %d", &N, &M);
    M -= N;
    comb(0, 0);
    printf("%d", ret);
    return 0;
}
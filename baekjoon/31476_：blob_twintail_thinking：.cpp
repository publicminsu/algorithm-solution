#include <iostream>
using namespace std;
int D, N, U, T;
int totalCnt, twinSum, ponySum;
bool isBlocked[4096];

void input()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> D >> N >> U >> T;
    while (N--)
    {
        int s, e;
        cin >> s >> e;
        isBlocked[e] = true;
    }
}

void twinRecur(int idx, int cnt, int sum)
{
    if (idx > totalCnt)
    {
        return;
    }

    if (idx != 1)
    {
        sum += U + T * cnt;
        twinSum = max(sum, twinSum);
    }

    int leftIdx = idx * 2;
    int rightIdx = leftIdx + 1;
    int nextCnt = cnt;

    bool isBlockedLeft = isBlocked[leftIdx];
    bool isBlockedright = isBlocked[rightIdx];

    if (!isBlockedLeft && !isBlockedright)
    {
        nextCnt += 1;
    }

    if (!isBlockedLeft)
    {
        twinRecur(leftIdx, nextCnt, sum);
    }

    if (!isBlockedright)
    {
        twinRecur(rightIdx, nextCnt, sum);
    }
}

int ponyRecur(int idx, int depth)
{
    if (idx > totalCnt)
    {
        return depth - 1;
    }

    if (idx != 1)
    {
        ponySum += U * 2;
    }

    int leftIdx = idx * 2;
    int rightIdx = leftIdx + 1;
    int retDepth = depth;

    bool isBlockedLeft = isBlocked[leftIdx];
    bool isBlockedright = isBlocked[rightIdx];

    if (!isBlockedLeft)
    {
        retDepth = ponyRecur(leftIdx, depth + 1);
    }

    if (!isBlockedright)
    {
        retDepth = ponyRecur(rightIdx, depth + 1);
    }

    return retDepth;
}

void solve()
{
    totalCnt = (1 << D) - 1;

    twinRecur(1, 0, 0);

    int depth = ponyRecur(1, 0);
    ponySum -= U * depth;

    if (twinSum < ponySum)
    {
        cout << ":blob_twintail_aww:";
    }
    else if (twinSum == ponySum)
    {
        cout << ":blob_twintail_thinking:";
    }
    else
    {
        cout << ":blob_twintail_sad:";
    }
}

int main()
{
    input();
    solve();
    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int aSize, bSize, aIndex = 0, bIndex, ret;
vector<int> A, B;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> aSize >> bSize;
    A = vector<int>(aSize);
    B = vector<int>(bSize);

    for (int i = 0; i < aSize; ++i)
    {
        cin >> A[i];
    }
    for (int i = 0; i < bSize; ++i)
    {
        cin >> B[i];
    }

    // 정렬
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    while (aIndex < aSize && bIndex < bSize) // 끝에 도달하지 않았다면
    {
        if (A[aIndex] < B[bIndex]) // B가 더 크다면
        {
            ++aIndex;
            ++ret;
        }
        else if (A[aIndex] > B[bIndex]) // A가 더 크다면
        {
            ++bIndex;
            ++ret;
        }
        else // 같다면
        {
            ++aIndex;
            ++bIndex;
        }
    }
    ret += (bSize - bIndex) + (aSize - aIndex); // 남은 개수 더해주기
    cout << ret;
    return 0;
}
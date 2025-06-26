#include <iostream>
using namespace std;

#define MAX_SIZE 1002

struct index
{
    int left, right;
};

int n, L, totalSum;

index indexes[1000];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> L;

        int prefixSum = 0;
        int maxSum = -987654321;

        for (int j = 1, num; j <= L; ++j)
        {
            index idx;
            cin >> num;

            if (prefixSum > 0)
            {
                idx.right = j;
            }
            else
            {
                prefixSum = 0;
                idx.left = j;
                idx.right = j;
            }

            prefixSum = prefixSum + num;

            if (maxSum == prefixSum)
            {
                index &maxSumIdx = indexes[i];

                if (idx.right - idx.left < maxSumIdx.right - maxSumIdx.left)
                {
                    maxSumIdx = idx;
                }
            }
            else if (maxSum < prefixSum)
            {
                indexes[i] = idx;
                maxSum = prefixSum;
            }
        }

        totalSum += maxSum;
    }

    cout << totalSum;

    for (int i = 0; i < n; ++i)
    {
        const index &idx = indexes[i];
        cout << "\n"
             << idx.left << " " << idx.right;
    }

    return 0;
}
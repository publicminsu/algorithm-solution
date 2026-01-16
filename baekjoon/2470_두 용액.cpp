#include <iostream>
#include <algorithm>

using namespace std;

int N, leftIdx, rightIdx;
int nums[100000];
int answer[2];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        cin >> nums[i];
    }

    sort(nums, nums + N);

    rightIdx = N - 1;
    answer[0] = nums[leftIdx];
    answer[1] = nums[rightIdx];

    while (leftIdx < rightIdx)
    {
        int leftNum = nums[leftIdx];
        int rightNum = nums[rightIdx];

        int diff = (leftNum + rightNum);

        if (abs(answer[0] + answer[1]) > abs(diff))
        {
            answer[0] = leftNum;
            answer[1] = rightNum;
        }

        if (diff < 0)
        {
            ++leftIdx;
        }
        else
        {
            --rightIdx;
        }
    }

    cout << answer[0] << " " << answer[1];
    return 0;
}
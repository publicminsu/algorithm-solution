#include <iostream>
using namespace std;

int N;
int nums[100001];
long long prefixSums[100001];
long long answer;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N;

    for (int i = 1; i <= N; ++i)
    {
        cin >> nums[i];
        prefixSums[i] = prefixSums[i - 1] + nums[i];
    }

    for (int i = 1; i <= N; ++i)
    {
        answer += nums[i] * prefixSums[i - 1];
    }

    cout << answer;
    return 0;
}
#include <iostream>
#include <queue>

using namespace std;

int N, M, cnt, sum;
queue<int> nums;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> N >> M;

    for (int i = 0; i < N; ++i)
    {
        int num;
        cin >> num;

        sum += num;
        nums.push(num);

        while (sum > M)
        {
            num = nums.front();
            nums.pop();

            sum -= num;
        }

        if (sum == M)
        {
            ++cnt;
        }
    }

    cout << cnt;
    return 0;
}
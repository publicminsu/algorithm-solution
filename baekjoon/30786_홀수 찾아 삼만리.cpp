#include <iostream>
#include <vector>
using namespace std;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int N, x, y;
    vector<int> nums[2];
    cin >> N;
    for (int i = 1; i <= N; ++i)
    {
        cin >> x >> y;
        nums[(x + y) % 2].push_back(i);
    }
    if (nums[0].size() == 0 || nums[1].size() == 0) // 홀수 또는 짝수가 없다면
    {
        cout << "NO";
    }
    else
    {
        cout << "YES"
             << "\n";
        for (int i = 0; i < 2; ++i)
        {
            for (int j : nums[i])
            {
                cout << j << " ";
            }
        }
    }
    return 0;
}
#include <iostream>
bool visted[2000001];
int nums[20];
using namespace std;
int N, num;
void make(int idx, int sum)
{
    if (idx == N)
    {
        visted[sum] = true;
        return;
    }
    make(idx + 1, sum + nums[idx]);
    make(idx + 1, sum);
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        cin >> num;
        nums[i] = num;
    }
    make(0, 0);
    for (int i = 1; i < 2000001; ++i)
    {
        if (!visted[i])
        {
            cout << i;
            break;
        }
    }
}
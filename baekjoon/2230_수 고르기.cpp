#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int abs(int num)
{
    return num < 0 ? -num : num;
}
int min(int num1, int num2)
{
    return num1 > num2 ? num2 : num1;
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int N, M, ret = 2000000000, front = 0, back = 0;
    cin >> N >> M;
    vector<int> A(N);
    for (int i = 0; i < N; ++i)
        cin >> A[i];
    sort(A.begin(), A.end());
    while (true)
    {
        int gap = abs(A[back] - A[front]);
        if (gap >= M)
        {
            ++front;
            ret = min(ret, gap);
            if (gap == 0)
                break;
            else if (front == back)
                ++back;
        }
        else
        {
            ++back;
        }
        if (back == N)
            break;
    }
    cout << ret;
    return 0;
}
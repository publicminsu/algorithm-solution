#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, x, startIndex, endIndex, cnt;
vector<int> a;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    a = vector<int>(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    cin >> x;
    sort(a.begin(), a.end());
    endIndex = n - 1;
    while (startIndex < endIndex)
    {
        int sum = a[startIndex] + a[endIndex];
        if (sum == x) // 같다면 두 값 모두 사용 불가 (서로 다른 정수이므로)
        {
            ++cnt;
            ++startIndex;
            --endIndex;
        }
        else if (sum > x) // 합이 높다면 값 줄이기
            --endIndex;
        else // 작다면 값 높이기
            ++startIndex;
    }
    cout << cnt;
    return 0;
}
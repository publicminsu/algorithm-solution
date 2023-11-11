#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int R, C, N, index = 0, cnt = 0;
    cin >> R >> C >> N;
    vector<int> h(N), map(C);
    for (int i = 0; i < N; ++i)
    {
        cin >> h[i];
    }
    sort(h.begin(), h.end());
    for (int i = 0; i < N; ++i)
    {
        if (h[i] > map[index]) // 이전에 전시한 높이보다 더 크다면
        {
            map[index] = h[i];
            ++cnt;
            index = (index + 1) % C;
        }
    }
    if (cnt > R * C) // 이미 탁자가 가득 찼다면
    {
        cnt = R * C;
    }
    cout << cnt;
}

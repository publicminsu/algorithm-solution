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
        if (h[i] > map[index]) // ������ ������ ���̺��� �� ũ�ٸ�
        {
            map[index] = h[i];
            ++cnt;
            index = (index + 1) % C;
        }
    }
    if (cnt > R * C) // �̹� Ź�ڰ� ���� á�ٸ�
    {
        cnt = R * C;
    }
    cout << cnt;
}

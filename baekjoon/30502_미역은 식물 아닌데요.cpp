#include <iostream>
#include <vector>
using namespace std;
int N, M;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> M;
    vector<vector<int>> v(N + 1, vector<int>(2, -1));
    while (M--)
    {
        int a, c;
        char b;
        cin >> a >> b >> c;
        if (b == 'P') // ���ռ��� ���
        {
            v[a][0] = c;
        }
        else // ����� ���
        {
            v[a][1] = c;
        }
    }
    int min = 0, max = 0;
    for (int i = 1; i <= N; ++i)
    {
        if (v[i][0] != 0 && v[i][1] != 1) // ���ռ��� ���� �ʴ� ��찡 �ƴϸ鼭 ����� �ִ� ��찡 �ƴ� ��
        {
            ++max;
            if (v[i][0] == 1 && v[i][1] == 0) // ���ռ��� �ϰ� ����� ���� ���
            {
                ++min;
            }
        }
    }
    cout << min << " " << max;
    return 0;
}
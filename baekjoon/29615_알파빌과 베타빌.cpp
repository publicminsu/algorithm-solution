#include <iostream>
using namespace std;

int N, M, cnt;
bool isAlpha[1001];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> N >> M;

    for (int i = 0, num; i < N; ++i)
    {
        cin >> num;

        if (i < M)
        {
            isAlpha[num] = true;
        }
    }

    for (int i = 0, num; i < M; ++i)
    {
        cin >> num;

        cnt += !isAlpha[num];
    }

    cout << cnt;
    return 0;
}
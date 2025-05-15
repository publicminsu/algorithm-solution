#include <iostream>

using namespace std;

int N, M, answer;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> N >> M;

    M -= N;

    for (int i = 0, H; i < N; ++i)
    {
        cin >> H;
        M -= H;
    }

    if (M <= 0)
    {
        cout << 0;
        return 0;
    }

    int minValue = M / (N + 1);
    int maxCount = M % (N + 1);

    answer += (minValue + 1) * (minValue + 1) * maxCount;

    for (int i = 1; i <= minValue; ++i)
    {
        answer += i * i * (N + 1);
    }

    cout << answer;
    return 0;
}

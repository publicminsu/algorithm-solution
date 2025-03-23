#include <iostream>
using namespace std;
int N, K;
bool isVisited[360];
int angles[10];

void dfs(int angle)
{
    if (isVisited[angle])
    {
        return;
    }

    isVisited[angle] = true;

    for (int i = 0; i < N; ++i)
    {
        int nextAngle = (angle + angles[i]) % 360;
        dfs(nextAngle);

        nextAngle = (angle - angles[i] + 360) % 360;
        dfs(nextAngle);
    }
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> N >> K;

    for (int i = 0; i < N; ++i)
    {
        cin >> angles[i];
    }

    for (int i = 0; i < N; ++i)
    {
        dfs(angles[i]);
    }

    while (K--)
    {
        int num;
        cin >> num;
        cout << (isVisited[num] ? "YES" : "NO") << "\n";
    }
    return 0;
}
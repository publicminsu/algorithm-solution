#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct info
{
    int X, Y, V;
};

int N, K, T;
int Xp, Yp, Vi, Yi;
info friendInfos[3001];
int friendStates[3001];
vector<int> answer;
queue<info> q;

void input()
{
    ios::sync_with_stdio(0), cin.tie(0);

    info myInfo;

    cin >> N >> K >> T;
    cin >> myInfo.X >> myInfo.Y >> myInfo.V;

    q.push(myInfo);

    for (int i = 1; i <= N; ++i)
    {
        info &friendInfo = friendInfos[i];
        cin >> friendInfo.X >> friendInfo.Y >> friendInfo.V >> friendStates[i];
    }
}

void solve()
{
    answer.reserve(N);

    while (!q.empty())
    {
        info currentInfo = q.front();

        q.pop();

        for (int i = 1; i <= N; ++i)
        {
            if (friendStates[i] == -1)
            {
                continue;
            }

            info friendInfo = friendInfos[i];

            if (abs(currentInfo.V - friendInfo.V) > T)
            {
                continue;
            }

            int diffX = friendInfo.X - currentInfo.X;
            int diffY = friendInfo.Y - currentInfo.Y;

            if (diffX * diffX + diffY * diffY > K * K)
            {
                continue;
            }

            if (friendStates[i] == 1)
            {
                answer.push_back(i);
            }
            friendStates[i] = -1;

            q.push(friendInfo);
        }
    }

    sort(answer.begin(), answer.end());

    if (answer.size() == 0)
    {
        cout << 0;
    }
    else
    {
        for (int &i : answer)
        {
            cout << i << " ";
        }
    }
}

int main()
{
    input();
    solve();
    return 0;
}
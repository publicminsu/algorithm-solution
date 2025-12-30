#include <iostream>
#include <queue>

using namespace std;
using pii = pair<int, int>;

int K;
int nums[1024];
int numSize;

void input()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> K;

    numSize = (1 << K) - 1;

    for (int i = 0; i < numSize; ++i)
    {
        cin >> nums[i];
    }
}

void bfs()
{
    queue<pii> q;
    q.push({0, numSize});

    for (int i = 0; i < K; ++i)
    {
        int qSize = q.size();

        for (int j = 0; j < qSize; ++j)
        {
            pii curRange = q.front();
            q.pop();

            int mid = (curRange.first + curRange.second) / 2;

            cout << nums[mid] << " ";

            q.push({curRange.first, mid});
            q.push({mid, curRange.second});
        }
        cout << "\n";
    }
}

int main()
{
    input();
    bfs();
    return 0;
}
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
#define MAX 1001
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T, time[MAX], inDegree[MAX], result[MAX];
    vector<int> next[MAX];
    queue<int> q;
    cin >> T;
    for (int testCase = 0; testCase < T; ++testCase)
    {
        q = queue<int>();
        memset(inDegree, 0, sizeof(inDegree));
        memset(next, 0, sizeof(next));
        memset(time, 0, sizeof(time));
        int N, K, W;
        cin >> N >> K;
        for (int i = 1; i <= N; ++i)
        {
            cin >> time[i];
            result[i] = time[i];
        }
        for (int i = 0; i < K; ++i)
        {
            int X, Y;
            cin >> X >> Y;
            next[X].push_back(Y);
            inDegree[Y]++;
        }
        cin >> W;
        for (int i = 1; i <= N; ++i)
        {
            if (inDegree[i] == 0) // 진입 차수가 0개면.
            {
                q.push(i);
            }
        }
        while (!q.empty())
        {
            int curX = q.front();
            q.pop();
            for (int i = 0; i < next[curX].size(); i++)
            {
                int nextX = next[curX][i];
                --inDegree[nextX];
                result[nextX] = max(result[nextX], result[curX] + time[nextX]); // 다음 정점의 값 vs 현재 정점 값 + 시간
                if (inDegree[nextX] == 0)
                {
                    q.push(nextX);
                }
            }
        }
        cout << result[W] << endl; // 목표 지점의 결과값
    }
    return 0;
}

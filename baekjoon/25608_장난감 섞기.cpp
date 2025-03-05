#include <iostream>
using namespace std;

int N, M;
int nums[10][10000];
int sums[10][3];
bool isVisited[10];
int answer = 0;

void calcSums()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> N >> M;

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            cin >> nums[i][j];
        }

        int sum = 0;
        for (int j = 0; j < M; ++j)
        {
            sum += nums[i][j];
            sums[i][1] = max(sums[i][1], sum);
        }
        sums[i][1] = max(sums[i][1], 0);
        sums[i][0] = max(sum, 0);

        sum = 0;
        for (int j = M - 1; j >= 0; --j)
        {
            sum += nums[i][j];
            sums[i][2] = max(sums[i][2], sum);
        }

        sum = 0;
        for (int j = 0; j < M; ++j)
        {
            sum = max(sum + nums[i][j], nums[i][j]);
            answer = max(answer, sum);
        }
    }
}

void dfs(int index)
{
    if (index == N)
    {
        int sum = 0;

        for (int i = 0; i < N; ++i)
        {
            if (isVisited[i])
            {
                sum += sums[i][0];
            }
        }

        answer = max(answer, sum);

        for (int i = 0; i < N; ++i)
        {
            if (isVisited[i])
            {
                continue;
            }

            int leftSum = sum + sums[i][1];
            int rightSum = sum + sums[i][2];

            answer = max(answer, leftSum);
            answer = max(answer, rightSum);

            for (int j = i + 1; j < N; ++j)
            {
                if (isVisited[j])
                {
                    continue;
                }

                answer = max(answer, leftSum + sums[j][2]);
                answer = max(answer, rightSum + sums[j][1]);
            }
        }

        return;
    }

    for (int i = index; i < N; ++i)
    {
        isVisited[i] = true;
        dfs(i + 1);
        isVisited[i] = false;
    }
    dfs(index + 1);
}

int main()
{
    calcSums();
    dfs(0);
    cout << answer;
    return 0;
}
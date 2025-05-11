#include <iostream>
#include <algorithm>
using namespace std;
using pii = pair<int, int>;

int N;
pii scores[4][200000];
bool isVisited[200001];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> N;

    for (int i = 0; i < N; ++i)
    {
        int num, score;

        cin >> num;

        for (int j = 0; j < 4; ++j)
        {
            cin >> score;

            scores[j][i] = {-score, num};
        }
    }

    for (int i = 0; i < 4; ++i)
    {
        sort(scores[i], scores[i] + N);
    }

    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            int num = scores[i][j].second;

            if (isVisited[num])
            {
                continue;
            }

            isVisited[num] = true;
            cout << num << " ";
            break;
        }
    }
    return 0;
}
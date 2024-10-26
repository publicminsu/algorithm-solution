#include <iostream>
using namespace std;
int N, answer;
char mobis[] = {'M', 'O', 'B', 'I', 'S'};
int dy[] = {1, 0, -1, 0, 1, 1, -1, -1};
int dx[] = {0, 1, 0, -1, 1, -1, 1, -1};
string map[101];
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        cin >> map[i];
    }

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            for (int k = 0; k < 8; ++k)
            {
                bool isFind = true;

                for (int l = 0; l < 5; ++l)
                {
                    int ny = i + dy[k] * l;
                    int nx = j + dx[k] * l;

                    if (ny < 0 || nx < 0 || ny >= N || nx >= N || map[ny][nx] != mobis[l])
                    {
                        isFind = false;
                        break;
                    }
                }

                if (isFind)
                {
                    ++answer;
                }
            }
        }
    }
    cout << answer;
    return 0;
}
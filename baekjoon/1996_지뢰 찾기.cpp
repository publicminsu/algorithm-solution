#include <iostream>
#include <vector>
using namespace std;
using pii = pair<int, int>;
vector<vector<int>> cnt;
vector<vector<char>> map;
pii dir[] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
int N;
int main()
{
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> N;
  cnt = vector<vector<int>>(N, vector<int>(N));
  map = vector<vector<char>>(N, vector<char>(N));
  for (int i = 0; i < N; ++i)
  {
    for (int j = 0; j < N; ++j)
    {
      cin >> map[i][j];
      if (map[i][j] == '.')
      {
        continue;
      }
      for (pii d : dir) // 폭탄 범위
      {
        int ny = d.first + i;
        int nx = d.second + j;
        if (ny < 0 || nx < 0 || ny >= N || nx >= N)
        {
          continue;
        }
        cnt[ny][nx] += map[i][j] - '0';
      }
    }
  }

  for (int i = 0; i < N; ++i)
  {
    for (int j = 0; j < N; ++j)
    {
      if (map[i][j] == '.') // 폭탄이 아니면
      {
        if (cnt[i][j] >= 10) // 10 이상이면
        {
          cout << 'M';
        }
        else
        {
          cout << cnt[i][j];
        }
      }
      else
      {
        cout << '*';
      }
    }
    cout << "\n";
  }
  return 0;
}
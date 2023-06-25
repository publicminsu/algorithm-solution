#include <iostream>
#include <vector>
using namespace std;
int N, blue = 0, white = 0;
vector<vector<int>> paper;
void slice(int sY, int eY, int sX, int eX)
{
    bool first = paper[sY][sX];
    for (int y = sY; y < eY; ++y)
        for (int x = sX; x < eX; ++x)
            if (first != paper[y][x])
            {
                int midY = (sY + eY) >> 1, midX = (sX + eX) >> 1;
                slice(sY, midY, sX, midX);
                slice(sY, midY, midX, eX);
                slice(midY, eY, sX, midX);
                slice(midY, eY, midX, eX);
                return;
            }
    first ? ++blue : ++white;
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N;
    paper = vector<vector<int>>(N, vector<int>(N));
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cin >> paper[i][j];
    slice(0, N, 0, N);
    cout << white << "\n"
         << blue;
    return 0;
}
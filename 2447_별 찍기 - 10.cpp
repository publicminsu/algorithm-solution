#include <iostream>
#include <vector>
using namespace std;
vector<vector<char>> map;
int N;
void part(int sX, int eX, int sY, int eY)
{
    if (eX - sX == 1)
        return;
    int gapX = (eX - sX) / 3, gapY = (eY - sY) / 3;
    for (int i = sY + gapY; i < eY - gapY; ++i)
        for (int j = sX + gapX; j < eX - gapX; ++j)
            map[i][j] = ' ';

    for (int i = sY; i < eY; i += gapY)
        for (int j = sX; j < eX; j += gapX)
        {
            part(j, j + gapX, i, i + gapY);
        }
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N;
    map = vector<vector<char>>(N, vector<char>(N, '*'));
    part(0, N, 0, N);
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
            cout << map[i][j];
        cout << "\n";
    }
    return 0;
}
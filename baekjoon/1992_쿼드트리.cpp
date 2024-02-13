#include <iostream>
#include <vector>
using namespace std;
int N;
vector<string> map;
bool isCompression(int startY, int startX, int endY, int endX)
{
    for (int i = startY; i < endY; ++i)
    {
        for (int j = startX; j < endX; ++j)
        {
            if (map[startY][startX] != map[i][j]) // 처음 값과 같은 경우가 아니면 false
            {
                return false;
            }
        }
    }
    return true;
}
void recur(int startY, int startX, int endY, int endX)
{
    if (isCompression(startY, startX, endY, endX))
    {
        cout << map[startY][startX];
    }
    else
    {
        cout << "(";
        int midY = (endY + startY) >> 1;
        int midX = (endX + startX) >> 1;
        recur(startY, startX, midY, midX);
        recur(startY, midX, midY, endX);
        recur(midY, startX, endY, midX);
        recur(midY, midX, endY, endX);
        cout << ")";
    }
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N;
    map = vector<string>(N);
    for (string &line : map)
    {
        cin >> line;
    }
    recur(0, 0, N, N);
    return 0;
}
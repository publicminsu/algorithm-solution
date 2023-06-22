#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N;
vector<vector<int>> chair;
int recur(int startY, int endY, int startX, int endX)
{
    if (startX + 1 == endX)
        return chair[startY][startX];
    int midY = (startY + endY) >> 1, midX = (startX + endX) >> 1;
    vector<int> v{
        recur(startY, midY, startX, midX),
        recur(startY, midY, midX, endX),
        recur(midY, endY, startX, midX),
        recur(midY, endY, midX, endX)};
    sort(v.begin(), v.end());
    return v[1];
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N;
    chair = vector<vector<int>>(N, vector<int>(N));
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
        {
            cin >> chair[i][j];
        }
    cout << recur(0, N, 0, N);
    return 0;
}
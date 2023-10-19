#include <iostream>
#include <vector>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int H, W, X, Y;
    cin >> H >> W >> X >> Y;
    vector<vector<int>> vec(H + X, vector<int>(W + Y));
    for (int i = 0; i < H + X; ++i)
        for (int j = 0; j < W + Y; ++j)
        {
            int k;
            cin >> k;
            vec[i][j] = k;
        }
    for (int i = 0; i < H; ++i)
    {
        for (int j = 0; j < W; ++j)
        {
            cout << vec[i][j] << " ";
            vec[i + X][j + Y] -= vec[i][j];
        }
        cout << "\n";
    }
    return 0;
}
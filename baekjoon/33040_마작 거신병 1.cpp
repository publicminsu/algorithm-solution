#include <iostream>
#include <vector>
using namespace std;
vector<int> map;
int H, W, C, D;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> H >> W >> C >> D;
    map = vector<int>(H);

    for (int i = 1; i < H; ++i)
    {
        map[i] = i;
        if (i > W)
        {
            cout << -1;
            return 0;
        }

        D -= i;

        if (D < 0)
        {
            cout << -1;
            return 0;
        }
    }

    for (int i = H - 1, w = W; i >= 0; --i)
    {
        int value = min(D, w - map[i]);

        D -= value;

        map[i] += value;

        --w;
    }

    if (D > 0)
    {
        cout << -1;
        return 0;
    }

    for (int i = 0; i < H; ++i)
    {
        for (int j = 0; j < W; ++j)
        {
            if (map[i] > j)
            {
                cout << 9;
            }
            else
            {
                cout << 1;
            }
            cout << " ";
        }
        cout << "\n";
    }
    return 0;
}
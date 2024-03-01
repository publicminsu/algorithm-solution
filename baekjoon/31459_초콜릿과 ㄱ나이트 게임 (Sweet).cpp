#include <iostream>
using namespace std;
int T, X, Y, x, y;
bool map[51][51];
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> T;
    while (T--)
    {
        cin >> X >> Y >> x >> y;
        int count = 0, right = X, bot = Y;
        bool isKnight = true;

        while (right >= 0 && bot >= 0)
        {
            for (int i = 0; i < right; ++i)
            {
                for (int j = 0; j < bot; ++j)
                {
                    map[i][j] = isKnight;
                }
            }
            isKnight = !isKnight;
            right -= x;
            bot -= y;
        }

        for (int i = 0; i < X; ++i)
        {
            for (int j = 0; j < Y; ++j)
            {
                if (map[i][j])
                {
                    ++count;
                }
            }
        }
        cout << count << "\n";
    }
    return 0;
}
#include <iostream>
using namespace std;

int L;
int arcaneLevels[6][3] = {{200, 210, 220}, {210, 220, 225}, {220, 225, 230}, {225, 230, 235}, {230, 235, 245}, {235, 245, 250}};
int grandisLevel = 260;
int monsters[3] = {500, 300, 100};

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> L;

    for (int i = 0; i < 6; ++i)
    {
        int monster = 0;

        for (int j = 0; j < 3; ++j)
        {
            if (arcaneLevels[i][j] <= L)
            {
                monster = monsters[j];
            }
        }

        cout << monster << " ";
    }

    cout << "\n";

    for (int i = 0; i < 7; ++i)
    {
        int startLevel = grandisLevel + i * 5;
        int monster = 0;

        for (int j = 0; j < 3; ++j)
        {
            int level = startLevel + j * 5;

            if (level <= L)
            {
                monster = monsters[j];
            }
        }

        cout << monster << " ";
    }
    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using pii = pair<int, int>;
using psii = pair<string, pii>;
string matrix[9][9];
vector<psii> v;
vector<string> temp;

void init()
{
    ios::sync_with_stdio(0), cin.tie(0);

    v.reserve(8);
    temp.reserve(8);

    for (int i = 0; i < 9; ++i)
    {
        for (int j = 0; j < 9; ++j)
        {
            cin >> matrix[i][j];
        }
    }

    for (int i = 1; i < 9; i += 3)
    {
        for (int j = 1; j < 9; j += 3)
        {
            if (i == j && i == 4)
            {
                continue;
            }

            v.push_back({matrix[i][j], {i, j}});
        }
    }

    sort(v.begin(), v.end());
}

void printMat(int idx, psii p)
{
    cout << "#" << idx << ". " << p.first << "\n";
    pii pos = p.second;

    temp.clear();

    for (int i = -1; i <= 1; ++i)
    {
        for (int j = -1; j <= 1; ++j)
        {
            if (i == j && i == 0)
            {
                continue;
            }

            int y = i + pos.first;
            int x = j + pos.second;

            temp.push_back(matrix[y][x]);
        }
    }

    sort(temp.begin(), temp.end());

    for (int i = 0; i < v.size(); ++i)
    {
        cout << "#" << idx << "-" << i + 1 << ". " << temp[i] << "\n";
    }
}

int main()
{
    init();
    for (int i = 0; i < v.size(); ++i)
    {
        printMat(i + 1, v[i]);
    }
    return 0;
}
#include <iostream>
#include <vector>
#include <string>
using namespace std;
char cube[6][3][3], temp[3][3], tempLine[3];
void init()
{
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
        {
            cube[0][i][j] = 'w';
            cube[1][i][j] = 'y';
            cube[2][i][j] = 'r';
            cube[3][i][j] = 'o';
            cube[4][i][j] = 'g';
            cube[5][i][j] = 'b';
        }
}
void roll(string &cmd)
{
    char face = cmd[0];
    int target;
    if (face == 'U')
    {
        target = 0;
        if (cmd[1] == '+')
        {
            tempLine[0] = cube[5][0][0], tempLine[1] = cube[5][0][1], tempLine[2] = cube[5][0][2];
            cube[5][0][0] = cube[3][0][0], cube[5][0][1] = cube[3][0][1], cube[5][0][2] = cube[3][0][2];
            cube[3][0][0] = cube[4][0][0], cube[3][0][1] = cube[4][0][1], cube[3][0][2] = cube[4][0][2];
            cube[4][0][0] = cube[2][0][0], cube[4][0][1] = cube[2][0][1], cube[4][0][2] = cube[2][0][2];
            cube[2][0][0] = tempLine[0], cube[2][0][1] = tempLine[1], cube[2][0][2] = tempLine[2];
        }
        else
        {
            tempLine[0] = cube[5][0][0], tempLine[1] = cube[5][0][1], tempLine[2] = cube[5][0][2];
            cube[5][0][0] = cube[2][0][0], cube[5][0][1] = cube[2][0][1], cube[5][0][2] = cube[2][0][2];
            cube[2][0][0] = cube[4][0][0], cube[2][0][1] = cube[4][0][1], cube[2][0][2] = cube[4][0][2];
            cube[4][0][0] = cube[3][0][0], cube[4][0][1] = cube[3][0][1], cube[4][0][2] = cube[3][0][2];
            cube[3][0][0] = tempLine[0], cube[3][0][1] = tempLine[1], cube[3][0][2] = tempLine[2];
        }
    }
    else if (face == 'D')
    {
        target = 1;
        if (cmd[1] == '+')
        {
            tempLine[0] = cube[5][2][0], tempLine[1] = cube[5][2][1], tempLine[2] = cube[5][2][2];
            cube[5][2][0] = cube[2][2][0], cube[5][2][1] = cube[2][2][1], cube[5][2][2] = cube[2][2][2];
            cube[2][2][0] = cube[4][2][0], cube[2][2][1] = cube[4][2][1], cube[2][2][2] = cube[4][2][2];
            cube[4][2][0] = cube[3][2][0], cube[4][2][1] = cube[3][2][1], cube[4][2][2] = cube[3][2][2];
            cube[3][2][0] = tempLine[0], cube[3][2][1] = tempLine[1], cube[3][2][2] = tempLine[2];
        }
        else
        {
            tempLine[0] = cube[5][2][0], tempLine[1] = cube[5][2][1], tempLine[2] = cube[5][2][2];
            cube[5][2][0] = cube[3][2][0], cube[5][2][1] = cube[3][2][1], cube[5][2][2] = cube[3][2][2];
            cube[3][2][0] = cube[4][2][0], cube[3][2][1] = cube[4][2][1], cube[3][2][2] = cube[4][2][2];
            cube[4][2][0] = cube[2][2][0], cube[4][2][1] = cube[2][2][1], cube[4][2][2] = cube[2][2][2];
            cube[2][2][0] = tempLine[0], cube[2][2][1] = tempLine[1], cube[2][2][2] = tempLine[2];
        }
    }
    else if (face == 'F')
    {
        target = 2;
        if (cmd[1] == '+')
        {
            tempLine[0] = cube[5][0][0], tempLine[1] = cube[5][1][0], tempLine[2] = cube[5][2][0];
            cube[5][0][0] = cube[0][2][0], cube[5][1][0] = cube[0][2][1], cube[5][2][0] = cube[0][2][2];
            cube[0][2][0] = cube[4][2][2], cube[0][2][1] = cube[4][1][2], cube[0][2][2] = cube[4][0][2];
            cube[4][2][2] = cube[1][0][2], cube[4][1][2] = cube[1][0][1], cube[4][0][2] = cube[1][0][0];
            cube[1][0][2] = tempLine[0], cube[1][0][1] = tempLine[1], cube[1][0][0] = tempLine[2];
        }
        else
        {
            tempLine[0] = cube[5][0][0], tempLine[1] = cube[5][1][0], tempLine[2] = cube[5][2][0];
            cube[5][0][0] = cube[1][0][2], cube[5][1][0] = cube[1][0][1], cube[5][2][0] = cube[1][0][0];
            cube[1][0][2] = cube[4][2][2], cube[1][0][1] = cube[4][1][2], cube[1][0][0] = cube[4][0][2];
            cube[4][2][2] = cube[0][2][0], cube[4][1][2] = cube[0][2][1], cube[4][0][2] = cube[0][2][2];
            cube[0][2][0] = tempLine[0], cube[0][2][1] = tempLine[1], cube[0][2][2] = tempLine[2];
        }
    }
    else if (face == 'B')
    {
        target = 3;
        if (cmd[1] == '+')
        {
            tempLine[0] = cube[5][2][2], tempLine[1] = cube[5][1][2], tempLine[2] = cube[5][0][2];
            cube[5][2][2] = cube[1][2][0], cube[5][1][2] = cube[1][2][1], cube[5][0][2] = cube[1][2][2];
            cube[1][2][0] = cube[4][0][0], cube[1][2][1] = cube[4][1][0], cube[1][2][2] = cube[4][2][0];
            cube[4][0][0] = cube[0][0][2], cube[4][1][0] = cube[0][0][1], cube[4][2][0] = cube[0][0][0];
            cube[0][0][2] = tempLine[0], cube[0][0][1] = tempLine[1], cube[0][0][0] = tempLine[2];
        }
        else
        {
            tempLine[0] = cube[5][2][2], tempLine[1] = cube[5][1][2], tempLine[2] = cube[5][0][2];
            cube[5][2][2] = cube[0][0][2], cube[5][1][2] = cube[0][0][1], cube[5][0][2] = cube[0][0][0];
            cube[0][0][2] = cube[4][0][0], cube[0][0][1] = cube[4][1][0], cube[0][0][0] = cube[4][2][0];
            cube[4][0][0] = cube[1][2][0], cube[4][1][0] = cube[1][2][1], cube[4][2][0] = cube[1][2][2];
            cube[1][2][0] = tempLine[0], cube[1][2][1] = tempLine[1], cube[1][2][2] = tempLine[2];
        }
    }
    else if (face == 'L')
    {
        target = 4;
        if (cmd[1] == '+')
        {
            tempLine[0] = cube[0][0][0], tempLine[1] = cube[0][1][0], tempLine[2] = cube[0][2][0];
            cube[0][0][0] = cube[3][2][2], cube[0][1][0] = cube[3][1][2], cube[0][2][0] = cube[3][0][2];
            cube[3][2][2] = cube[1][0][0], cube[3][1][2] = cube[1][1][0], cube[3][0][2] = cube[1][2][0];
            cube[1][0][0] = cube[2][0][0], cube[1][1][0] = cube[2][1][0], cube[1][2][0] = cube[2][2][0];
            cube[2][0][0] = tempLine[0], cube[2][1][0] = tempLine[1], cube[2][2][0] = tempLine[2];
        }
        else
        {
            tempLine[0] = cube[0][0][0], tempLine[1] = cube[0][1][0], tempLine[2] = cube[0][2][0];
            cube[0][0][0] = cube[2][0][0], cube[0][1][0] = cube[2][1][0], cube[0][2][0] = cube[2][2][0];
            cube[2][0][0] = cube[1][0][0], cube[2][1][0] = cube[1][1][0], cube[2][2][0] = cube[1][2][0];
            cube[1][0][0] = cube[3][2][2], cube[1][1][0] = cube[3][1][2], cube[1][2][0] = cube[3][0][2];
            cube[3][2][2] = tempLine[0], cube[3][1][2] = tempLine[1], cube[3][0][2] = tempLine[2];
        }
    }
    else
    {
        target = 5;
        if (cmd[1] == '+')
        {
            tempLine[0] = cube[0][2][2], tempLine[1] = cube[0][1][2], tempLine[2] = cube[0][0][2];
            cube[0][2][2] = cube[2][2][2], cube[0][1][2] = cube[2][1][2], cube[0][0][2] = cube[2][0][2];
            cube[2][2][2] = cube[1][2][2], cube[2][1][2] = cube[1][1][2], cube[2][0][2] = cube[1][0][2];
            cube[1][2][2] = cube[3][0][0], cube[1][1][2] = cube[3][1][0], cube[1][0][2] = cube[3][2][0];
            cube[3][0][0] = tempLine[0], cube[3][1][0] = tempLine[1], cube[3][2][0] = tempLine[2];
        }
        else
        {
            tempLine[0] = cube[0][2][2], tempLine[1] = cube[0][1][2], tempLine[2] = cube[0][0][2];
            cube[0][2][2] = cube[3][0][0], cube[0][1][2] = cube[3][1][0], cube[0][0][2] = cube[3][2][0];
            cube[3][0][0] = cube[1][2][2], cube[3][1][0] = cube[1][1][2], cube[3][2][0] = cube[1][0][2];
            cube[1][2][2] = cube[2][2][2], cube[1][1][2] = cube[2][1][2], cube[1][0][2] = cube[2][0][2];
            cube[2][2][2] = tempLine[0], cube[2][1][2] = tempLine[1], cube[2][0][2] = tempLine[2];
        }
    }
    if (cmd[1] == '+')
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
                temp[j][3 - 1 - i] = cube[target][i][j];
    else
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
                temp[3 - 1 - j][i] = cube[target][i][j];
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            cube[target][i][j] = temp[i][j];
}
int main()
{
    vector<string> v;
    string cmd;
    ios::sync_with_stdio(0), cin.tie(0);
    int tc, n;
    cin >> tc;
    while (tc--)
    {
        init();
        v.clear();
        cin >> n;
        while (n--)
        {
            cin >> cmd;
            v.push_back(cmd);
        }
        for (int i = 0; i < v.size(); ++i)
        {
            if (i + 3 < v.size() && (v[i] == v[i + 1]) && (v[i + 1] == v[i + 2]) && (v[i + 2] == v[i + 3]))
            {
                i = i + 3;
                continue;
            }
            else if (i + 1 < v.size() && v[i][0] == v[i + 1][0] && v[i][1] != v[i + 1][1])
            {
                i = i + 1;
                continue;
            }
            roll(v[i]);
        }
        for (int i = 0; i < 3; ++i)
        {
            for (int j = 0; j < 3; ++j)
                cout << cube[0][i][j];
            cout << "\n";
        }
    }
    return 0;
}
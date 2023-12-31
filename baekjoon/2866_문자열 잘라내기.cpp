#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;
vector<string> table;
int R, C;
void input()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> R >> C;
    table = vector<string>(R);
    for (int row = 0; row < R; ++row)
    {
        string line;
        cin >> line;
        table[row] = line;
    }

    vector<string> newTable;
    newTable.reserve(C);
    for (int col = 0; col < C; ++col)
    {
        string line;
        line.reserve(R);
        for (int row = R - 1; row >= 0; --row) // 뒤에서부터 받기
        {
            line.push_back(table[row][col]);
        }
        newTable.push_back(line);
    }
    table = newTable;
}
void solve()
{
    int count = 0;
    while (R--)
    {
        set<string> s;
        for (string &line : table)
        {
            line.pop_back();
            if (s.find(line) == s.end())
            {
                s.insert(line);
            }
            else
            {
                cout << count;
                return;
            }
        }
        ++count;
    }
    cout << count;
    return;
}
int main()
{
    input();
    solve();
    return 0;
}
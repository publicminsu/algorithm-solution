#include <iostream>
using namespace std;
string alpha;
string patterns[] = {"c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="};
int answer;
bool isFind(int i, const string &pattern)
{
    for (int j = 0; j < pattern.size(); ++j)
    {
        if (alpha[i + j] != pattern[j]) // 불일치하면 false
        {
            return false;
        }
    }
    return true;
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> alpha;
    for (int i = 0; i < alpha.size(); ++i)
    {
        for (const string &pattern : patterns)
        {
            if (pattern.size() + i > alpha.size()) // 범위를 넘어가는가?
            {
                continue;
            }
            if (isFind(i, pattern)) // 변경할 수 있다면 i를 길이만큼 증가시켜줌
            {
                i += pattern.size() - 1;
                break;
            }
        }
        ++answer;
    }
    cout << answer;
    return 0;
}
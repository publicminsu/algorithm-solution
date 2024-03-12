#include <iostream>
using namespace std;
int T, answer;
string s, p;
bool isFind(int idx)
{
    for (int j = 0; j < p.size(); ++j)
    {
        if (s[idx + j] != p[j])
        {
            return false;
        }
    }
    return true;
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> T;
    while (T--)
    {
        answer = 0;
        cin >> s >> p;
        for (int i = 0; i < s.size();)
        {
            ++answer;
            if (isFind(i))
            {
                i += p.size();
            }
            else
            {
                ++i;
            }
        }
        cout << answer << "\n";
    }
    return 0;
}
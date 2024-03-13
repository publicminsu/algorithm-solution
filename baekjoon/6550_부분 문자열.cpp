#include <iostream>
using namespace std;
string s, t;
bool isSubstring()
{
    int i = 0, j = 0;
    while (true)
    {
        if (s[i] == t[j]) // 동일한가?
        {
            ++i, ++j;
        }
        else
        {
            ++j;
        }

        if (s.size() == i || t.size() == j) // 만약 i 또는 j 끝까지 갔다면
        {
            break;
        }
    }
    return s.size() == i; // 끝까지 확인했는가?
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    while (cin >> s >> t)
    {
        cout << (isSubstring() ? "Yes" : "No") << "\n";
    }
    return 0;
}
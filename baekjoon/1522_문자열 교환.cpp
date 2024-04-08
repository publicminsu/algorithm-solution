#include <iostream>
#include <string>
using namespace std;
int aCnt, answer = 987654321;
string str;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> str;

    for (int i = 0; i < str.size(); ++i)
    {
        if (str[i] == 'a')
        {
            ++aCnt;
        }
    }

    for (int i = 0; i < str.size(); ++i)
    {
        int cnt = aCnt, bCnt = 0, j = i;
        while (true)
        {
            if (cnt == 0)
            {
                break;
            }
            if (str[j % str.size()] == 'b')
            {
                ++bCnt;
            }
            --cnt;
            ++j;
        }
        answer = min(answer, bCnt);
    }

    cout << answer;
    return 0;
}
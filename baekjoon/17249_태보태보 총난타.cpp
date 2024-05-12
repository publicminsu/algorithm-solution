#include <iostream>
using namespace std;
string str;
int idx, lCnt, rCnt;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> str;

    while (true)
    {
        if (str[idx] == '@')
        {
            ++lCnt;
        }
        else if (str[idx] == ')')
        {
            break;
        }
        ++idx;
    }

    while (str.size() != idx)
    {
        if (str[idx++] == '@')
        {
            ++rCnt;
        }
    }

    cout << lCnt << " " << rCnt;
    return 0;
}
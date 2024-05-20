#include <iostream>
using namespace std;
string S, answer;
int cnt0, cnt1;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> S;
    for (const char &c : S)
    {
        if (c == '0')
        {
            ++cnt0;
        }
    }

    cnt1 = S.size() - cnt0;
    cnt1 /= 2, cnt0 /= 2;
    for (const char &c : S)
    {
        if (c == '0')
        {
            if (cnt0-- > 0)
            {
                answer.push_back('0');
            }
        }
        else
        {
            if (cnt1-- > 0)
            {
                continue;
            }
            answer.push_back('1');
        }
    }

    cout << answer;
    return 0;
}
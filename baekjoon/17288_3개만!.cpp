#include <iostream>
using namespace std;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    string str;
    char prev = 0;
    int cnt = 0, answer = 0;

    cin >> str;

    for (const char &c : str)
    {
        if (prev + 1 == c)
        {
            ++cnt;
        }
        else
        {
            if (cnt == 3)
            {
                ++answer;
            }
            cnt = 1;
        }

        prev = c;
    }

    if (cnt == 3)
    {
        ++answer;
    }

    cout << answer;
    return 0;
}
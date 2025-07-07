#include <iostream>
using namespace std;
int N;
string str[50];
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> N;

    for (int i = 0; i < N; ++i)
    {
        cin >> str[i];
    }

    for (int i = 0; i < str[0].size(); ++i)
    {
        bool isSame = true;
        char c = str[0][i];

        for (int j = 1; j < N; ++j)
        {
            if (c != str[j][i])
            {
                isSame = false;
                break;
            }
        }

        if (!isSame)
        {
            c = '?';
        }

        cout << c;
    }
    return 0;
}
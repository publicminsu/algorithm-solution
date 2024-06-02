#include <iostream>
using namespace std;
int N, cnt[53];
string str;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N;

    for (int i = 0, j; i < N; ++i)
    {
        cin >> j;
        ++cnt[j];
    }

    cin.ignore();
    getline(cin, str);

    for (char c : str)
    {
        int index = 0;

        if ('A' <= c && c <= 'Z')
        {
            index = c - 'A' + 1;
        }
        else if ('a' <= c && c <= 'z')
        {
            index = c - 'a' + 27;
        }

        if (--cnt[index] < 0)
        {
            cout << "n";
            return 0;
        }
    }

    cout << "y";
    return 0;
}
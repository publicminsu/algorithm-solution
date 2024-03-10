#include <iostream>
#include <unordered_map>
using namespace std;
unordered_map<string, string> um;
int N, M, T;
char a[7];
string song;
string getThree()
{
    string str;
    for (int i = 0; i < 3; ++i)
    {
        str += a[i];
    }
    return str;
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> M;

    while (N--)
    {
        cin >> T >> song;
        for (char &c : a)
        {
            cin >> c;
        }
        string str = getThree();

        if (um.find(str) == um.end())
        {
            um[str] = song;
        }
        else
        {
            um[str] = "?";
        }
    }

    while (M--)
    {
        for (int i = 0; i < 3; ++i)
        {
            cin >> a[i];
        }

        string str = getThree();

        bool isFind = um.find(str) != um.end();
        cout << (isFind ? um[str] : "!") << "\n";
    }
    return 0;
}
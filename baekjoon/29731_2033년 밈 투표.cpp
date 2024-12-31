#include <iostream>
using namespace std;
int N;
string promises[] = {
    "Never gonna give you up",
    "Never gonna let you down",
    "Never gonna run around and desert you",
    "Never gonna make you cry",
    "Never gonna say goodbye",
    "Never gonna tell a lie and hurt you",
    "Never gonna stop"};
string str;
bool isYes;

bool contains()
{
    for (const string &promise : promises)
    {
        if (promise == str)
        {
            return true;
        }
    }

    return false;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> N;
    cin.ignore();

    while (N--)
    {
        getline(cin, str);

        isYes |= !contains();
    }

    cout << (isYes ? "Yes" : "No");

    return 0;
}
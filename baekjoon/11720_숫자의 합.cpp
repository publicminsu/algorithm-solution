#include <iostream>
using namespace std;
string str;
int answer;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> str >> str;

    for (char &c : str)
    {
        answer += c - '0';
    }

    cout << answer;
    return 0;
}
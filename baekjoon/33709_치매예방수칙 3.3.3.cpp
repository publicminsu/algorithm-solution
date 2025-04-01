#include <iostream>
using namespace std;
string str;
int N, num, answer;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> N >> str;

    for (char &c : str)
    {
        if (c >= '0' && c <= '9')
        {
            num = num * 10 + (c - '0');
        }
        else
        {
            answer += num;
            num = 0;
        }
    }

    answer += num;

    cout << answer;
    return 0;
}
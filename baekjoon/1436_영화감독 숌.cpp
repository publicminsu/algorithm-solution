#include <iostream>
using namespace std;
int N, num = 665;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> N;

    while (true)
    {
        if (to_string(++num).find("666") == string::npos)
        {
            continue;
        }

        if (--N == 0)
        {
            cout << num;
            break;
        }
    }

    return 0;
}
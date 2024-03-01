#include <iostream>
using namespace std;
int T;
string exp;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> T;
    while (T--)
    {
        cin >> exp;
        int left = 0, right = 0;
        for (; left < exp.size(); ++left)
        {
            if (exp[left] != '!')
            {
                break;
            }
        }
        right = exp.size() - left - 1;

        int n = exp[left] - '0';
        if (right)
        {
            n = 1;
        }

        cout << (n + left) % 2 << "\n";
    }
    return 0;
}
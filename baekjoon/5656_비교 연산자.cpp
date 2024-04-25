#include <iostream>
using namespace std;
int l, r, idx;
bool value;
string oper;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    while (true)
    {
        cin >> l >> oper >> r;

        if (oper == "E")
        {
            break;
        }

        if (oper == ">")
        {
            value = l > r;
        }
        else if (oper == ">=")
        {
            value = l >= r;
        }
        else if (oper == "<")
        {
            value = l < r;
        }
        else if (oper == "<=")
        {
            value = l <= r;
        }
        else if (oper == "==")
        {
            value = l == r;
        }
        else if (oper == "!=")
        {
            value = l != r;
        }

        cout << "Case " << ++idx << ": " << (value ? "true" : "false") << "\n";
    }

    return 0;
}
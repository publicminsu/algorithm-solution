#include <iostream>
using namespace std;

int N;
long long d, dk, dks, dksh;
string S;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> N >> S;

    for (const char &c : S)
    {
        switch (c)
        {
        case 'D':
            ++d;
            break;
        case 'K':
            dk += d;
            break;
        case 'S':
            dks += dk;
            break;
        case 'H':
            dksh += dks;
            break;
        default:
            break;
        }
    }

    cout << dksh;
    return 0;
}
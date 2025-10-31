#include <iostream>
using namespace std;
using ll = long long;

string P;
ll num, den = 1;
int cnts[6];

ll gcd(ll a, ll b)
{
    if (b == 0)
    {
        return a;
    }

    return gcd(b, a % b);
}

void parse()
{
    int pos = P.find('.');
    string intPart = P.substr(0, pos);
    string fracPart = P.substr(pos + 1);
    num = stoll(intPart + fracPart);
    for (int i = 0; i < fracPart.size(); i++)
    {
        den *= 10;
    }
}

void reduceFraction()
{
    ll gcdNum = gcd(num, den);
    num /= gcdNum;
    den /= gcdNum;
}

void solve()
{
    int quot = num / den;
    int mod = num % den;

    cnts[quot] = den - mod;
    cnts[quot + 1] = mod;

    for (int i = 1; i <= 5; ++i)
    {
        cout << cnts[i] << " ";
    }
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> P;

    parse();
    reduceFraction();
    solve();

    return 0;
}
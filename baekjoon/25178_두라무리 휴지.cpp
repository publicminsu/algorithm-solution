#include <iostream>
#include <algorithm>
using namespace std;
int N;
string str1, str2;
char vowels[] = {'a', 'e', 'i', 'o', 'u'};

void input()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> N >> str1 >> str2;
}

void erase(string &str, char c)
{
    str.erase(remove(str.begin(), str.end(), c), str.end());
}

string erase(string str)
{
    for (char c : vowels)
    {
        erase(str, c);
    }

    return str;
}

bool solve()
{
    if (str1.front() != str2.front() || str1.back() != str2.back())
    {
        return false;
    }

    if (erase(str1) != erase(str2))
    {
        return false;
    }

    sort(str1.begin(), str1.end());
    sort(str2.begin(), str2.end());

    return str1 == str2;
}

int main()
{
    input();
    cout << (solve() ? "YES" : "NO");
    return 0;
}
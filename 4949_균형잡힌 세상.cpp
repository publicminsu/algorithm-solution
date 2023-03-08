#include <iostream>
using namespace std;
char str[101];
bool stack[101];
int start;
bool isBal()
{
    start = -1;
    for (int i = 0; str[i] != '.'; ++i)
    {
        switch (str[i])
        {
        case '(':
            stack[++start] = false;
            break;
        case ')':
            if (start == -1 || stack[start])
                return false;
            --start;
            break;
        case '[':
            stack[++start] = true;
            break;
        case ']':
            if (start == -1 || !stack[start])
                return false;
            --start;
            break;
        default:
            break;
        }
    }
    if (start == -1)
        return true;
    else
        return false;
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    while (true)
    {
        cin.getline(str, 101, '\n');
        if (str[0] == '.')
            break;
        cout << (isBal() ? "yes" : "no") << "\n";
    }
}
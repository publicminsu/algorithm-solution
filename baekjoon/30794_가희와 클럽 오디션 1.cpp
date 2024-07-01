#include <iostream>
using namespace std;
int lv;
string str;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> lv >> str;

    if (str == "bad")
    {
        cout << 200 * lv;
    }
    else if (str == "cool")
    {
        cout << 400 * lv;
    }
    else if (str == "great")
    {
        cout << 600 * lv;
    }
    else if (str == "perfect")
    {
        cout << 1000 * lv;
    }
    else
    {
        cout << 0;
    }

    return 0;
}
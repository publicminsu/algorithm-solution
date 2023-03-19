#include <iostream>
#include <string>
using namespace std;
bool set[21];
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int M;
    string com;
    int val;
    cin >> M;
    while (M--)
    {
        cin >> com;
        if (com != "all" && com != "empty")
            cin >> val;
        if (com == "add")
            set[val] = true;
        else if (com == "remove")
            set[val] = false;
        else if (com == "check")
            cout << (int)set[val] << "\n";
        else if (com == "toggle")
            set[val] = !set[val];
        else if (com == "all")
            for (int i = 1; i <= 20; ++i)
                set[i] = true;
        else
            for (int i = 1; i <= 20; ++i)
                set[i] = false;
    }
    return 0;
}
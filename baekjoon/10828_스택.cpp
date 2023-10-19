#include <iostream>
#include <string>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, stack[10001], idx = -1;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        string com;
        cin >> com;
        if (com == "push")
        {
            int num;
            cin >> num;
            stack[++idx] = num;
        }
        else if (com == "pop")
        {
            if (idx == -1)
                cout << -1 << '\n';
            else
            {
                cout << stack[idx--] << '\n';
            }
        }
        else if (com == "size")
        {
            cout << idx + 1 << '\n';
        }
        else if (com == "empty")
        {
            if (idx == -1)
                cout << 1 << '\n';
            else
                cout << 0 << '\n';
        }
        else
        {
            if (idx == -1)
                cout << -1 << '\n';
            else
            {
                cout << stack[idx] << '\n';
            }
        }
    }
    return 0;
}
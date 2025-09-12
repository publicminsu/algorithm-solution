#include <iostream>
using namespace std;

int N, stackSize, cmd;
int stack[1000001];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> N;

    while (N--)
    {
        cin >> cmd;

        switch (cmd)
        {
        case 1:
            int X;
            cin >> X;
            stack[stackSize++] = X;
            break;
        case 2:
            if (stackSize > 0)
            {
                cout << stack[--stackSize] << "\n";
            }
            else
            {
                cout << -1 << "\n";
            }
            break;
        case 3:
            cout << stackSize << "\n";
            break;
        case 4:
            cout << (stackSize == 0) << "\n";
            break;
        case 5:
            if (stackSize > 0)
            {
                cout << stack[stackSize - 1] << "\n";
            }
            else
            {
                cout << -1 << "\n";
            }
            break;
        }
    }
    return 0;
}
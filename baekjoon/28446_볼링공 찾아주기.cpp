#include <iostream>
#include <unordered_map>
using namespace std;

int M, cmd, w, x;
unordered_map<int, int> lockers;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> M;

    while (M--)
    {
        cin >> cmd;

        switch (cmd)
        {
        case 1:
            cin >> x >> w;
            lockers[w] = x;
            break;
        case 2:
            cin >> w;
            cout << lockers[w] << "\n";
            break;
        }
    }
    return 0;
}
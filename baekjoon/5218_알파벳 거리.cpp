#include <iostream>
using namespace std;
int TC;
string x, y;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> TC;
    while (TC--)
    {
        cin >> x >> y;

        cout << "Distances: ";

        for (int i = 0; i < x.size(); ++i)
        {
            cout << (y[i] - x[i] + 26) % 26 << " ";
        }

        cout << "\n";
    }
    return 0;
}
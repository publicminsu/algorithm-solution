#include <iostream>
using namespace std;
int tc, m, n, k, idx;
string words[51];
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> tc;

    for (int t = 1; t <= tc; ++t)
    {
        cout << "Scenario #" << t << ":\n";

        cin >> m;

        for (int i = 0; i < m; ++i)
        {
            cin >> words[i];
        }

        cin >> n;

        while (n--)
        {
            cin >> k;

            while (k--)
            {
                cin >> idx;

                cout << words[idx];
            }
            cout << "\n";
        }

        cout << "\n";
    }
    return 0;
}
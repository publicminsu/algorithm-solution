#include <iostream>

using namespace std;

int N, M;
string bun;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> M;

    while (N--)
    {
        cin >> bun;

        for (int i = M - 1; i >= 0; --i)
        {
            cout << bun[i];
        }
        cout << "\n";
    }
    return 0;
}
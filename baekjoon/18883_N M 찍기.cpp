#include <iostream>

using namespace std;

int N, M;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> M;

    for (int i = 1; i <= N * M; ++i)
    {
        cout << i;

        if (i % M)
        {
            cout << " ";
        }
        else
        {
            cout << "\n";
        }
    }
    return 0;
}

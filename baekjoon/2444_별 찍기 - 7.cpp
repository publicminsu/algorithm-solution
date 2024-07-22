#include <iostream>
using namespace std;
int N;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> N;

    int maxEmptyLength = N - 1;

    for (int i = 0; i < 2 * N - 1; ++i)
    {
        int currentEmptyLength = abs(maxEmptyLength - i);

        for (int j = 0; j < currentEmptyLength; ++j)
        {
            cout << " ";
        }

        for (int j = 0; j < (maxEmptyLength - currentEmptyLength) * 2 + 1; ++j)
        {
            cout << "*";
        }

        cout << "\n";
    }
    return 0;
}
#include <iostream>

using namespace std;

int N;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> N;
    cin.ignore();

    for (int i = 1; i <= N; ++i)
    {
        string line;
        getline(cin, line);

        cout << i << ". " << line << "\n";
    }
    return 0;
}
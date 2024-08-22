#include <iostream>
using namespace std;
int N;
string K;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N;
    while (N--)
    {
        cin >> K;

        cout << ((K.back() % 2) ? "odd" : "even") << "\n";
    }
    return 0;
}
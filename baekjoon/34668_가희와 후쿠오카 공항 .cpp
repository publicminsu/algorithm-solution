#include <iostream>
#include <iomanip>
using namespace std;

int Q, M;
int startingMin = 366;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> Q;

    cout << setfill('0');

    while (Q--)
    {
        cin >> M;
        int quot = M / 50;
        int depatureMin = startingMin + quot * 12;

        cout << setw(2) << (depatureMin / 60) << ":" << setw(2) << (depatureMin % 60) << "\n";
    }
    return 0;
}
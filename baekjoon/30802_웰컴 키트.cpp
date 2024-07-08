#include <iostream>
using namespace std;
int N, T, P, count;
int people[6];
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N;
    for (int &i : people)
    {
        cin >> i;
    }

    cin >> T >> P;

    for (const int &i : people)
    {
        if (i)
        {
            count += (i - 1) / T + 1;
        }
    }

    cout << count << "\n";
    cout << (N / P) << " " << (N % P);
    return 0;
}
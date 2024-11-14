#include <iostream>
using namespace std;
int sum, diff;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> sum >> diff;

    int A2 = (sum + diff);

    if (diff > sum || A2 % 2 == 1)
    {
        cout << -1;
        return 0;
    }

    int A = A2 >> 1;
    int B = sum - A;

    if (A < B)
    {
        swap(A, B);
    }

    cout << A << " " << B;
    return 0;
}
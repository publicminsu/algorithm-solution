#include <iostream>
using namespace std;

int N;

void Move(int count, int start, int end, int temp)
{
    if (count == 1)
    {
        cout << start << " " << end << "\n";
        return;
    }

    Move(count - 1, start, temp, end);

    cout << start << " " << end << "\n";

    Move(count - 1, temp, end, start);
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> N;

    cout << (1 << N) - 1 << "\n";

    Move(N, 1, 3, 2);
}
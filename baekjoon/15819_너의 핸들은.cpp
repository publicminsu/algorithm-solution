#include <iostream>
#include <algorithm>
using namespace std;
int N, I;
string arr[100];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> N >> I;

    for (int i = 0; i < N; ++i)
    {
        cin >> arr[i];
    }

    sort(arr, arr + N);

    cout << arr[I - 1];
    return 0;
}
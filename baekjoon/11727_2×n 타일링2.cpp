#include <iostream>
#include <vector>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int arr[1001], n;
    cin >> n;
    arr[1] = 1, arr[2] = 3;
    for (int i = 3; i <= n; ++i)
    {
        arr[i] = ((arr[i - 2] << 1) + arr[i - 1]) % 10007;
    }
    cout << arr[n];
}
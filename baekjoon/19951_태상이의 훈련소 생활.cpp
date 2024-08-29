#include <iostream>
#include <vector>
using namespace std;
vector<int> arr, prefix;
int N, M, a, b, k;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> M;

    arr = prefix = vector<int>(N + 2);

    for (int i = 1; i <= N; ++i)
    {
        cin >> arr[i];
    }

    while (M--)
    {
        cin >> a >> b >> k;

        prefix[a] += k;
        prefix[b + 1] += -k;
    }

    for (int i = 2; i <= N; ++i)
    {
        prefix[i] += prefix[i - 1];
    }

    for (int i = 1; i <= N; ++i)
    {
        cout << arr[i] + prefix[i] << " ";
    }

    return 0;
}
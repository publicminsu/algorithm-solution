#include <iostream>
#include <algorithm>
using namespace std;
int W[10], K[10];
int main()
{
    for (int &i : W)
    {
        cin >> i;
    }

    sort(W, W + 10);

    for (int &i : K)
    {
        cin >> i;
    }

    sort(K, K + 10);

    cout << W[9] + W[8] + W[7] << " " << K[9] + K[8] + K[7];
    return 0;
}
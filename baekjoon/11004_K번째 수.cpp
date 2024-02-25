#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, K;
vector<int> A;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> K;
    A = vector<int>(N);
    for (int &i : A)
    {
        cin >> i;
    }
    sort(A.begin(), A.end());
    cout << A[K - 1];
    return 0;
}
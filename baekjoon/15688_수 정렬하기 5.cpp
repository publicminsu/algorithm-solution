#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N;
vector<int> A;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N;
    A = vector<int>(N);
    for (int &a : A)
    {
        cin >> a;
    }
    sort(A.begin(), A.end());
    for (const int &a : A)
    {
        cout << a << "\n";
    }
    return 0;
}
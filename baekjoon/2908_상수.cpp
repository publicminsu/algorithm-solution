#include <iostream>
#include <algorithm>
using namespace std;

string A, B;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> A >> B;
    reverse(A.begin(), A.end());
    reverse(B.begin(), B.end());
    cout << max(A, B);
    return 0;
}
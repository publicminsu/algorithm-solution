#include <iostream>
using namespace std;
long long N;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N;
    cout << (N % 2 ? "SK" : "CY");
    return 0;
}
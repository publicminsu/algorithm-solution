#include <iostream>
using namespace std;

string A, B, C, D;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> A >> B >> C >> D;
    cout << stoll(A + B) + stoll(C + D);
    return 0;
}
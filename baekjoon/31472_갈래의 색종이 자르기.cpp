#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int W;
    cin >> W;
    W <<= 1;
    int len = sqrt(W);
    cout << (len << 2);
    return 0;
}
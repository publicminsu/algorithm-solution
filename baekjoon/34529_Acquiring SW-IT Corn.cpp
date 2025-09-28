#include <iostream>
using namespace std;

int X, Y, Z, U, V, W;

int CalcCost(int amount, int unit, int cost)
{
    return amount / unit * cost;
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> X >> Y >> Z >> U >> V >> W;
    cout << CalcCost(U, 100, X) + CalcCost(V, 50, Y) + CalcCost(W, 20, Z);
    return 0;
}
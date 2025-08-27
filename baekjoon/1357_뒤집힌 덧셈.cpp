#include <iostream>
#include <algorithm>
using namespace std;

string X, Y;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> X >> Y;

    reverse(X.begin(), X.end());
    reverse(Y.begin(), Y.end());

    int sumNum = stoi(X) + stoi(Y);
    string sumStr = to_string(sumNum);

    reverse(sumStr.begin(), sumStr.end());

    cout << stoi(sumStr);
    return 0;
}
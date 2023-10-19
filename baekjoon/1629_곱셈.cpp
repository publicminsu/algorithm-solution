#include <iostream>
using namespace std;
int part(int A, int B, int C)
{
    if (B == 1)
        return A;
    long partVal = part(A, B / 2, C);
    long multiVal = (partVal * partVal) % C;
    if (B % 2)
        multiVal = (multiVal * A) % C;
    return multiVal;
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int A, B, C;
    cin >> A >> B >> C;
    cout << part(A, B, C) % C;
    return 0;
}
#include <iostream>
#include <string>
using namespace std;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    string A, B, ret = "";
    cin >> A >> B;
    int i = A.length() - 1, j = B.length() - 1, sum = 0;
    while (i >= 0 || j >= 0)
    {
        if (i >= 0)
            sum += A[i--] - '0';
        if (j >= 0)
            sum += B[j--] - '0';
        ret += (sum % 10) + '0';
        sum /= 10;
    }
    if (sum)
        ret += sum + '0';
    for (int i = ret.length() - 1; i >= 0; --i)
        cout << ret[i];
    return 0;
}
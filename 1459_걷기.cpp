#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    unsigned long long X, Y, W, S, ret;
    cin >> X >> Y >> W >> S;
    if ((W << 1) < S)
    {
        ret = (X + Y) * W;
    }
    else
    {
        if (X > Y)
        {
            swap(X, Y);
        }
        ret = X * S + (Y - X) * W;
        unsigned long long i = ((X + Y) % 2 == 1 ? 1 : 0);
        ret = min((Y - i) * S + W * i, ret);
        // ret=X*S+
    }
    cout << ret;
    return 0;
}
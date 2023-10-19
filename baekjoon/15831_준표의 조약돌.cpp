#include <iostream>
#include <string>
using namespace std;
string stone;
int N, B, W, l = 0, r = 0, b, w, ret = 0, len = 0;
void goRight()
{
    ++len;
    if (stone[r++] == 'W')
        ++w;
    else
        ++b;
}
void goLeft()
{
    --len;
    if (stone[l++] == 'W')
        --w;
    else
        --b;
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> B >> W;
    cin >> stone;
    while (r != stone.length() && l != stone.length())
    {
        if (B >= b)
        {
            if (r != stone.length())
                goRight();
        }
        else
        {
            goLeft();
        }
        if (W <= w && B >= b)
        {
            ret = len > ret ? len : ret;
        }
    }
    cout << ret;
    return 0;
}
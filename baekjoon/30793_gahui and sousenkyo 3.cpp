#include <iostream>
using namespace std;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    float p, r, ret;
    cin >> p >> r;
    ret = p / r;

    if (ret < 0.2f)
    {
        cout << "weak";
    }
    else if (ret < 0.4f)
    {
        cout << "normal";
    }
    else if (ret < 0.6f)
    {
        cout << "strong";
    }
    else
    {
        cout << "very strong";
    }
    return 0;
}
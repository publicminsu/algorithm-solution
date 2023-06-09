#include <iostream>
using namespace std;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int S1, S2, ans, res;
    cin >> S1 >> S2;
    while (S1--)
    {
        cin >> ans >> res;
        if (res != ans)
        {
            cout << "Wrong Answer";
            return 0;
        }
    }
    while (S2--)
    {
        cin >> ans >> res;
        if (res != ans)
        {
            cout << "Why Wrong!!!";
            return 0;
        }
    }
    cout << "Accepted";
    return 0;
}
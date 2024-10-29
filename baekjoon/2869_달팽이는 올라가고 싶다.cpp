#include <iostream>
using namespace std;
int A, B, V;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> A >> B >> V;
    int dayDist = (A - B);
    int days = (V - A);
    int day = days / dayDist;
    if (days % dayDist)
    {
        ++day;
    }
    cout << day + 1;
    return 0;
}
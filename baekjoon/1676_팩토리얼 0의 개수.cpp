#include <iostream>
using namespace std;
int N, cnt5, cnt2;
int main()
{
    cin >> N;
    while (N)
    {
        int curN = N;
        while (curN % 5 == 0)
        {
            ++cnt5;
            curN /= 5;
        }
        while (curN % 2 == 0)
        {
            ++cnt2;
            curN /= 2;
        }
        --N;
    }
    cout << min(cnt5, cnt2);
    return 0;
}
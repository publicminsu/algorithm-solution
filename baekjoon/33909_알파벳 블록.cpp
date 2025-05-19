#include <iostream>
using namespace std;
int S, C, O, N;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> S >> C >> O >> N;

    C += O * 2;
    S += N;

    int cCount = C / 6;
    int sCount = S / 3;

    cout << min(sCount, cCount);
    return 0;
}
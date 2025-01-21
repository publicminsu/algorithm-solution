#include <iostream>
#include <iomanip>
using namespace std;
int T, H, W, N;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> T;
    while (T--)
    {
        cin >> H >> W >> N;

        int Y = (N % H);
        if (Y == 0)
        {
            Y = H;
        }
        int X = ((N - 1) / H + 1);

        cout << Y << setw(2) << setfill('0') << X << "\n";
    }
    return 0;
}
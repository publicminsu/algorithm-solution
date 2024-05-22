#include <iostream>
using namespace std;
int N, A, B, answer;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> A >> B;
    while (A != B)
    {
        A = (A + 1) >> 1;
        B = (B + 1) >> 1;
        ++answer;
    }
    cout << answer;
    return 0;
}
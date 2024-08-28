#include <iostream>
using namespace std;
int T, A, B;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> T;
    while (T--)
    {
        cin >> A >> B;

        int answer = 0;

        while (A * 4 < B)
        {
            ++A;
            ++answer;
        }

        if (3 * A > B)
        {
            answer += 3 * A - B;
        }

        cout << answer << "\n";
    }
    return 0;
}
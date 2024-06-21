#include <iostream>
using namespace std;
int h, answer;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    while (true)
    {
        cin >> h;

        if (h == 0)
        {
            break;
        }

        answer = h;

        while (h != 1)
        {
            if (h % 2)
            {
                h = 3 * h + 1;

                answer = max(h, answer);
            }
            else
            {
                h /= 2;
            }
        }

        cout << answer << "\n";
    }
    return 0;
}
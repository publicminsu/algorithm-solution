#include <iostream>
using namespace std;
int N, answer, i = 1;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N;

    while (true)
    {
        ++answer;
        if (N <= i)
        {
            break;
        }
        i += 6 * answer;
    }

    cout << answer;
    return 0;
}
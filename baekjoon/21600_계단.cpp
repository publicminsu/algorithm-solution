#include <iostream>
using namespace std;
int N, A, height, answer;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> N;

    while (N--)
    {
        cin >> A;

        height = min(height + 1, A);
        answer = max(answer, height);
    }

    cout << answer;
    return 0;
}
#include <iostream>
using namespace std;

int N, a, b;
bool isEntered[200001];
int cnt;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> N;

    while (N--)
    {
        cin >> a >> b;
        if (isEntered[a] == b)
        {
            ++cnt;
        }
        else
        {
            isEntered[a] = b;
        }
    }

    for (int i = 1; i < 200001; ++i)
    {
        cnt += isEntered[i];
    }

    cout << cnt;
    return 0;
}
#include <iostream>
#include <vector>
using namespace std;
int N, D, maxH;
long long answer;
vector<int> h;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> N >> D;

    h = vector<int>(N);

    for (int &i : h)
    {
        cin >> i;
        maxH = max(maxH, i);
    }

    int hurdle = maxH - D;
    hurdle = max(0, hurdle);

    for (int &i : h)
    {
        if (hurdle < i)
        {
            answer += i - hurdle;
        }
    }

    cout << answer;
    return 0;
}
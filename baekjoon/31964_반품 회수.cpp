#include <iostream>
#include <vector>
using namespace std;
using pii = pair<int, int>;
int N, answer, curX;
vector<pii> XT;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> N;
    XT = vector<pii>(N);
    for (pii &p : XT)
    {
        cin >> p.first;
    }
    for (pii &p : XT)
    {
        cin >> p.second;
    }

    for (int i = N - 1; i >= 0; --i)
    {
        const pii &p = XT[i];
        int diff = max(abs(p.first - curX), p.second - answer);
        answer += diff;

        curX = p.first;
    }

    cout << answer + curX;
    return 0;
}
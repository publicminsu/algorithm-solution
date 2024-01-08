#include <iostream>
#include <vector>
#include <cmath>
#include <limits>
using namespace std;
using pii = pair<int, int>;
vector<pii> countries;
int n, fullBitMask;
double answer = numeric_limits<double>::max();
double getDistance(pii a, pii b)
{
    double sub1 = a.first - b.first;
    double sub2 = a.second - b.second;
    return sqrt(sub1 * sub1 + sub2 * sub2);
}
void dfs(int cur, double sum, int bitMask)
{
    if (sum >= answer)
    {
        return;
    }
    if (fullBitMask == bitMask) // 모두 방문한 경우
    {
        double distance = getDistance(countries[cur], countries[0]);
        answer = min(answer, sum + distance);
        return;
    }
    for (int i = 1; i < n; ++i)
    {
        if ((bitMask & (1 << i))) // 이미 방문했다면
        {
            continue;
        }
        double distance = getDistance(countries[cur], countries[i]);
        dfs(i, sum + distance, (bitMask | (1 << i)));
    }
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    cout << fixed;
    cout.precision(8);

    countries = vector<pii>(n);
    fullBitMask = (1 << n) - 1;

    for (pii &country : countries)
    {
        cin >> country.first >> country.second;
    }

    dfs(0, 0, 1 << 0);
    cout << (answer == numeric_limits<double>::max() ? -1 : answer); // 불가능할 경우 -1
}
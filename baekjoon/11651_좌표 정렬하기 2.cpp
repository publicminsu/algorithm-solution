#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using pii = pair<int, int>;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int N;
    cin >> N;
    vector<pii> pos(N);
    for (pii &p : pos) // x부터 받기
    {
        cin >> p.second >> p.first;
    }

    sort(pos.begin(), pos.end());

    for (pii p : pos) // x부터 출력
    {
        cout << p.second << " " << p.first << "\n";
    }
    return 0;
}
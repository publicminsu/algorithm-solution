#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct node
{
    string word;
    int num;
};
bool operator<(const node &a, int b)
{
    return a.num < b;
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int N, M;
    cin >> N >> M;
    vector<node> v(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> v[i].word >> v[i].num;
    }
    while (M--)
    {
        int num;
        cin >> num;

        auto it = lower_bound(v.begin(), v.end(), num); // 전투력이 이하인 곳 찾기
        cout << (*it).word << "\n";
    }
    return 0;
}
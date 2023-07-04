#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;
int N, sum = 0;
unordered_set<int> us;
vector<int> card;
void comb(int idx, int sum)
{
    if (sum)
        us.insert(sum);
    for (int i = idx; i < N; ++i)
    {
        comb(i + 1, sum + card[i]);
    }
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N;
    card = vector<int>(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> card[i];
        sum += card[i];
    }
    comb(0, 0);
    cout << sum - us.size();
    return 0;
}
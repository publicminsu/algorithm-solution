#include <iostream>
#include <stack>
#include <vector>
using namespace std;
using pii = pair<int, int>;
stack<pii> s;
vector<int> NGE;
int N;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N;
    NGE = vector<int>(N, -1);

    for (int i = 0, A; i < N; ++i)
    {
        cin >> A;
        while (!s.empty() && s.top().first < A)
        {
            NGE[s.top().second] = A;
            s.pop();
        }
        s.push({A, i});
    }

    for (const int &i : NGE)
    {
        cout << i << " ";
    }
    return 0;
}
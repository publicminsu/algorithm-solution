#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, A;
vector<int> answer;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N;

    answer.reserve(N);

    while (N--)
    {
        cin >> A;
        A = -A;

        auto idx = lower_bound(answer.begin(), answer.end(), A) - answer.begin();

        if (idx == answer.size())
        {
            answer.push_back(A);
        }
        else
        {
            answer[idx] = A;
        }
    }

    cout << answer.size();
    return 0;
}
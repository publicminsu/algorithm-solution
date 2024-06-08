#include <iostream>
#include <vector>
using namespace std;
int answer;
void recur(const vector<int> &v, int sum)
{
    if (v.size() == 2)
    {
        answer = max(answer, sum);
        return;
    }

    for (int i = 1; i < v.size() - 1; ++i)
    {
        int energy = v[i - 1] * v[i + 1];

        vector<int> copy = v;

        copy.erase(copy.begin() + i);

        recur(copy, sum + energy);
    }
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    int N;
    cin >> N;

    vector<int> v = vector<int>(N);
    for (int &i : v)
    {
        cin >> i;
    }

    recur(v, 0);

    cout << answer;
    return 0;
}
#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;

using pis = pair<int, string>;

int N, K;
map<string, int> containerToPriority;
vector<pis> containers;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> N;

    for (int i = 0; i < N; ++i)
    {
        string container;
        cin >> container;

        containerToPriority[container] = i;
    }

    cin >> K;

    for (int i = 0; i < K; ++i)
    {
        string container;
        cin >> container;
        containerToPriority[container] += N;
    }

    containers.reserve(N);

    for (auto p : containerToPriority)
    {
        containers.push_back({p.second, p.first});
    }

    sort(containers.begin(), containers.end(), greater<>());

    for (auto p : containers)
    {
        cout << p.second << "\n";
    }
    return 0;
}